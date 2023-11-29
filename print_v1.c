#include "main.h"
void flush_buffer(char buffer[], int *buff_index);
/**
* _printf - Custom printf function
* @format: The format string
* Return: Number of printed characters
*/
int _printf(const char *format, ...)
{
int i, printed_chars = 0, flags, width, precision, size, buff_index = 0;
va_list args_list;
char output_buffer[BUFF_SIZE];

if (format == NULL)
return (-1);

va_start(args_list, format);

for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
output_buffer[buff_index++] = format[i];
if (buff_index == BUFF_SIZE)
flush_buffer(output_buffer, &buff_index);
printed_chars++;
}
else
{
flush_buffer(output_buffer, &buff_index);
flags = get_flags(format, &i);
width = get_width(format, &i, args_list);
precision = get_precision(format, &i, args_list);
size = get_size(format, &i);
++i;
int printed = handle_print(format, &i, args_list,
	      output_buffer, flags, width, precision, size);
if (printed == -1)
return (-1);
our_result = printed_chars += printed;
}
}

flush_buffer(output_buffer, &buff_index);

va_end(args_list);

return (our_result);
}

/**
* flush_buffer - Display the content
* @buffer: Array of characters in the file
* @buff_index: The index of the buffer.
*/
void flush_buffer(char buffer[], int *buff_index)
{
if (*buff_index > 0)
write(1, &buffer[0], *buff_index);

*buff_index = 0;
}
