#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	char a[] = "testio";
	int i = 123;
	const char *fmt = "ismail: %u % d %# X %-011s %p\n";
	ft_printf(fmt, INT_MIN, i, i, a, a);
	printf(fmt, INT_MIN, i, i, a, a);
}
