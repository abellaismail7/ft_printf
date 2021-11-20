#ifndef FT_STR_H
# define FT_STR_H

#include "ft_ds.h"
int ft_strncmp(char *s1, char *s2, unsigned int n);
int ft_strlen(char *str);
int	put_char(t_format format, int c);
int	put_fstr(t_format format, char *str);
int	put_what(t_format format);

#endif
