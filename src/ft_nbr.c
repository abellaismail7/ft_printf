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
#include "ft_str.h"
#include "util.h"

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

int    put_nbr(t_format format, int nb)
{
	int	min;
	int size;

	size = nb <= 0;
	if(nb >= 0 && (format.flags & FORCE_SIGN))
		write(1, "+", ++size >= 0);
	else if (nb >= 0 && (format.flags & FORCE_SPACE))
		write(1, " ", ++size >= 0);
	if(nb == 0 && format.precision == 0)
		return size;
	size += count_base(nb, 10) - (nb <= 0);
	if(format.precision != -1 && format.precision >= size)
	{
		filler('0', format.precision - size + (nb < 0));
		size = format.precision;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		min = 1 << (sizeof(int) * 8 - 1);
		if (min == nb)
		{
			_ft_putnbr(nb / 10 * -1);
			_ft_putnbr(nb % 10 * -1);
			return max(size, format.width);
		}
		nb = nb * -1;
	}
	if (format.flags & ADJUSTLEFT)
	{
		_ft_putnbr(nb);
		set_filler(format, format.width - size);
	}
	else
	{
		set_filler(format, format.width - size);
		_ft_putnbr(nb);
	}
	return max(size, format.width);
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

void _put_hex(unsigned long long nb, int is_upp, int i)
{
	char a[] = "0123456789abcdef0x";
	char A[] = "0123456789ABCDEF0X";
	char c;
	int ignore_zero;
	char *selected;

	ignore_zero = 1;
	selected = a;
	if (is_upp)
		selected = A;
	write(1, selected + 16, 2 * (i > 0));

	i = 16 * 4;
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
	if(ignore_zero)
		write(1, "0", 1);
}

int	put_hex(t_format format, unsigned long long nb, int is_upp)
{
	int		i;

	i = 0;
	if (nb != 0 && format.flags & ALTERNATE_FORM)
		i = 2;
	if (format.flags & ADJUSTLEFT)
	{
		_put_hex(nb, is_upp, i);
		set_filler(format, format.width - count_unsigned(nb, 16) - i);
	}
	else
	{
		set_filler(format, format.width - count_unsigned(nb, 16) - i);
		_put_hex(nb, is_upp, i);
	}
	return max(format.width, i + count_unsigned(nb, 16));
}

int put_addr(t_format format, unsigned long long nb)
{
	if (nb == 0)
	{
		put_fstr(format, "(nil)");
		return 5; 
	}
	format.flags = format.flags | ALTERNATE_FORM;
	return put_hex(format, nb, 0);
}

int put_udec(t_format format, unsigned int nb)
{
	format.specifier = format.width;
	if (format.flags & ADJUSTLEFT)
	{
		_ft_putnbr(nb);
		set_filler(format, format.width - count_unsigned(nb, 10));
	}
	else
	{
		set_filler(format, format.width - count_unsigned(nb, 10));
		_ft_putnbr(nb);
	}
	return max(format.width, count_unsigned(nb, 10));
}
