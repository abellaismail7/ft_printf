/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 23:40:03 by iait-bel          #+#    #+#             */
/*   Updated: 2021/11/23 23:40:03 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ds.h"
#include <unistd.h>

int	is_number(t_format *format)
{
	char	sp;

	sp = format->specifier;
	return (sp == 'x' || sp == 'X' || sp == 'd'
		|| sp == 'i' || sp == 'p' || sp == 'u');
}

void	get_hex(unsigned long long nb, int *i, int *ignore_zero, int is_upp)
{
	char	c;
	char	*a;

	a = "0123456789abcdef";
	if (is_upp)
		a = "0123456789ABCDEF";
	*i -= 4;
	c = (nb >> *i) & 0xf;
	if (*ignore_zero && c == 0)
		return ;
	*ignore_zero = ! write(1, a + c, 1);
}
