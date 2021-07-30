#include <lldc/spooky.h>
#include <string.h>

#define ALLOW_UNALIGNED_READS 1

//
// left rotate a 64-bit value by k bytes
//
static inline 
uint64 spooky_rot64(uint64 x, int k)
{
    return (x << k) | (x >> (64 - k));
}

//
// This is used if the input is 96 bytes long or longer.
//
// The internal state is fully overwritten every 96 bytes.
// Every input bit appears to cause at least 128 bits of entropy
// before 96 other bytes are combined, when run forward or backward
//   For every input bit,
//   Two inputs differing in just that input bit
//   Where "differ" means xor or subtraction
//   And the base value is random
//   When run forward or backwards one Mix
// I tried 3 pairs of each; they all differed by at least 212 bits.
//
static inline 
void spooky_mix (
    const uint64 *data, 
    uint64 *s0, uint64 *s1, uint64 *s2, uint64 *s3,
    uint64 *s4, uint64 *s5, uint64 *s6, uint64 *s7,
    uint64 *s8, uint64 *s9, uint64 *s10,uint64 *s11)
{
    *s0 += data[0];    *s2 ^= *s10;    *s11 ^= *s0;    *s0 = spooky_rot64(*s0,11);    *s11 += *s1;
    *s1 += data[1];    *s3 ^= *s11;    *s0 ^= *s1;    *s1 = spooky_rot64(*s1,32);    *s0 += *s2;
    *s2 += data[2];    *s4 ^= *s0;    *s1 ^= *s2;    *s2 = spooky_rot64(*s2,43);    *s1 += *s3;
    *s3 += data[3];    *s5 ^= *s1;    *s2 ^= *s3;    *s3 = spooky_rot64(*s3,31);    *s2 += *s4;
    *s4 += data[4];    *s6 ^= *s2;    *s3 ^= *s4;    *s4 = spooky_rot64(*s4,17);    *s3 += *s5;
    *s5 += data[5];    *s7 ^= *s3;    *s4 ^= *s5;    *s5 = spooky_rot64(*s5,28);    *s4 += *s6;
    *s6 += data[6];    *s8 ^= *s4;    *s5 ^= *s6;    *s6 = spooky_rot64(*s6,39);    *s5 += *s7;
    *s7 += data[7];    *s9 ^= *s5;    *s6 ^= *s7;    *s7 = spooky_rot64(*s7,57);    *s6 += *s8;
    *s8 += data[8];    *s10 ^= *s6;    *s7 ^= *s8;    *s8 = spooky_rot64(*s8,55);    *s7 += *s9;
    *s9 += data[9];    *s11 ^= *s7;    *s8 ^= *s9;    *s9 = spooky_rot64(*s9,54);    *s8 += *s10;
    *s10 += data[10];    *s0 ^= *s8;    *s9 ^= *s10;    *s10 = spooky_rot64(*s10,22);    *s9 += *s11;
    *s11 += data[11];    *s1 ^= *s9;    *s10 ^= *s11;    *s11 = spooky_rot64(*s11,46);    *s10 += *s0;
}

//
// Mix all 12 inputs together so that h0, h1 are a hash of them all.
//
// For two inputs differing in just the input bits
// Where "differ" means xor or subtraction
// And the base value is random, or a counting value starting at that bit
// The final result will have each bit of h0, h1 flip
// For every input bit,
// with probability 50 +- .3%
// For every pair of input bits,
// with probability 50 +- 3%
//
// This does not rely on the last Mix() call having already mixed some.
// Two iterations was almost good enough for a 64-bit result, but a
// 128-bit result is reported, so End() does three iterations.
//
static inline 
void spooky_end_partial (
    uint64 *h0, uint64 *h1, uint64 *h2, uint64 *h3,
    uint64 *h4, uint64 *h5, uint64 *h6, uint64 *h7, 
    uint64 *h8, uint64 *h9, uint64 *h10,uint64 *h11)
{
    *h11+= *h1;    *h2 ^= *h11;   *h1 = spooky_rot64(*h1,44);
    *h0 += *h2;    *h3 ^= *h0;    *h2 = spooky_rot64(*h2,15);
    *h1 += *h3;    *h4 ^= *h1;    *h3 = spooky_rot64(*h3,34);
    *h2 += *h4;    *h5 ^= *h2;    *h4 = spooky_rot64(*h4,21);
    *h3 += *h5;    *h6 ^= *h3;    *h5 = spooky_rot64(*h5,38);
    *h4 += *h6;    *h7 ^= *h4;    *h6 = spooky_rot64(*h6,33);
    *h5 += *h7;    *h8 ^= *h5;    *h7 = spooky_rot64(*h7,10);
    *h6 += *h8;    *h9 ^= *h6;    *h8 = spooky_rot64(*h8,13);
    *h7 += *h9;    *h10^= *h7;    *h9 = spooky_rot64(*h9,38);
    *h8 += *h10;   *h11^= *h8;    *h10= spooky_rot64(*h10,53);
    *h9 += *h11;   *h0 ^= *h9;    *h11= spooky_rot64(*h11,42);
    *h10+= *h0;    *h1 ^= *h10;   *h0 = spooky_rot64(*h0,54);
}


