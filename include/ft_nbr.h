#ifndef FT_NBR_H
# define FT_NBR_H

# include "ft_ds.h"
int     put_nbr(t_format *format, int value);
int     put_float(t_format *format, double value);
int     put_addr(t_format *format, unsigned long long addr);
int     put_hex(t_format *format, int nb, int is_upp);
int     put_udec(t_format *format, unsigned int nb);
int     _ft_putnbr(unsigned int nb);

#endif
