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