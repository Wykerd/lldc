#include <lldc/common.h>
#include <ctype.h>

size_t lldc_urldecode(char* dst, const char* src)
{
    char* org_dst = dst;
    char ch, a, b;
    do {
        ch = *src++;
        if (ch == '%' && isxdigit(a = src[0]) && isxdigit(b = src[1])) {
            if (a < 'A') a -= '0';
            else if(a < 'a') a -= 'A' - 10;
            else a -= 'a' - 10;
            if (b < 'A') b -= '0';
            else if(b < 'a') b -= 'A' - 10;
            else b -= 'a' - 10;
            ch = 16 * a + b;
            src += 2;
        }
        *dst++ = ch;
    } while(ch);
    return (dst - org_dst) - 1;
}

const char hex_table[] = "0123456789abcdef";

/* Converts an integer value to its hex character*/
static inline
char to_hex(char code) {
    return hex_table[code & 15];
}

size_t lldc_urlencode(char* dst, const char *str) 
{
    char *pstr = (char *)str;
    char *pbuf = dst;
    while (*pstr) {
        if (isalnum(*pstr) || *pstr == '-' || *pstr == '_' || *pstr == '.' || *pstr == '~') 
        *pbuf++ = *pstr;
        else if (*pstr == ' ') 
        *pbuf++ = '+';
        else 
        *pbuf++ = '%', *pbuf++ = to_hex(*pstr >> 4), *pbuf++ = to_hex(*pstr & 15);
        pstr++;
    }
    *pbuf = '\0';
    return (dst - pbuf) - 1;
}

static const char *escape_table[] = {
    "\\u0000","\\u0001","\\u0002","\\u0003","\\u0004","\\u0005","\\u0006","\\u0007","\\b","\\t","\\n","\\u000b","\\f","\\r","\\u000e","\\u000f","\\u0010","\\u0011","\\u0012","\\u0013","\\u0014","\\u0015","\\u0016","\\u0017","\\u0018","\\u0019","\\u001a","\\u001b","\\u001c","\\u001d","\\u001e","\\u001f","\\u0020","\\u0021","\\\""
};

static const char *escape_len[] = {
    6,6,6,6,6,6,6,6,2,2,2,6,2,2,6,6,6,6,6,6,6,
    6,6,6,6,6,6,6,6,6,6,6,6,6,2
};

void *lldc_buf_write_json_str (cwr_buf_t *buf, const char *s) 
{
    const char *last = s;
    char *cur = (char *)s;
    while (*cur != '\0') {
        if (((*cur >= '\x00') && (*cur <= '\x1f')) || 
            (*cur == '"') || (*cur == '\\'))
        {
            if (!cwr_buf_push_back(buf, last, cur - last))
                return NULL;
            if (!cwr_buf_push_back(buf, escape_table[(uint8_t)*cur], escape_len[(uint8_t)*cur]))
                return NULL;
            last = cur + 1;
        }
        cur++;
    }
    if (*last != '\0')
        if (!cwr_buf_push_back(buf, last, cur - last))
            return NULL;

    return buf;
}

/**
 * The date functions below (until comment "End Date Utils") are from QuickJS
 *
 * Copyright (c) 2017-2021 Fabrice Bellard
 * Copyright (c) 2017-2021 Charlie Gordon
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include <string.h>
#include <math.h>
#include <time.h>

/* parse a numeric field with an optional sign if accept_sign is TRUE */
static int string_get_digits(const char*sp, size_t sp_len, int *pp, int64_t *pval) {
    int64_t v = 0;
    int c, p = *pp, p_start;
    
    if (p >= sp_len)
        return -1;
    p_start = p;
    while (p < sp_len) {
        c = sp[p];
        if (!(c >= '0' && c <= '9')) {
            if (p == p_start)
                return -1;
            else
                break;
        }
        v = v * 10 + c - '0';
        p++;
    }
    *pval = v;
    *pp = p;
    return 0;
}

static int string_get_signed_digits(const char *sp, size_t sp_len, int *pp, int64_t *pval) {
    int res, sgn, p = *pp;
    
    if (p >= sp_len)
        return -1;

    sgn = sp[p];
    if (sgn == '-' || sgn == '+')
        p++;
 
    res = string_get_digits(sp, sp_len, &p, pval);
    if (res == 0 && sgn == '-')
        *pval = -*pval;
    *pp = p;
    return res;
}

static int string_get_milliseconds(const char*sp, size_t sp_len, int *pp, int64_t *pval) {
    /* parse milliseconds as a fractional part, round to nearest */
    /* XXX: the spec does not indicate which rounding should be used */
    int mul = 1000, ms = 0, p = *pp, c, p_start;
    if (p >= sp_len)
        return -1;
    p_start = p;
    while (p < sp_len) {
        c = sp[p];
        if (!(c >= '0' && c <= '9')) {
            if (p == p_start)
                return -1;
            else
                break;
        }
        if (mul == 1 && c >= '5')
            ms += 1;
        ms += (c - '0') * (mul /= 10);
        p++;
    }
    *pval = ms;
    *pp = p;
    return 0;
}

/* parse a fixed width numeric field */
static int string_get_fixed_width_digits(const char*sp, size_t sp_len, int *pp, int n, int64_t *pval) {
    int64_t v = 0;
    int i, c, p = *pp;

    for(i = 0; i < n; i++) {
        if (p >= sp_len)
            return -1;
        c = sp[p];
        if (!(c >= '0' && c <= '9'))
            return -1;
        v = v * 10 + c - '0';
        p++;
    }
    *pval = v;
    *pp = p;
    return 0;
}