static inline 
void spooky_end (
    const uint64 *data, 
    uint64 *h0, uint64 *h1, uint64 *h2, uint64 *h3,
    uint64 *h4, uint64 *h5, uint64 *h6, uint64 *h7, 
    uint64 *h8, uint64 *h9, uint64 *h10,uint64 *h11)
{
    *h0 += data[0];   *h1 += data[1];   *h2 += data[2];   *h3 += data[3];
    *h4 += data[4];   *h5 += data[5];   *h6 += data[6];   *h7 += data[7];
    *h8 += data[8];   *h9 += data[9];   *h10 += data[10]; *h11 += data[11];
    spooky_end_partial(h0,h1,h2,h3,h4,h5,h6,h7,h8,h9,h10,h11);
    spooky_end_partial(h0,h1,h2,h3,h4,h5,h6,h7,h8,h9,h10,h11);
    spooky_end_partial(h0,h1,h2,h3,h4,h5,h6,h7,h8,h9,h10,h11);
}

//
// The goal is for each bit of the input to expand into 128 bits of 
//   apparent entropy before it is fully overwritten.
// n trials both set and cleared at least m bits of h0 h1 h2 h3
//   n: 2   m: 29
//   n: 3   m: 46
//   n: 4   m: 57
//   n: 5   m: 107
//   n: 6   m: 146
//   n: 7   m: 152
// when run forwards or backwards
// for all 1-bit and 2-bit diffs
// with diffs defined by either xor or subtraction
// with a base of all zeros plus a counter, or plus another bit, or random
//
static inline 
void spooky_short_mix(uint64 *h0, uint64 *h1, uint64 *h2, uint64 *h3)
{
    *h2 = spooky_rot64(*h2,50);  *h2 += *h3;  *h0 ^= *h2;
    *h3 = spooky_rot64(*h3,52);  *h3 += *h0;  *h1 ^= *h3;
    *h0 = spooky_rot64(*h0,30);  *h0 += *h1;  *h2 ^= *h0;
    *h1 = spooky_rot64(*h1,41);  *h1 += *h2;  *h3 ^= *h1;
    *h2 = spooky_rot64(*h2,54);  *h2 += *h3;  *h0 ^= *h2;
    *h3 = spooky_rot64(*h3,48);  *h3 += *h0;  *h1 ^= *h3;
    *h0 = spooky_rot64(*h0,38);  *h0 += *h1;  *h2 ^= *h0;
    *h1 = spooky_rot64(*h1,37);  *h1 += *h2;  *h3 ^= *h1;
    *h2 = spooky_rot64(*h2,62);  *h2 += *h3;  *h0 ^= *h2;
    *h3 = spooky_rot64(*h3,34);  *h3 += *h0;  *h1 ^= *h3;
    *h0 = spooky_rot64(*h0,5);   *h0 += *h1;  *h2 ^= *h0;
    *h1 = spooky_rot64(*h1,36);  *h1 += *h2;  *h3 ^= *h1;
}

