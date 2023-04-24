#ifndef MAIN_H
#define MAIN_H
/**
 * Project Header file
 *
 */

/**
 * Necessary libraries
 */
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct _flag - D4efining a flags struct.
 * @flag: A character representing a flag.
 * @value: The integer value of the flag.
 */
typedef struct _flag
{
unsigned char flag;
unsigned char value;
} flag_n;

/**
 * struct _buffer - Defining a buffer struct.
 * @buffer: A pointer to a character array.
 * @start: A pointer to the start of buffer.
 * @len: The length of the string stored in buffer.
 */
typedef struct _buffer
{
char *buffer;
char *start;
unsigned int len;
} buffer_n;

/**
 * struct _converter - Defining a converter struct.
 * @specifier: A character representing a conversion specifier.
 * @func: A pointer to a conversion function corresponding to specifier.
 */
typedef struct _converter
{
unsigned char specifier;
unsigned int (*func)(va_list, buffer_n *,unsigned char, char, char, unsigned char);
} converter_n;


/**
 * Funtion Prototypes
 */
int _printf(const char *format, ...);

/**
 * Conversion Specifier Functions.
*/

unsigned int convert_c(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len);
unsigned int convert_s(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len);
unsigned int convert_di(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len);
unsigned int convert_per(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len);
unsigned int convert_b(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len);
unsigned int convert_u(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len);
unsigned int convert_o(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len);
unsigned int convert_x(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len);
unsigned int convert_X(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len);
unsigned int convert_S(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len);
unsigned int convert_p(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len);
unsigned int convert_r(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len);
unsigned int convert_R(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len);





#endif
