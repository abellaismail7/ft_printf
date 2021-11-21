/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:15:08 by iait-bel          #+#    #+#             */
/*   Updated: 2021/11/21 20:15:30 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NBR_H
# define FT_NBR_H

# include "ft_ds.h"

int	put_nbr(t_format *format, int value);
int	put_float(t_format *format, double value);
int	put_addr(t_format *format, unsigned long long addr);
int	put_hex(t_format *format, int nb, int is_upp);
int	put_udec(t_format *format, unsigned int nb);
int	_ft_putnbr(unsigned int nb);

#endif
