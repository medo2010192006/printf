#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - prints output according to a format
 * @format: format string
 *
 * Return: number of characters printed (excluding null byte)
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
				count += write(1, va_arg(args, char *), _strlen(va_arg(args, char *)));
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

/**
 * _strlen - calculates the length of a string
 * @str: string
 *
 * Return: length of string
 */
int _strlen(char *str)
{
	int len = 0;

	while (*str)
	{
		len++;
		str++;
	}

	return (len);
}

