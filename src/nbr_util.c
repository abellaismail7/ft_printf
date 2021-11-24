/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:45:00 by iait-bel          #+#    #+#             */
/*   Updated: 2021/11/21 17:45:00 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ds.h"
#include "util.h"
#include "ft_extra.h"
#include <unistd.h>

int	count_base(int nb, int base)
{
	int	count;

	count = (nb <= 0);
	while (nb)
	{
		nb /= base;
		count++;
	}
	return (count);
}

int	count_unsigned(unsigned long long nb, int base)
{
	int	count;

	count = (nb == 0);
	while (nb)
	{
		nb /= base;
		count++;
	}
	return (count);
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
	return (count_base(nb, 10));
}

void	__ft_putnbr(t_format *format, unsigned int nb)
{
	int	size;

	size = count_unsigned(nb, 10);
	if (format->precision != -1 && format->precision >= size)
	{
		filler('0', format->precision - size);
		size = format->precision;
	}
	_ft_putnbr(nb);
}

int	_put_hex(t_format *format, unsigned long long *val)
{
	int					i;
	int					count;
	int					ignore_zero;
	unsigned long long	nb;

	nb = *val;
	i = 0;
	count = 0;
	if (format->specifier == 'p' || (nb && format->flags & ALTERNATE_FORM))
		i = 2;
	write(1, ("0x0X") + (2 * (format->specifier == 'X')), 2 * (i > 0));
	count += count_unsigned(nb, 16) - (!format->precision && !nb);
	filler('0', format->precision - count);
	count += i;
	i = 16 * 4;
	ignore_zero = 1;
	while (i)
	{
		get_hex(nb, &i, &ignore_zero, format->specifier == 'X');
	}
	write(1, "0", ignore_zero && format->precision != 0);
	return (count);
}
