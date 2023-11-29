#include "main.h"

/**
* binary_in_printf - binary representation of an unsigned number
* @types: types
* @buffer: Buffer to handle print
* @flags: flags
* @width: pecification
* @precision: Preci
* @size: Size specifier
* Return: return value
*/
int binary_in_printf(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
unsigned int num, mask, i, sum;
unsigned int binary_array[32];
int count = 0;

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

num = va_arg(types, unsigned int);
mask = 2147483648; /* 2^31 */
binary_array[0] = num / mask;

for (i = 1; i < 32; i++)
{
mask /= 2;
binary_array[i] = (num / mask) % 2;
}

for (i = 0, sum = 0; i < 32; i++)
{
sum += binary_array[i];
if (sum || i == 31)
{
char binary_char = '0' + binary_array[i];
write(1, &binary_char, 1);
count++;
}
}
return (count);
}

/**
* unsigned_function - Prints an unsigned number
* @types: List of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: Width
* @precision: Precision specification
* @size: Size specifier
* Return: Number of characters printed
*/
int unsigned_function(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
int write_result;

num = convert_size_unsgnd(num, size);

if (num == 0)
buffer[i--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buffer[i--] = (num % 10) + '0';
num /= 10;
}

i++;

write_result = write_unsgnd(0, i, buffer, flags, width, precision, size);
return (write_result);
}

/**
* print_hexadecimal_notation - In hexadecimal notation
* @types: List of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: Width
* @precision: Precision specifier
* @size: Size to specifier
* Return: Number of characters printed
*/
int print_hexadecimal_notation(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int result = print_hexa(types, "0123456789abcdef", buffer,
flags, 'x', width, precision, size);
return (result);
}
