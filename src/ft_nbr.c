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
#include "nbr_util.h"

void _putnbr(t_format format, int nb)
{
	int size;

	if(nb >= 0)
	{
		write(1, "+", (format.flags & FORCE_SIGN) > 0 );
		write(1, " ", (format.flags & FORCE_SPACE) > 0);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		if ((1 << (sizeof(int) * 8 - 1)) == nb)
		{
			_ft_putnbr(nb / 10 * -1);
			_ft_putnbr(nb % 10 * -1);
			return ;
		}
		nb = nb * -1;
	}
	size = count_base(nb, 10);
	if(format.precision != -1 && format.precision >= size)
	{
		filler('0', format.precision - size);
		size = format.precision;
	}
	_ft_putnbr(nb);
}

int    put_nbr(t_format format, int nb)
{
	int size;

	size = nb <= 0;
	if(nb == 0 && format.precision == 0)
		return size;
	size += count_base(nb, 10) - (nb <= 0);
	size = max(size, format.precision + (nb < 0));
	if (format.flags & ADJUSTLEFT)
	{
		_putnbr(format, nb);
		set_filler(format, format.width - size);
	}
	else
	{
		set_filler(format, format.width - size);
		_putnbr(format, nb);
	}
	return max(size, format.width);
}

int	put_hex(t_format format, unsigned long long nb, int is_upp)
{
	int count;
	int i;

	i = 0;
	if (format.flags & ALTERNATE_FORM)
		i = 2;
	if (format.flags & ADJUSTLEFT)
	{
		count = _put_hex(format, nb, is_upp);
		set_filler(format, format.width - count_unsigned(nb, 16) - i);
	}
	else
	{
		set_filler(format, format.width - count_unsigned(nb, 16) - i);
		count = _put_hex(format, nb, is_upp);
	}
	return max(format.width, count);
}

int put_addr(t_format format, unsigned long long nb)
{
	format.flags |= ALTERNATE_FORM;
	return put_hex(format, nb, 0);
}

int put_udec(t_format format, unsigned int nb)
{
	int size;

	size = count_unsigned(nb, 10);
	if (format.flags & ADJUSTLEFT)
	{
		size = __ft_putnbr(format, nb, size);
		set_filler(format, format.width - size);
	}
	else
	{
		set_filler(format, format.width - size);
		size = __ft_putnbr(format, nb, size);
	}
	return max(format.width, size);
}
