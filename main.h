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
 * Macros Length Modifiers
 */
#define SHORT 1
#define LONG 2


/**
 * Macros Flag Modifiers
 */
#define PLUS 1
#define SPACE 2
#define HASH 4
#define ZERO 8
#define NEG 16
#define PLUS_FLAG (flags & 1)
#define SPACE_FLAG ((flags >> 1) & 1)
#define HASH_FLAG ((flags >> 2) & 1)
#define ZERO_FLAG ((flags >> 3) & 1)
#define NEG_FLAG ((flags >> 4) & 1)


/**
 * struct _flag - Defining a flags struct.
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
int _putchar(char c);

/**
 * Conversion Specifier Functions.
*/

unsigned int convert_chr(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len);
unsigned int convert_str(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len);
unsigned int convert_arg(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len);
unsigned int convert_cent(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len);
unsigned int convert_bin(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len);
unsigned int convert_dec(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len);
unsigned int convert_oct(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len);
unsigned int convert_int(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len);
unsigned int convert_Int(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len);
unsigned int convert_Str(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len);
unsigned int convert_add(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len);
unsigned int reverse_str(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len);
unsigned int str_ROT13(va_list args, buffer_n *output, unsigned char flags, char wid, char prec, unsigned char len);


/**
 * Handlers
 * flag_handler - to handle flags
 * len_handler - to handle length of modifier
 * wid_handler - to handle width of modifiers
 * pre_handler - precision handler
 * spec_handler - specifier handler
 */
unsigned char flag_handler(const char *flags);
unsigned char len_handler(const char *modifier);
char wid_handler(va_list args, const char *modifier, char *index);
char pre_handler(va_list args, const char *modifier, char *index);
unsigned int (*spec_handler(const char *specifier))(va_list, buffer_n *, unsigned char, char, char, unsigned char);






/**
 * Additional Functions
 */
buffer_n *init_buffer(void);
void free_buffer(buffer_n *output);
unsigned int _memcpy(buffer_n *output, const char *src, unsigned int n);
unsigned int convert_sbase(buffer_n *output, long int num, char *base, unsigned char flags, char wid, char prec);
unsigned int convert_ubase(buffer_n *output, unsigned long int num, char *base, unsigned char flags, char wid, char prec);





#endif /*MAIN_H*/
