#include<unistd.h>
#include "ft_ds.h"
#include "util.h"

int	nbr_size(int nbr, int len)
{
	int	i;

	i = 0;
	while (nbr)
	{
		nbr /= len;
		i++;
	}
	return (i);
}

void	_ft_putnbr(int nb)
{
	int	c;

	if (nb < 10)
	{
		c = nb + '0';
		write(1, &c, 1);
	}
	else
	{
		_ft_putnbr(nb / 10);
		_ft_putnbr(nb % 10);
	}
}

void    put_nbr(t_format format, int nb)
{
	int	min;
	int size;

	size = (nb <= 0) + nbr_size(nb, 10);
	if (nb < 0)
	{
		size++;
		write(1, "-", 1);
		min = 1 << (sizeof(int) * 8 - 1);
		if (min == nb)
		{
			_ft_putnbr(nb / 10 * -1);
			_ft_putnbr(nb % 10 * -1);
			return ;
		}
		nb = nb * -1;
	}
	if (format.flags & ADJUSTLEFT) {
		_ft_putnbr(nb);
		filler('0', format.width - size);
	}
	else
	{
		filler('0', format.width - size);
		_ft_putnbr(nb);
	}
}

int put_frac(double frac, int precision)
{
	int count;
	char c;

	count = 6;
	frac *= 10;
	while((precision == -1 && count && frac > 0) || precision)
	{
		c = (int) frac;
		frac -= c;
		c += '0';
		write(1, &c, 1); 
	    frac *= 10;
		count--;
		precision--;
	}

	return count;
}

void put_float(t_format format, double nb)
{
	int integral;

	integral = (int) nb;

	put_nbr(format, integral);
	if(format.precision == 0)
		return ;
	write(1, ".", 1);
	put_frac(nb - integral, format.precision);
}

