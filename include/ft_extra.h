/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:28:55 by iait-bel          #+#    #+#             */
/*   Updated: 2021/11/24 11:28:55 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ds.h"

#ifndef FT_EXTRA_H
# define FT_EXTRA_H

#include "ft_ds.h"
void	get_hex(unsigned long long nb, int *i, int *ignore_zero, int is_upp);
int is_number(t_format *format);

#endif
