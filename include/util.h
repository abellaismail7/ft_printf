/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:08:00 by iait-bel          #+#    #+#             */
/*   Updated: 2021/11/21 20:20:45 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "ft_ds.h"

void	filler(char c, int times);
void	set_filler(t_format *format, int len);
void	clear_format(t_format *format);
void	filler_setter(void (*f)(t_format*, void *),
			t_format *format, void *value, int len);
char	*ft_strchr(const char *s, int c);

int		count_base(int nb, int base);
int		has_flag(t_format *format, int flag);
int		max(int a, int b);
int		count_unsigned(unsigned long long nb, int base);

#endif
