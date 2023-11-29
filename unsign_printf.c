#include "main.h"

/**
* unsigned_in_printf - unsigned number
* @types: types
* @buffer: Buffer handle print
* @flags: active flags
* @width: Width of f
* @precision: precidion value
* @size: Size
* Return: return value
*/
int unsigned_in_printf(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int index = BUFF_SIZE - 2;
unsigned long int number = va_arg(types, unsigned long int);
int write_result;

number = convert_size_unsgnd(number, size);

if (number == 0)
buffer[index--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (number > 0)
{
buffer[index--] = (number % 10) + '0';
number /= 10;
}

index++;

write_result = write_unsgnd(0, index, buffer, flags, width, precision, size);
return (write_result);
}
