/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:52:35 by iait-bel          #+#    #+#             */
/*   Updated: 2021/11/24 11:52:35 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	const char *fmt = "ismail: %0#- +1.1@@ %u % d %# X %11s %9 \n";
	int ret;
	fflush(stdout);

	puts("===== test i  ====");
	fflush(stdout);
	fmt = " %-0x";
	ret = ft_printf(fmt, 0);
	printf("(%d)\n", ret);
	ret = printf(fmt, 0);
	printf("(%d)\n", ret);
	fflush(stdout);
}
