#include "main.h"
#include <stdarg.h>
/**
 * convert_arg - Converts an argument to a signed int and
 *              stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_n struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_arg(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len)
{
long int d, copy;
unsigned int ret = 0, count = 0;
char pad, space = ' ', neg = '-', plus = '+';
if (len == LONG)
{
d = va_arg(args, long int);
}
else
{
d = va_arg(args, int);
}
if (len == SHORT)
{
d = (short)d;
}
if (SPACE_FLAG == 1 && d >= 0)
{
ret += _memcpy(output, &space, 1);
}
if (ZERO_FLAG == 1 && PLUS_FLAG == 1 && d >= 0)
{
ret += _memcpy(output, &plus, 1);
}
if (prec <= 0 && (NEG_FLAG == 0))
{
for (copy = (d < 0) ? -d : d; copy > 0; copy /= 10)
{
count++;
}
count = (d == LONG_MIN) ? 19 : count;
count += (ret != 0) ? ret : 0;
count += (ZERO_FLAG == 0 && (PLUS_FLAG == 1 && d >= 0)) ? 1 : 0;
ret += (ZERO_FLAG == 1 && d < 0) ? _memcpy(output, &neg, 1) : 0;
pad = (ZERO_FLAG == 1) ? '0' : ' ';
for (wid -= (d <= 0) ? (count + 1) : count; wid > 0; wid--)
{
ret += _memcpy(output, &pad, 1);
}
if (d == 0 && prec == 0)
{
ret += _memcpy(output, &pad, 1);
}
}
if (ZERO_FLAG == 0 && d < 0)
{
ret += _memcpy(output, &neg, 1);
}
if (ZERO_FLAG == 0 && (PLUS_FLAG == 1 && d >= 0))
{
ret += _memcpy(output, &plus, 1);
}
if (!(d == 0 && prec == 0))
{
ret += convert_sbase(output, d, "0123456789", flags, 0, prec);
}
if (NEG_FLAG == 1)
{
for (wid -= ret; wid > 0; wid--)
{
ret += _memcpy(output, &space, 1);
}
}
return (ret);
}
/**
 * convert_bi - Converts an unsigned int argument to binary
 *             and stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_n struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_bi(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len)
{
unsigned int num;
num = va_arg(args, unsigned int);
(void)len;
return (convert_ubase(output, num, "01", flags, wid, prec));
}
/**
 * convert_oct - Converts an unsigned int to octal and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list poinitng to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_n struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_oct(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len)
{
unsigned long int num;
unsigned int ret = 0;
char zero = '0', space = ' ';
if (len == LONG)
{
num = va_arg(args, unsigned long int);
}
else
{
num = va_arg(args, unsigned int);
}
if (len == SHORT)
{
num = (unsigned short)num;
}
if (HASH_FLAG == 1 && num != 0)
{
ret += _memcpy(output, &zero, 1);
}
if (!(num == 0 && prec == 0))
{
ret += convert_ubase(output, num, "01234567", flags, wid, prec);
}
if (NEG_FLAG == 1)
{
for (wid -= ret; wid > 0; wid--)
{
ret += _memcpy(output, &space, 1);
}
}
return (ret);
}
/**
 * convert_dec - Converts an unsigned int argument to decimal and
 *               stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_n struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_dec(va_list args, buffer_t *output, unsigned char flags, char wid, char prec, unsigned char len)
{
unsigned long int num;
unsigned int ret = 0;
char space = ' ';
if (len == LONG)
{
num = va_arg(args, unsigned long int);
}
else
{
num = va_arg(args, unsigned int);
}
if (len == SHORT)
{
num = (unsigned short)num;
}
if (!(num == 0 && prec == 0))
{
ret += convert_ubase(output, num, "0123456789", flags, wid, prec);
}
if (NEG_FLAG == 1)
{
for (wid -= ret; wid > 0; wid--)
{
ret += _memcpy(output, &space, 1);
}
}
return (ret);
}
/**
 * convert_int - Converts an unsigned int argument to hex using abcdef
 *             and stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_n struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_int(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len)
{
unsigned long int num;
unsigned int ret = 0;
char *lead = "0x", space = ' ';
if (len == LONG)
{
num = va_arg(args, unsigned long int);
{
else
{
num = va_arg(args, unsigned int);
}
if (len == SHORT)
{
num = (unsigned short)num;
}
if (HASH_FLAG == 1 && num != 0)
{
ret += _memcpy(output, lead, 2);
}
if (!(num == 0 && prec == 0))
{
ret += convert_ubase(output, num, "0123456789abcdef", flags, wid, prec);
}
if (NEG_FLAG == 1)
{
for (wid -= ret; wid > 0; wid--)
{
ret += _memcpy(output, &space, 1);
}
}
return (ret);
}
/**
 * convert_Int - Converts an unsigned int argument to hex using ABCDEF
 *             and stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_n struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_Int(va_list args, buffer_t *output, unsigned char flags, char wid, char prec, unsigned char len)
{
unsigned long int num;
unsigned int ret = 0;
char *lead = "0X", space = ' ';
if (len == LONG)
{
num = va_arg(args, unsigned long);
}
else
{
num = va_arg(args, unsigned int);
}
if (len == SHORT)
{
num = (unsigned short)num;
}
if (HASH_FLAG == 1 && num != 0)
{
ret += _memcpy(output, lead, 2);
}
if (!(num == 0 && prec == 0))
{
ret += convert_ubase(output, num, "0123456789ABCDEF", flags, wid, prec);
}
if (NEG_FLAG == 1)
{
for (wid -= ret; wid > 0; wid--)
{
ret += _memcpy(output, &space, 1);
}
}
return (ret);
}
