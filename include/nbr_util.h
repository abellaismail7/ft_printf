/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:16:13 by iait-bel          #+#    #+#             */
/*   Updated: 2021/11/21 20:17:43 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NBR_UTIL_H
# define NBR_UTIL_H

# include "ft_ds.h"

int	_ft_putnbr(unsigned int nb);
int	count_unsigned(unsigned long long nb, int base);
int	count_base(int nb, int base);
void	__ft_putnbr(t_format *format, unsigned int nb);
int	_put_hex(t_format *format, unsigned long long nb, int is_upp);

#endif 
