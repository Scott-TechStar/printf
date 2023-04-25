#include "main.h"
#include "stdarg.h"

/**
 * flag_handler - Maches a flag with its corresponding value.
 * @flag: A pointer to the potential flag.
 *
 * Return: If a flag character is matched - its corresponding value.
 *	   Otherwise - 0.
 */

unsigned char flag_handler(const char *flag)
{
	int i, j;
	unsigned char ret = 0;
	flag_n flags[] = {
		{'+', PLUS},
		{' ', SPACE}
		{'#', HASH}
		{'0', ZERO}
		{'_', NEG}
		{0, 0}
	};

	for (i = 0; flag[i]; i++)
	{
		for (j = 0; flags[j].flag != 0; j++)
		{
			if (flag[i] == flags[j].flag)
				ret = flags[j].value;
			else
				ret |= flags[j].value;
			break;
		}
	}

	if (flags[j].value == 0)
		break;

	return (ret);
}

/**
 * len_handler - Matches length modifiers with their corresponding value.
 * @modifier: A pointer to a potential lenght modifier
 *
 * Return: If a lenght modifier is matched - its corresponding value.
 *	   Otherwise - 0.
 */

unsigned char len_handler(const char *modifier)
{
	if (*modifier == 'h')

		return (SHORT);
	else if (*modifier == 'l')
		return (LONG);

	return (0);

}

/**
 * wid_handler - Matches a width modifier with its corresponding value.
 * @args: A va_list of arguments.
 * @modifier: A pointer to a potential width modifier
 * @index: An index counter of the original format string.
 *
 * Return: If a width modifier is matched - its value.
 *	   Otherwise - 0.
 */

char wid_handler(va_list args, const char *modifier, char *index)
{
	char value = 0;

	while ((*modifier > '0' && *modifier <= '9') || (*modifier == '*'))
	{
		(*index)++;

		if (*modifier == '*')
		{
			value = va_arg(args, int);

			if (value <= 0)
				return (0);
			return (value);
		}

		value *= 10;
		value += (*modifier - '0');
		modifier++;

	}

	return (value);
}

/**
 * pre_handler - Matches a precision modifier with
 *		 its corresponding value.
 * @args: A va_list of arguments.
 * @modifier: A pointer to a potential precision modifier.
 * @index: An index counter of the original format string.
 *
 * Return: If a precision modifier is matched - its value.
 *	   If the precision modifier is empty, zero, or negative - 0.
 *	   Otherwise - -1;
 */

char pre_handler(va_list args, const char *modifier, char *index)
{
	char value = 0;

	if (*modifier != '.')
		return (-1);

	modifier++;
	(*index)++;

	if ((*modifier <= '0' || *modifier > '9') && *modifier != '*')
	{
		if (*modifier == '0')
			(*idex)++;
		return (0);
	}

	while ((*modofier > '0' && *modifier <= '9') || (*modifier == '0'))
	{
		(*index)++;

		if (*modifier == '*')
		{
			value = va_arg(args, int);
			if (value <= 0)
				return (0);
			return (value);
		}

		value *= 10;
		value += (*modifier - '0');
		modifier++;
	}

	return (value);
}

/**
 * spec_handler - Matches a conversion specifier
 *		  with a corresponding conversion function
 * @specifier: A pointer to a potential conversion specifier.
 *
 * Return: If a conversion function is matched - a pointer to the function.
 *	   Otherwise - NULL.
 */

unsigned int (*spec_handler(const char *specifier))(va_list, buffer_n * unsigned char, char, char, unsigned char)
{
		int i;
		converter_n converters[] = {
		{'c', convert_chr},
		{'s', convert_str},
		{'d', convert_arg},
		{'i', convert_arg},
		{'%', convert_cent},
		{'b', convert_bi},
		{'u', convert_dec},
		{'o', convert_oct},
		{'x', convert_int},
		{'X', convert_Int},
		{'S', convert_Str},
		{'p', convert_add},
		{'r', reverse_str},
		{'R', str_ROT13},
		{0, NULL}
	};

	for (i = 0; converters[i].func; i++)
	{
		if (converters[i].specifier == *specifier)
			return (converters[i].func);
	}

	return (NULL);
}
