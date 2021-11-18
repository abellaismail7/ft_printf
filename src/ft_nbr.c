/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:04:59 by iait-bel          #+#    #+#             */
/*   Updated: 2021/11/18 17:04:59 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	_ft_putnbr(unsigned int nb)
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
	if(nb > 0 && has_flag(format, FORCE_SIGN))
	{
		write(1, "+", 1);
	}
	else if (nb < 0)
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

void put_addr(t_format format, unsigned long nb)
{
	char a[] = "0123456789abcdef";
	char	c;
	int		i;
	int ignore_zero;

	ignore_zero = 1;
	write(1, "0x", 2);
	i = 16 * 4;
	while (i)
	{
		i -= 4;
		c = nb >> i;
		c = c & 0xf;
		if(ignore_zero && c == 0)
			continue;
		ignore_zero  = 0;
		write(1, a + c, 1);
	}
	format.specifier = 0;
}

void put_hex(t_format format, int nb, int is_upp)
{
	char a[] = "0123456789abcdef";
	char A[] = "0123456789ABCDEF";
	int ignore_zero;
	char *selected;
	char	c;
	int		i;

	i = 0;
	if (has_flag(format, ALTERNATE_FORM))
		i = 2;
	if (has_flag(format, FORCE_SPACE))
	{
		write(1, " ", 1);
		i++;
	}
	set_filler(format, format.width - count_base(nb, 16) - i);
	write(1, "0x", 2 * (i > 0));
	ignore_zero = 1;
	selected = a;
	if (is_upp)
		selected = A;

	i = 8 * 4;
	while (i)
	{
		i -= 4;
		c = nb >> i;
		c = c & 0xf;
		if(ignore_zero && c == 0)
			continue;
		ignore_zero  = 0;
		write(1, selected + c, 1);
	}
	format.specifier = 0;
}

void put_udec(t_format format, int nb)
{
	format.specifier = 0;
	_ft_putnbr(nb);
}
