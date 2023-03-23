#include "variadic_functions.h"
/**
 * print_char - prints a ASCII character
 * @arg: argument to be printed
 */
void print_char(va_list arg)
{
	printf("%c", va_arg(arg, int));
}

/**
 * print_int - prints an integer
 * @arg: argument to be printed
 */
void print_int(va_list arg)
{
	printf("%i", va_arg(arg, int));
}

/**
 * print_float - prints a float number
 * @arg: argument to be printed
 */
void print_float(va_list arg)
{
	printf("%f", va_arg(arg, double));
}

/**
 * print_str - prints a string
 * @arg: argument to be printed
 */
void print_str(va_list arg)
{
	char *string = va_arg(arg, char *);

	if (!string)
		string = "(nil)";
	printf("%s", string);
}

/**
 * print_all- prints anything
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	va_list list;
	int i = 0, j;
	char *separator = "";
	prt format_funcs[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_str},
	};

	va_start(list, format);
	while (format && format[i])
	{
		j = 0;
		while (j < 4)
		{
			if (format[i] == format_funcs[j].symbol)
			{
				printf("%s", separator);
				format_funcs[j].print(list);
				separator = ", ";
				break;
			}
			j++;
		}
		i++;
	}
	printf("\n");
	va_end(list);
}
