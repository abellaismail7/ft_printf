/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:50:47 by iait-bel          #+#    #+#             */
/*   Updated: 2021/11/21 19:50:47 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ds.h"
#include "ft_str.h"
#include "nbr_util.h"
#include "util.h"
#include <unistd.h>

void	_putnbr(t_format *format, void *val)
{
	int	size;
	int	nb;	

	nb = *((int *)val);
	write(1, "+", (nb >= 0 && (format->flags & FORCE_SIGN) > 0));
	write(1, " ", (nb >= 0 && (format->flags & FORCE_SPACE) > 0));
	if (nb < 0)
	{
		write(1, "-", (!(format->flags & FILLZERO)));
		if ((1 << (sizeof(int) * 8 - 1)) == nb)
		{
			_ft_putnbr(nb / 10 * -1);
			_ft_putnbr(nb % 10 * -1);
			return ;
		}
		nb = nb * -1;
	}
	size = count_base(nb, 10);
	if (format->precision != -1 && format->precision >= size)
	{
		filler('0', format->precision - size);
		size = format->precision;
	}
	_ft_putnbr(nb);
}

int	put_nbr(t_format *format, int nb)
{
	int	size;
	int	has_sign;

	size = nb <= 0;
	has_sign = 0;
	if (nb == 0 && format->precision == 0)
		return (put_fstr(format, ""));
	write(1, "-", (nb < 0 && (format->flags & FILLZERO)));
	if (nb >= 0)
	{
		has_sign = (format->flags & FORCE_SIGN);
		has_sign = (has_sign || (format->flags & FORCE_SPACE));
	}
	size = count_base(nb, 10) + has_sign;
	size = max(size, format->precision + (nb < 0) + has_sign);
	filler_setter(_putnbr, format, &nb, size);
	return (max(size, format->width));
}

int	put_hex(t_format *format, unsigned long long nb)
{
	int	hex_size;

	hex_size = !!(format->flags & ALTERNATE_FORM) * 2;
	if (!nb && format->specifier != 'p')
		hex_size = 0;
	if ((format->flags & FILLZERO)
		&& (format->width < format->precision || format->precision == -1))
	{
		format->precision = max(format->precision, format->width - hex_size);
		format->precision = max(count_unsigned(nb, 16), format->precision);
		format->width = 0;
	}
	else
	{
		format->precision = max(count_unsigned(nb, 16), format->precision);
		format->width = format->width - format->precision - hex_size ;
		format->width *= (format->width > 0);
	}
	filler_setter(_put_hex, format, &nb, 0);
	return (format->width + hex_size + format->precision);
}

int	put_addr(t_format *format, unsigned long long nb)
{
	format->flags |= ALTERNATE_FORM;
	return (put_hex(format, nb));
}

int	put_udec(t_format *format, unsigned int nb)
{
	int	size;

	if (nb == 0 && format->precision == 0)
		return (put_fstr(format, ""));
	size = max(count_unsigned(nb, 10), format->precision);
	if (format->flags & ADJUSTLEFT)
	{
		__ft_putnbr(format, nb);
		set_filler(format, format->width - size);
	}
	else
	{
		set_filler(format, format->width - size);
		__ft_putnbr(format, nb);
	}
	return (max(format->width, size));
}
