/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:40:13 by iait-bel          #+#    #+#             */
/*   Updated: 2021/11/21 19:40:13 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_ds.h"
#include "ft_str.h"
#include "ft_nbr.h"
#include "util.h"

int	put_str(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	write(1, str, i);
	return (i);
}

const char	*parse_flags(const char *exp, unsigned short *flags)
{
	char	c;

	*flags = 0;
	while (*exp)
	{
		c = *exp;
		if (c == '#')
			*flags |= ALTERNATE_FORM;
		else if (c == '0')
			*flags |= FILLZERO;
		else if (c == '-')
			*flags |= ADJUSTLEFT;
		else if (c == ' ')
			*flags |= FORCE_SPACE;
		else if (c == '+')
			*flags |= FORCE_SIGN;
		else
			break ;
		exp++;
	}
	if (*flags & ADJUSTLEFT)
		*flags &= ~FILLZERO;
	if (*flags & FORCE_SIGN)
		*flags &= ~FORCE_SPACE;
	return (exp);
}

const char	*parse_var(const char *exp, int *dest)
{
	int	res;

	res = 0;
	while (*exp >= '0' && *exp <= '9')
	{
		res *= 10;
		res += *exp - '0';
		exp++;
	}
	*dest = res;
	return (exp);
}

const char	*parse_exp(const char *exp, t_format *format)
{
	exp = parse_flags(exp, &format->flags);
	exp = parse_var(exp, &format->width);
	if (*exp == '.')
	{
		exp++;
		exp = parse_var(exp, &format->precision);
	}
	format->specifier = *exp;
	return (exp + 1);
}

int	put_exp(t_format *format, va_list list)
{
	int	sp;
	int	count;

	count = 0;
	sp = format->specifier;
	if (sp == 'd' || sp == 'i')
		count = put_nbr(format, va_arg(list, int));
	else if (sp == 'c')
		count = put_char(format, va_arg(list, int));
	else if (sp == 'p')
		count = put_addr(format, va_arg(list, unsigned long long));
	else if (sp == 's')
		count = put_fstr(format, va_arg(list, char *));
	else if (sp == 'u')
		count = put_udec(format, va_arg(list, unsigned int));
	else if (sp == 'x' || sp == 'X')
		count = put_hex(format, va_arg(list, unsigned long long));
	else
		count = put_what(format);
	return (count);
}