//
// Mix all 4 inputs together so that h0, h1 are a hash of them all.
//
// For two inputs differing in just the input bits
// Where "differ" means xor or subtraction
// And the base value is random, or a counting value starting at that bit
// The final result will have each bit of h0, h1 flip
// For every input bit,
// with probability 50 +- .3% (it is probably better than that)
// For every pair of input bits,
// with probability 50 +- .75% (the worst case is approximately that)
//
static inline 
void spooky_short_end (uint64 *h0, uint64 *h1, uint64 *h2, uint64 *h3)
{
    *h3 ^= *h2;  *h2 = spooky_rot64(*h2,15);  *h3 += *h2;
    *h0 ^= *h3;  *h3 = spooky_rot64(*h3,52);  *h0 += *h3;
    *h1 ^= *h0;  *h0 = spooky_rot64(*h0,26);  *h1 += *h0;
    *h2 ^= *h1;  *h1 = spooky_rot64(*h1,51);  *h2 += *h1;
    *h3 ^= *h2;  *h2 = spooky_rot64(*h2,28);  *h3 += *h2;
    *h0 ^= *h3;  *h3 = spooky_rot64(*h3,9);   *h0 += *h3;
    *h1 ^= *h0;  *h0 = spooky_rot64(*h0,47);  *h1 += *h0;
    *h2 ^= *h1;  *h1 = spooky_rot64(*h1,54);  *h2 += *h1;
    *h3 ^= *h2;  *h2 = spooky_rot64(*h2,32);  *h3 += *h2;
    *h0 ^= *h3;  *h3 = spooky_rot64(*h3,25);  *h0 += *h3;
    *h1 ^= *h0;  *h0 = spooky_rot64(*h0,63);  *h1 += *h0;
}

//
// Short is used for messages under 192 bytes in length
// Short has a low startup cost, the normal mode is good for long
// keys, the cost crossover is at about 192 bytes.  The two modes were
// held to the same quality bar.
// 
static void spooky_short(
    const void *message,  // message (array of bytes, not necessarily aligned)
    size_t length,        // length of message (in bytes)
    uint64 *hash1,        // in/out: in the seed, out the hash value
    uint64 *hash2)        // in/out: in the seed, out the hash value
{
uint64 buf[2*sc_numVars];
    union 
    { 
        const uint8 *p8; 
        uint32 *p32;
        uint64 *p64; 
        size_t i; 
    } u;

    u.p8 = (const uint8 *)message;
    
    if (!ALLOW_UNALIGNED_READS && (u.i & 0x7))
    {
        memcpy(buf, message, length);
        u.p64 = buf;
    }

    size_t remainder = length%32;
    uint64 a=*hash1;
    uint64 b=*hash2;
    uint64 c=sc_const;
    uint64 d=sc_const;

    if (length > 15)
    {
        const uint64 *end = u.p64 + (length/32)*4;
        
        // handle all complete sets of 32 bytes
        for (; u.p64 < end; u.p64 += 4)
        {
            c += u.p64[0];
            d += u.p64[1];
            spooky_short_mix(&a,&b,&c,&d);
            a += u.p64[2];
            b += u.p64[3];
        }
        
        //Handle the case of 16+ remaining bytes.
        if (remainder >= 16)
        {
            c += u.p64[0];
            d += u.p64[1];
            spooky_short_mix(&a,&b,&c,&d);
            u.p64 += 2;
            remainder -= 16;
        }
    }
    
    // Handle the last 0..15 bytes, and its length
    d += ((uint64)length) << 56;
    switch (remainder)
    {
    case 15:
    d += ((uint64)u.p8[14]) << 48;
    case 14:
        d += ((uint64)u.p8[13]) << 40;
    case 13:
        d += ((uint64)u.p8[12]) << 32;
    case 12:
        d += u.p32[2];
        c += u.p64[0];
        break;
    case 11:
        d += ((uint64)u.p8[10]) << 16;
    case 10:
        d += ((uint64)u.p8[9]) << 8;
    case 9:
        d += (uint64)u.p8[8];
    case 8:
        c += u.p64[0];
        break;
    case 7:
        c += ((uint64)u.p8[6]) << 48;
    case 6:
        c += ((uint64)u.p8[5]) << 40;
    case 5:
        c += ((uint64)u.p8[4]) << 32;
    case 4:
        c += u.p32[0];
        break;
    case 3:
        c += ((uint64)u.p8[2]) << 16;
    case 2:
        c += ((uint64)u.p8[1]) << 8;
    case 1:
        c += (uint64)u.p8[0];
        break;
    case 0:
        c += sc_const;
        d += sc_const;
    }
    spooky_short_end(&a,&b,&c,&d);
    *hash1 = a;
    *hash2 = b;
}

