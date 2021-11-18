

#include <unistd.h>
#include "ft_ds.h"

void	set_filler(t_format format, int len)
{
	if(len < 0)
		return ;
	while(len--)
	{
		if((format.flags & FILLER) == FILLER)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
}

int has_flag(t_format format,int flag)
{
	return ((format.flags & flag) == flag);
}

int count_base(int nb, int base)
{
	int		count;

	count = (nb <= 0);
	while (nb)
	{
		nb /= base;
		count++;
	}
	return count;
}

void filler(char c, int times)
{
	while(times--)
		write(1, &c, 1);
}
