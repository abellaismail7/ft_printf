/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:12:48 by iait-bel          #+#    #+#             */
/*   Updated: 2021/11/21 20:14:55 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXPR_H
# define FT_EXPR_H

# include "ft_ds.h"
# include <stdarg.h>

int		put_str(char *str);
int		next_exp(char **exp);
char	*parse_exp(char *exp, t_format *format);
int		put_exp(t_format *format, va_list list);

#endif
