#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
* _printf - produces output according to a format
* @format: character string containing zero or more directives
*
* Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
count += write(1, &va_arg(args, int), 1);
break;
case 's':
count += write(1, va_arg(args, char *), strlen(va_arg(args, char *)));
break;
case '%':
count += write(1, "%", 1);
break;
default:
count += write(1, "%", 1);
count += write(1, &(*format), 1);
break;
}
}
else
{
count += write(1, &(*format), 1);
}
format++;
}
va_end(args);
return (count);
}
