

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

int count_hex(int nb)
{
	int		count;

	count = 0;
	while (nb)
	{
		nb /= 16;
		count++;
	}
	return count;
}

void filler(char c, int times)
{
	while(times--)
		write(1, &c, 1);

}
