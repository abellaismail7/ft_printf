/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 10:35:59 by iait-bel          #+#    #+#             */
/*   Updated: 2021/11/20 10:35:59 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ds.h"
#include "ft_nbr.h"
#include "util.h"
#include "str_util.h"
#include "unistd.h"

int	put_char(t_format *format, int c)
{
	if (format->flags & ADJUSTLEFT)
	{
		write(1, &c, 1);
		set_filler(format, format->width - 1);
	}
	else
	{
		set_filler(format, format->width - 1);
		write(1, &c, 1);
	}
	return (max(format->width, 1));
}

void	put_mystr(t_format *format, void *str)
{
	int	len;

	len = ft_strlen(str);
	if (format->precision != -1 && format->precision < len)
		len = format->precision;
	write(1, str, len);
}

int	put_fstr(t_format *format, char *str)
{
	int	len;

	len = 6;
	if (format->precision != -1 && format->precision < len)
		len = format->precision;
	if (str == 0)
	{
		filler_setter(put_mystr, format, "(null)", len);
		return (max(len, format->width));
	}
	len = ft_strlen(str);
	if (format->precision != -1 && format->precision < len)
		len = format->precision;
	filler_setter(put_mystr, format, str, len);
	return (max(format->width, len));
}

int	put_what(t_format *format)
{
	write(1, &(format->specifier), 1);
	return (1);
}
