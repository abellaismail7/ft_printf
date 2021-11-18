#ifndef FT_NBR_H
# define FT_NBR_H

# include "ft_ds.h"
void    put_nbr(t_format format, int value);
void    put_float(t_format format, double value);
void	put_addr(t_format format, unsigned long long addr);
void    put_hex(t_format format, int nb, int is_upp);
void    put_udec(t_format format, unsigned int nb);
#endif
