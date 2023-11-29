#include <stdlib.h>
#include "main.h"

/**
* _printf - Prints formatted output to stdout.
* @format: A string containing format specifiers.
* @... : A variable number of arguments to be formatted.
*
* Return: The number of characters printed
*/

int _printf(const char *format, ...)
{
int count = 0;
va_list args;
va_start(args, format);
for (int i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
switch (format[i + 1])
{
case 'c':
count += 1;
putchar(va_arg(args, int));
break;
case 's':
count += strlen(va_arg(args, char *));
puts(va_arg(args, char *));
break;
case '%':
count += 1;
putchar('%');
break;
default:
/* Invalid format specifier.*/
return (-1);
}
i++;
}
else
{
count += 1;
putchar(format[i]);
}
}
va_end(args);
return (count);
}
