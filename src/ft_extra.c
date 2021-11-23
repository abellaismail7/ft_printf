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

#include <unistd.h>

void get_hex(unsigned long long nb, int *i, int *ignore_zero, int is_upp)
{
	char c;
	char a[] = "0123456789abcdef";
	char A[] = "0123456789ABCDEF";

	*i -= 4;
	c = (nb >> *i) & 0xf;
	if (*ignore_zero && c == 0)
		return ;
	if(is_upp)
		*ignore_zero = ! write(1, A + c, 1);
	else
		*ignore_zero = ! write(1, a + c, 1);
}
