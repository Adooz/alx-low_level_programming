#include "function_pointers.h"

/**
 * print_name - A function that prints a name.
 * @name: name pointer
 * @f: function pointer
 */

void print_name(char *name, void (*f)(char *))
{
	if (!f)
		return;
	(*f)(name);
}
