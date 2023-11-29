#include "main.h"

/**
* unsigned_octal_in_printf - Print octal function
* @types: types
* @buffer:  array to handle print
* @flags: active flags
* @width: Width size
* @precision: Precision
* @size: Size
* Return: return value
*/
int unsigned_octal_in_printf(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int index = BUFF_SIZE - 2;
unsigned long int number = va_arg(types, unsigned long int);
unsigned long int initial_number = number;
int write_result;
UNUSED(width);

number = convert_size_unsgnd(number, size);

if (number == 0)
buffer[index--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (number > 0)
{
buffer[index--] = (number % 8) + '0';
number /= 8;
}

if (flags & F_HASH && initial_number != 0)
buffer[index--] = '0';

index++;

write_result = write_unsgnd(0, index, buffer, flags, width, precision, size);
return (write_result);
}
