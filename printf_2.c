#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
/**
* _printf - prints formatted output to stdout
* @format: character string containing zero or more directives
*
* Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
int count = 0;
va_list args;
char *str;
va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
count += putchar(va_arg(args, int));
break;
case 's':
str = va_arg(args, char *);
if (!str)
str = "(null)";
count += printf("%s", str);
break;
case '%':
count += putchar('%');
break;
default:
count += putchar('%');
count += putchar(*format);
break;
}
}
else
{
count += putchar(*format);
}
format++;
}
va_end(args);
return (count);
}
