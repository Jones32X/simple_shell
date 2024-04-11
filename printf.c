#include "simple.h"

/**
* _putchar - writes the character c to stdout
* @c: Character for printing
* Return: On success 1.
* On error, -1 is returned, and errno appropriately set.
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* p_char - writes the character c to stdout.
* @arguments: The character to print
* Return: int.
*/

int p_char(va_list arguments)
{
	_putchar(va_arg(arguments, int));
	return (1);
}

/**
* p_int - print var type int
* @arguments: arguments
* Return: Int
*/

int p_int(va_list arguments)
{
	long int n, n_aux, d = 1, l_aux;
	int count = 0;

	n = va_arg(arguments, int);

	if (n < 0)
	{
		n_aux = -n;
		_putchar('-');
		count++;
	}
	else
		n_aux = n;
	l_aux = n_aux;
	while (n_aux > 9)
	{
		n_aux = n_aux / 10;
		d *= 10;
	}
	while (d > 0)
	{
		_putchar(((l_aux / d) % 10) + '0');
		count++;
		d /= 10;
	}
	return (count);
}

/**
* p_str - var string type.
* @arguments: number of arguments.
* Return: Int.
*/

int p_str(va_list arguments)
{
	char *p;
	int ax = 0;

	p = va_arg(arguments, char *);
	if (p == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	for (; p[ax] != '\0' ; ax++)
	{
	_putchar(p[ax]);
	}
	return (ax);
}

/**
* _printf - print c,s,f,u,i,d
* @format: arguments
* Return: all char's length
*/

int _printf(const char *format, ...)
{
form types[] = {
	{"c", p_char}, {"s", p_str}, {"d", p_int}, {"i", p_int}, {NULL, NULL}};
	va_list arguments;
	int len = 0, pos = 0, pos_form;

	va_start(arguments, format);
	if (!format || !format[pos])
		return (-1);
	for (; format[pos]; pos++)
	{
		if (format[pos] == '%')
		{
			if (format[pos + 1] == '\0')
				return (-1);
			if (format[pos + 1] == '%')
				_putchar(37), len++;
			else
			{
				for (pos_form = 0; types[pos_form].ch != NULL; pos_form++)
				{
					if (types[pos_form].ch[0] == format[pos + 1])
					{
						len += types[pos_form].func(arguments);
						break;
					}
				}
				if (types[pos_form].ch == NULL)
				{
					_putchar(format[pos]);
					_putchar(format[pos + 1]), len += 2;
				}
			}
			pos++;
		}
		else
			_putchar(format[pos]), len++;
	}
	va_end(arguments);
	return  (len);
}
