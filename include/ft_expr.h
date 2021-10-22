#ifndef FT_EXPR_H
# define FT_EXPR_H

# include "ft_ds.h"
#include <stdarg.h>

char	    *put_str(char *str);
int         next_exp(char **exp);
char        *parse_exp(char *exp,t_format *format, va_list list);
void	    put_exp(t_format format, va_list list);
#endif
