#include "main.h"
#include <stdarg.h>
/**
 * num_bits - Counts the number of bits set.
 *
 * @num: Binary number.
 *
 * Return: Number of bits set to one.
 */
unsigned char num_bits(unsigned char num)
{
unsigned char set = 0;
while (num != 0)
{
if ((num & 1) == 1)
{
set++;
}
num >>= 1;
}
return (set);
}
/**
 * clear_op - Clear operations for _printf.
 * @args: A va_list of arguments provided to _printf.
 * @output: A buffer_n struct.
 */
void clear_op(va_list args, buffer_n *output)
{
va_end(args);
write(1, output->start, output->len);
free_buffer(output);
}
/**
 * read_printf - Reads through the format string for _printf.
 * @format: Character string to print - may contain directives.
 * @output: A buffer_n struct containing a buffer.
 * @args: A va_list of arguments.
 *
 * Return: The number of characters stored to output.
 */
int read_printf(const char *format, va_list args, buffer_n *output)
{
int index, ret = 0;
char wid, prec, tmp;
unsigned char flag, len;
unsigned int (*f)(va_list, buffer_n *, unsigned char, char, char, unsigned char);
for (index = 0; *(format + index); index++)
{
len = 0;
if (*(format + index) == '%')
{
flag = flag_handler(format + index + 1);
tmp = num_bits(flag);
wid = wid_handler(args, format + index + tmp + 1, &tmp);
prec = pre_handler(args, format + index + tmp + 1, &tmp);
len = len_handler(format + index + tmp + 1);
tmp += (len != 0) ? 1 : 0;
f = spec_handler(format + index + tmp + 1);
if (f != NULL)
{
index += tmp + 1;
ret += f(args, output, flag, wid, prec, len);
continue;
}
else if (*(format + index + tmp + 1) == '\0')
{
ret = -1;
break;
}
}
ret += _memcpy(output, (format + index), 1);
index += (len != 0) ? 1 : 0;
}
clear_op(args, output);
return (ret);
}
/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print - may contain directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
buffer_n *output;
va_list args;
int ret;
if (format == NULL)
{
return (-1);
}
output = init_buffer();
if (output == NULL)
{
return (-1);
}
va_start(args, format);
ret = read_printf(format, args, output);
return (ret);
}
