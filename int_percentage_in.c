#include "main.h"
/**
* custom_int_in_printf - Prints an integer with specified options
* @args:  argum
* @buffer: array buffer
* @flags: Active flags
* @width: Width of the integer
* @precision: Precision specification
* @size: Size specifier
* Return: Number of characters printed
*/

int custom_int_in_printf(va_list args, char buffer[],
int flags, int width, int precision, int size)
{
int index = BUFF_SIZE - 2;
int negative = 0;
long int number = va_arg(args, long int);
unsigned long int unsigned_number;
int result;

number = convert_size_number(number, size);

if (number == 0)
buffer[index--] = '0';

buffer[BUFF_SIZE - 1] = '\0';
unsigned_number = (unsigned long int)number;

if (number < 0)
{
unsigned_number = (unsigned long int)((-1) * number);
negative = 1;
}

while (unsigned_number > 0)
{
buffer[index--] = (unsigned_number % 10) + '0';
unsigned_number /= 10;
}

index++;

result = write_number_custom(negative, index,
		buffer, flags, width, precision, size);
return (result);
}

/**
* custom_percentage - Prints a percent sign with specified options
* @args: arguments
* @buffer: Buffer to handle print
* @flags: Active
* @width: Width of the percent
* @precision: Precision specif
* @size: Size of text
* Return: Number of characters
*/
int custom_percentage(va_list args, char buffer[],
int flags, int width, int precision, int size)
{
UNUSED(args);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
return (write(1, "%%", 1));
}
