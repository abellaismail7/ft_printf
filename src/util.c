#include <unistd.h>
#include "ft_ds.h"

void	set_filler(t_format *format, int len)
{
	if(len < 0)
		return ;

	while(len--)
	{
		if(format->flags & FILLZERO)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
}

void filler_setter(void(*f)(t_format*, void *), t_format *format, void *value, int len)
{
	if (format->flags & ADJUSTLEFT)
	{
		f(format, value);
		set_filler(format, format->width - len);
	}
	else
	{
		set_filler(format, format->width - len);
		f(format, value);
	}
}

void filler(char c, int times)
{
	if(times <= 0)
		return;
	while(times--)
		write(1, &c, 1);
}

void clear_format(t_format *format)
{
	format->precision = -1;
	format->flags = 0;
	format->width = format->flags; // not working with clangd linux
}

int max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}
