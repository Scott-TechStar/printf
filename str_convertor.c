#include "main.h"
/**
 * convert_str - Converts an argument to a string and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_n struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_str(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len)
{
char *str, *null = "(null)", width = ' ';
int size;
unsigned int ret = 0;
(void)flags;
(void)len;
str = va_arg(args, char *);
if (str == NULL)
{
return (_memcpy(output, null, 6));
}
for (size = 0; *(str + size);)
{
size++;
}
if (NEG_FLAG == 0)
{
for (wid -= (prec == -1) ? size : prec; wid > 0; wid--)
{
ret += _memcpy(output, &width, 1);
}
}
prec = (prec == -1) ? (int)size : prec;
while (*str != '\0' && prec > 0)
{
ret += _memcpy(output, str, 1);
prec--;
str++;
}
if (NEG_FLAG == 1)
{
for (wid -= ret; wid > 0; wid--)
{
ret += _memcpy(output, &width, 1);
}
}
return (ret);
}
/**
 * convert_Str - Converts an argument to a string and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_n struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 *
 * Description: Non-printable characteres (ASCII values < 32 or >= 127)
 *              are stored as \x followed by the ASCII code value in hex.
 */
unsigned int convert_Str(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len)
{
char *str, *null = "(null)", *hex = "\\x", *zero = "0", width = ' ';
int size, index;
unsigned int ret = 0;
(void)len;
str = va_arg(args, char *);
if (str == NULL)
{
return (_memcpy(output, null, 6));
}
for (size = 0; str[size];)
{
size++;
}
if (NEG_FLAG == 0)
{
for (wid -= (prec == -1) ? size : prec; wid > 0; wid--)
{
ret += _memcpy(output, &width, 1);
}
}
prec = (prec == -1) ? size : prec;
for (index = 0; *(str + index) != '\0' && index < prec; index++)
{
if (*(str + index) < 32 || *(str + index) >= 127)
{
ret += _memcpy(output, hex, 2);
if (*(str + index) < 16)
{
ret += _memcpy(output, zero, 1);
}
ret += convert_ubase(output, *(str + index), "0123456789ABCDEF", flags, 0, 0);
continue;
}
ret += _memcpy(output, (str + index), 1);
}
if (NEG_FLAG == 1)
{
for (wid -= ret; wid > 0; wid--)
{
ret += _memcpy(output, &width, 1);
}
}
return (ret);
}
/**
 * reverse_str - Reverses a string and stores it
 *             to a buffer contained in a struct.
 * @args: A va_list pointing to the string to be reversed.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_n struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int reverse_str(va_list args, buffer_t *output, unsigned char flags, char wid, char prec, unsigned char len)
{
char *str, *null = "(null)", width = ' ';
int size, end, i;
unsigned int ret = 0;
(void)flags;
(void)len;
str = va_arg(args, char *);
if (str == NULL)
{
return (_memcpy(output, null, 6));
}
for (size = 0; *(str + size);)
{
size++;
}
if (NEG_FLAG == 0)
{
for (wid -= (prec == -1) ? size : prec; wid > 0; wid--)
{
ret += _memcpy(output, &width, 1);
}
}
end = size - 1;
prec = (prec == -1) ? (int)size : prec;
for (i = 0; end >= 0 && i < prec; i++)
{
ret += _memcpy(output, (str + end), 1);
end--;
}
if (NEG_FLAG == 1)
{
for (wid -= ret; wid > 0; wid--)
{
ret += _memcpy(output, &width, 1);
}
}
return (ret);
}
/**
 * str_ROT13 - Converts a string to ROT13 and stores
 *             it to a buffer contained in a struct.
 * @args: A va_list pointing to the string to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A lenth modifier.
 * @output: A buffer_n struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int str_ROT13(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len)
{
char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
char *str, *null = "(null)", width = ' ';
int i, j, size;
unsigned int ret = 0;
(void)flags;
(void)len;
str = va_arg(args, char *);
if (str == NULL)
{
return (_memcpy(output, null, 6));
}
for (size = 0; *(str + size);)
{
size++;
}
if (NEG_FLAG == 0)
{
for (wid -= (prec == -1) ? size : prec; wid > 0; wid--)
{
ret += _memcpy(output, &width, 1);
}
}
prec = (prec == -1) ? (int)size : prec;
for (i = 0; *(str + i) != '\0' && i < prec; i++)
{
for (j = 0; j < 52; j++)
{
if (*(str + i) == *(alpha + j))
{
ret += _memcpy(output, (rot13 + j), 1);
break;
}
}
if (j == 52)
{
ret += _memcpy(output, (str + i), 1);
}
}
if (NEG_FLAG == 1)
{
for (wid -= ret; wid > 0; wid--)
{
ret += _memcpy(output, &width, 1);
}
}
return (ret);
}
/**
 * convert_chr - Converts an argument to an unsigned char and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_n struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_chr(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len)
{
	char c, width = ' ';
	unsigned int ret = 0;

	c = va_arg(args, int);

	(void)prec;
	(void)len;

	if (NEG_FLAG == 0)
	{
		for (; wid > 1; wid--)
			ret += _memcpy(output, &width, 1);
	}

	ret += _memcpy(output, &c, 1);

	if (NEG_FLAG == 1)
	{
		for (wid -= ret; wid > 0; wid--)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}

/**
 * convert_cent - Stores a percent sign to a
 *                   buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_n struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer (always 1).
 */
unsigned int convert_cent(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len)
{
	char percent = '%', width = ' ';
	unsigned int ret = 0;

	(void)args;
	(void)prec;
	(void)len;

	if (NEG_FLAG == 0)
	{
		for (; wid > 1; wid--)
			ret += _memcpy(output, &width, 1);
	}

	ret += _memcpy(output, &percent, 1);

	if (NEG_FLAG == 1)
	{
		for (wid -= ret; wid > 1; wid--)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}

/**
 * convert_add - Converts the address of an argument to hex and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_n struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_add(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len)
{
	char *null = "(nil)", width = ' ';
	unsigned long int address;
	unsigned int ret = 0;

	(void)len;

	address = va_arg(args, unsigned long int);
	if (address == '\0')
		return (_memcpy(output, null, 5));

	flags |= 32;

	ret += convert_ubase(output, address, "0123456789abcdef",
			flags, wid, prec);

	if (NEG_FLAG == 1)
	{
		for (wid -= ret; wid > 0; wid--)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}