static int64_t floor_div(int64_t a, int64_t b) {
    /* integer division rounding toward -Infinity */
    int64_t m = a % b;
    return (a - (m + (m < 0) * b)) / b;
}

static int64_t days_from_year(int64_t y) {
    return 365 * (y - 1970) + floor_div(y - 1969, 4) -
        floor_div(y - 1901, 100) + floor_div(y - 1601, 400);
}

static int64_t days_in_year(int64_t y) {
    return 365 + !(y % 4) - !(y % 100) + !(y % 400);
}

static int const month_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

/* OS dependent. d = argv[0] is in ms from 1970. Return the difference
   between UTC time and local time 'd' in minutes */
static int getTimezoneOffset(int64_t time) {
#if defined(_WIN32)
    /* XXX: TODO */
    return 0;
#else
    time_t ti;
    struct tm tm;

    time /= 1000; /* convert to seconds */
    if (sizeof(time_t) == 4) {
        /* on 32-bit systems, we need to clamp the time value to the
           range of `time_t`. This is better than truncating values to
           32 bits and hopefully provides the same result as 64-bit
           implementation of localtime_r.
         */
        if ((time_t)-1 < 0) {
            if (time < INT32_MIN) {
                time = INT32_MIN;
            } else if (time > INT32_MAX) {
                time = INT32_MAX;
            }
        } else {
            if (time < 0) {
                time = 0;
            } else if (time > UINT32_MAX) {
                time = UINT32_MAX;
            }
        }
    }
    ti = time;
    localtime_r(&ti, &tm);
    return -tm.tm_gmtoff / 60;
#endif
}

static double time_clip(double t) {
    if (t >= -8.64e15 && t <= 8.64e15)
        return trunc(t) + 0.0;  /* convert -0 to +0 */
    else
        return NAN;
}

/* The spec mandates the use of 'double' and it fixes the order
   of the operations */
static double set_date_fields(double fields[], int is_local) {
    int64_t y;
    double days, d, h, m1;
    int i, m, md;
    
    m1 = fields[1];
    m = fmod(m1, 12);
    if (m < 0)
        m += 12;
    y = (int64_t)(fields[0] + floor(m1 / 12));
    days = days_from_year(y);

    for(i = 0; i < m; i++) {
        md = month_days[i];
        if (i == 1)
            md += days_in_year(y) - 365;
        days += md;
    }
    days += fields[2] - 1;
    h = fields[3] * 3600000 + fields[4] * 60000 + 
        fields[5] * 1000 + fields[6];
    d = days * 86400000 + h;
    if (is_local)
        d += getTimezoneOffset(d) * 60000;
    return time_clip(d);
}

double lldc_date_parse (const char *s)
{
    // parse(s)
    int64_t fields[] = { 0, 1, 1, 0, 0, 0, 0 };
    double fields1[7];
    int64_t tz, hh, mm;
    int p, i, c, sgn, l;
    const char *sp;
    size_t sp_len;
    int is_local;
    
    double rv = NAN;
    
    sp = s;
    sp_len = strlen(s);
    p = 0;
    if (p < sp_len && (((c = sp[p]) >= '0' && c <= '9') || c == '+' || c == '-')) {
        /* ISO format */
        /* year field can be negative */
        if (string_get_signed_digits(sp, sp_len, &p, &fields[0]))
            goto done;

        for (i = 1; i < 7; i++) {
            if (p >= sp_len)
                break;
            switch(i) {
            case 1:
            case 2:
                c = '-';
                break;
            case 3:
                c = 'T';
                break;
            case 4:
            case 5:
                c = ':';
                break;
            case 6:
                c = '.';
                break;
            }
            if (sp[p] != c)
                break;
            p++;
            if (i == 6) {
                if (string_get_milliseconds(sp, sp_len, &p, &fields[i]))
                    goto done;
            } else {
                if (string_get_digits(sp, sp_len, &p, &fields[i]))
                    goto done;
            }
        }
        /* no time: UTC by default */
        is_local = (i > 3);
        fields[1] -= 1;

        /* parse the time zone offset if present: [+-]HH:mm or [+-]HHmm */
        tz = 0;
        if (p < sp_len) {
            sgn = sp[p];
            if (sgn == '+' || sgn == '-') {
                p++;
                l = sp_len - p;
                if (l != 4 && l != 5)
                    goto done;
                if (string_get_fixed_width_digits(sp, sp_len, &p, 2, &hh))
                    goto done;
                if (l == 5) {
                    if (sp[p] != ':')
                        goto done;
                    p++;
                }
                if (string_get_fixed_width_digits(sp, sp_len, &p, 2, &mm))
                    goto done;
                tz = hh * 60 + mm;
                if (sgn == '-')
                    tz = -tz;
                is_local = 0;
            } else if (sgn == 'Z') {
                p++;
                is_local = 0;
            } else {
                goto done;
            }
            /* error if extraneous characters */
            if (p != sp_len)
                goto done;
        }
    }
    for(i = 0; i < 7; i++)
        fields1[i] = fields[i];
    rv = set_date_fields(fields1, is_local) - tz * 60000;

done:
    return rv;
}

/* End Date Utils */

double lldc_date_now () 
{
    uv_timeval64_t tv;
    uv_gettimeofday(&tv);
    return ((int64_t)tv.tv_sec) * 1000.0 + (tv.tv_usec / 1000.0);
}
