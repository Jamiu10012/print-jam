#include "main.h"

/**
* character_in_printf - Printf character
* @types: Arguments typws
* @buffer: Buffer array
* @flags: active flags
* @width: Width size
* @precision: printf char precision
* @size: For size
*
* Return: Number of chars printed
*/
int character_in_printf(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char character;
int chars_printed;

character = va_arg(types, int);
chars_printed = handle_write_char(character, buffer,
flags, width, precision, size);

return (chars_printed);
}

/**
* custom_string - Prints a string with formatting options
* @buffer: Buffer array to handle print
* @flags:  Active flags
* @width: Width of the string
* @precision: Precision specification for string length
* @size: Size specifier for the string
* @args: arguments
* Return: Number of characters printed
*/

int custom_string(va_list args, char buffer[],
int flags, int width, int precision, int size)
{
int str_length = 0, i;
char *string_to_print = va_arg(args, char *);

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

if (string_to_print == NULL)
{
string_to_print = "(null)";
if (precision >= 6)
string_to_print = "      ";
}
while (string_to_print[str_length] != '\0')
str_length++;

if (precision >= 0 && precision < str_length)
str_length = precision;

if (width > str_length)
{
if (flags & F_MINUS)
{
write(1, &string_to_print[0], str_length);
for (i = width - str_length; i > 0; i--)
write(1, " ", 1);
return (width);
}
else
{
for (i = width - str_length; i > 0; i--)
write(1, " ", 1);
write(1, &string_to_print[0], str_length);
return (width);
}
}
int str_out = write(1, string_to_print, str_length);
return (str_out);
}
