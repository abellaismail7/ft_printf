#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	const char *fmt = "ismail: %0#- +1.1@@ %u % d %# X %11s %9 \n";
	int ret;
	fflush(stdout);

	puts("===== test i  ====");
	fflush(stdout);
	fmt = " %p";
	ret = ft_printf(fmt, fmt);
	printf("(%d)\n", ret);
	ret = printf(fmt, fmt);
	printf("(%d)\n", ret);
	fflush(stdout);
}
