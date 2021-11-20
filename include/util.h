#ifndef UTIL_H
# define UTIL_H

#include "ft_ds.h"

void    filler(char c, int times);
void	set_filler(t_format format, int len);
int     count_base(int nb, int base);
int     has_flag(t_format format, int flag);
void    clear_format(t_format *format);
char	*ft_strchr(const char *s, int c);
int max(int a, int b);
int count_unsigned(unsigned long long nb, int base);
void filler_setter(void(*f)(t_format, void *), t_format format, void *value, int len);


#endif
