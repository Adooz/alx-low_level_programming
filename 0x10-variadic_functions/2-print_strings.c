#include "variadic_functions.h"

/**
* print_strings - print strings
* @n: number of strings passed to the function
* @separator: the string to be printed between the strings
*/
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list args;
	char *str = NULL;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(args, char *);
		if (str)
		{
			printf("%s", str);
		}
		if (!str)
		{
			printf("(nil)");
		}
		if (separator && i != n - 1)
		{
			printf("%s", separator);
		}
	}

	printf("\n");
	va_end(args);
}