//
// SpookyHash: hash a single message in one call, produce 128-bit output
//
void spooky_hash128 (
    const void *message,  // message to hash
    size_t length,        // length of message in bytes
    uint64 *hash1,        // in/out: in seed 1, out hash value 1
    uint64 *hash2         // in/out: in seed 2, out hash value 2
)
{
    if (length < sc_bufSize)
    {
        spooky_short(message, length, hash1, hash2);
        return;
    }

    uint64 h0,h1,h2,h3,h4,h5,h6,h7,h8,h9,h10,h11;
    uint64 buf[sc_numVars];
    uint64 *end;
    union 
    { 
        const uint8 *p8; 
        uint64 *p64; 
        size_t i; 
    } u;
    size_t remainder;
    
    h0=h3=h6=h9  = *hash1;
    h1=h4=h7=h10 = *hash2;
    h2=h5=h8=h11 = sc_const;
    
    u.p8 = (const uint8 *)message;
    end = u.p64 + (length/sc_blockSize)*sc_numVars;

    // handle all whole sc_blockSize blocks of bytes
    if (ALLOW_UNALIGNED_READS || ((u.i & 0x7) == 0))
    {
        while (u.p64 < end)
        { 
            spooky_mix(u.p64, &h0,&h1,&h2,&h3,&h4,&h5,&h6,&h7,&h8,&h9,&h10,&h11);
	    u.p64 += sc_numVars;
        }
    }
    else
    {
        while (u.p64 < end)
        {
            memcpy(buf, u.p64, sc_blockSize);
            spooky_mix(buf, &h0,&h1,&h2,&h3,&h4,&h5,&h6,&h7,&h8,&h9,&h10,&h11);
	    u.p64 += sc_numVars;
        }
    }

    // handle the last partial block of sc_blockSize bytes
    remainder = (length - ((const uint8 *)end-(const uint8 *)message));
    memcpy(buf, end, remainder);
    memset(((uint8 *)buf)+remainder, 0, sc_blockSize-remainder);
    ((uint8 *)buf)[sc_blockSize-1] = remainder;
    
    // do some final mixing 
    spooky_end(buf, &h0,&h1,&h2,&h3,&h4,&h5,&h6,&h7,&h8,&h9,&h10,&h11);
    *hash1 = h0;
    *hash2 = h1;
}

//
// Hash64: hash a single message in one call, return 64-bit output
//
uint64 spooky_hash64 (
    const void *message,  // message to hash
    size_t length,        // length of message in bytes
    uint64 seed)          // seed
{
    uint64 hash1 = seed;
    spooky_hash128(message, length, &hash1, &seed);
    return hash1;
}

//
// Hash32: hash a single message in one call, produce 32-bit output
//
uint32 spooky_hash32 (
    const void *message,  // message to hash
    size_t length,        // length of message in bytes
    uint32 seed)          // seed
{
    uint64 hash1 = seed, hash2 = seed;
    spooky_hash128(message, length, &hash1, &hash2);
    return (uint32)hash1;
}

//
// Init: initialize the context of a SpookyHash
//
void spooky_init (
    spooky_ctx_t *ctx,
    uint64 seed1,       // any 64-bit value will do, including 0
    uint64 seed2)       // different seeds produce independent hashes
{
    ctx->m_length = 0;
    ctx->m_remainder = 0;
    ctx->m_state[0] = seed1;
    ctx->m_state[1] = seed1;
}

