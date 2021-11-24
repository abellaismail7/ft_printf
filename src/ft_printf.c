/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:50:56 by iait-bel          #+#    #+#             */
/*   Updated: 2021/11/21 19:54:02 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_expr.h"
#include "util.h"
#include "ft_ds.h"

int	ft_printf(char *format, ...)
{
	va_list		args;
	char		*str;
	t_format	d_format;
	int			counter;
	int			tmp;

	va_start(args, format);
	str = format;
	counter = 0;
	while (1)
	{
		tmp = put_str(str);
		counter += tmp;
		str += tmp;
		if (*str == 0)
			break ;
		clear_format(&d_format);
		str = parse_exp(str + 1, &d_format);
		counter += put_exp(&d_format, args);
	}
	return (counter);
}
