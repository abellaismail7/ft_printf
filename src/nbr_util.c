#include "ft_ds.h"
#include "util.h"
#include <unistd.h>

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

int count_unsigned(unsigned long long nb, int base)
{
	int		count;

	count = (nb == 0);
	while (nb)
	{
		nb /= base;
		count++;
	}
	return count;
}

int	_ft_putnbr(unsigned int nb);
int	__ft_putnbr(t_format format, unsigned int nb, int size)
{
	int ret;

	ret = size;
	if(format.precision != -1 && format.precision >= size)
	{
		filler('0', format.precision - size);
		ret = format.precision;
	}
	_ft_putnbr(nb);
	return ret;
}

int	_ft_putnbr(unsigned int nb)
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
	return count_base(nb, 10);
}

int _put_hex(t_format format, unsigned long long nb, int is_upp)
{
	char c;
	int	i;
	int count;
	int ignore_zero;
	char *selected[] = {
		"0123456789abcdef0x",
	 	"0123456789ABCDEF0X"
	};

	ignore_zero = 1;
	i = 0;
	count = 0;
	if (format.flags & ALTERNATE_FORM)
		i = 2;
	write(1, selected[is_upp] + 16, 2 * (i > 0));
	count += count_unsigned(nb, 16);
	if(format.precision != -1 && format.precision >= i + count)
	{
		filler('0', format.precision - i - count);
		count = format.precision;
	}
	count += i;
	i = 16 * 4;
	while (i)
	{
		i -= 4;
		c = nb >> i;
		c = c & 0xf;
		if(ignore_zero && c == 0)
			continue;
		ignore_zero  = 0;
		write(1, selected[is_upp] + c, 1);
	}
	if(ignore_zero)
		write(1, "0", 1);
	return count;
}