//
// Update: add a piece of a message to a SpookyHash state
//
void spooky_update (
    spooky_ctx_t *ctx,
    const void *message,  // message fragment
    size_t length)        // length of message fragment in bytes
{
    uint64 h0,h1,h2,h3,h4,h5,h6,h7,h8,h9,h10,h11;
    size_t newLength = length + ctx->m_remainder;
    uint8  remainder;
    union 
    { 
        const uint8 *p8; 
        uint64 *p64; 
        size_t i; 
    } u;
    const uint64 *end;
    
    // Is this message fragment too short?  If it is, stuff it away.
    if (newLength < sc_bufSize)
    {
        memcpy(&((uint8 *)ctx->m_data)[ctx->m_remainder], message, length);
        ctx->m_length = length + ctx->m_length;
        ctx->m_remainder = (uint8)newLength;
        return;
    }
    
    // init the variables
    if (ctx->m_length < sc_bufSize)
    {
        h0=h3=h6=h9  = ctx->m_state[0];
        h1=h4=h7=h10 = ctx->m_state[1];
        h2=h5=h8=h11 = sc_const;
    }
    else
    {
        h0 = ctx->m_state[0];
        h1 = ctx->m_state[1];
        h2 = ctx->m_state[2];
        h3 = ctx->m_state[3];
        h4 = ctx->m_state[4];
        h5 = ctx->m_state[5];
        h6 = ctx->m_state[6];
        h7 = ctx->m_state[7];
        h8 = ctx->m_state[8];
        h9 = ctx->m_state[9];
        h10 = ctx->m_state[10];
        h11 = ctx->m_state[11];
    }
    ctx->m_length = length + ctx->m_length;
    
    // if we've got anything stuffed away, use it now
    if (ctx->m_remainder)
    {
        uint8 prefix = sc_bufSize-ctx->m_remainder;
        memcpy(&(((uint8 *)ctx->m_data)[ctx->m_remainder]), message, prefix);
        u.p64 = ctx->m_data;
        spooky_mix(u.p64, &h0,&h1,&h2,&h3,&h4,&h5,&h6,&h7,&h8,&h9,&h10,&h11);
        spooky_mix(&u.p64[sc_numVars], &h0,&h1,&h2,&h3,&h4,&h5,&h6,&h7,&h8,&h9,&h10,&h11);
        u.p8 = ((const uint8 *)message) + prefix;
        length -= prefix;
    }
    else
    {
        u.p8 = (const uint8 *)message;
    }
    
    // handle all whole blocks of sc_blockSize bytes
    end = u.p64 + (length/sc_blockSize)*sc_numVars;
    remainder = (uint8)(length-((const uint8 *)end-u.p8));
    if (ALLOW_UNALIGNED_READS || (u.i & 0x7) == 0)
    {
        while (u.p64 < end)
        { 
            spooky_mix(u.p64, &h0,&h1,&h2,&h3,&h4,&h5,&h6,&h7,&h8,&h9,&h10,&h11);
	    u.p64 += sc_numVars;
        }
    }
    else
    {
        while (u.p64 < end)
        { 
            memcpy(ctx->m_data, u.p8, sc_blockSize);
            spooky_mix(ctx->m_data, &h0,&h1,&h2,&h3,&h4,&h5,&h6,&h7,&h8,&h9,&h10,&h11);
	    u.p64 += sc_numVars;
        }
    }

    // stuff away the last few bytes
    ctx->m_remainder = remainder;
    memcpy(ctx->m_data, end, remainder);
    
    // stuff away the variables
    ctx->m_state[0] = h0;
    ctx->m_state[1] = h1;
    ctx->m_state[2] = h2;
    ctx->m_state[3] = h3;
    ctx->m_state[4] = h4;
    ctx->m_state[5] = h5;
    ctx->m_state[6] = h6;
    ctx->m_state[7] = h7;
    ctx->m_state[8] = h8;
    ctx->m_state[9] = h9;
    ctx->m_state[10] = h10;
    ctx->m_state[11] = h11;
}

//
// Final: compute the hash for the current SpookyHash state
//
// This does not modify the state; you can keep updating it afterward
//
// The result is the same as if SpookyHash() had been called with
// all the pieces concatenated into one message.
//
void spooky_final (
    spooky_ctx_t *ctx,
    uint64 *hash1,    // out only: first 64 bits of hash value.
    uint64 *hash2)    // out only: second 64 bits of hash value.
{
    // init the variables
    if (ctx->m_length < sc_bufSize)
    {
        *hash1 = ctx->m_state[0];
        *hash2 = ctx->m_state[1];
        spooky_short( ctx->m_data, ctx->m_length, hash1, hash2);
        return;
    }
    
    const uint64 *data = (const uint64 *)ctx->m_data;
    uint8 remainder = ctx->m_remainder;
    
    uint64 h0 = ctx->m_state[0];
    uint64 h1 = ctx->m_state[1];
    uint64 h2 = ctx->m_state[2];
    uint64 h3 = ctx->m_state[3];
    uint64 h4 = ctx->m_state[4];
    uint64 h5 = ctx->m_state[5];
    uint64 h6 = ctx->m_state[6];
    uint64 h7 = ctx->m_state[7];
    uint64 h8 = ctx->m_state[8];
    uint64 h9 = ctx->m_state[9];
    uint64 h10 = ctx->m_state[10];
    uint64 h11 = ctx->m_state[11];

    if (remainder >= sc_blockSize)
    {
        // m_data can contain two blocks; handle any whole first block
        spooky_mix(data, &h0,&h1,&h2,&h3,&h4,&h5,&h6,&h7,&h8,&h9,&h10,&h11);
        data += sc_numVars;
        remainder -= sc_blockSize;
    }

    // mix in the last partial block, and the length mod sc_blockSize
    memset(&((uint8 *)data)[remainder], 0, (sc_blockSize-remainder));

    ((uint8 *)data)[sc_blockSize-1] = remainder;
    
    // do some final mixing
    spooky_end(data, &h0,&h1,&h2,&h3,&h4,&h5,&h6,&h7,&h8,&h9,&h10,&h11);

    *hash1 = h0;
    *hash2 = h1;
}
