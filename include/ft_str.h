/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:15:43 by iait-bel          #+#    #+#             */
/*   Updated: 2021/11/21 20:16:00 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

# include "ft_ds.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n);
int	ft_strlen(char *str);
int	put_char(t_format *format, int c);
int	put_fstr(t_format *format, char *str);
int	put_what(t_format *format);

#endif
