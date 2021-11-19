#include <stdarg.h>
#include "ft_expr.h"
#include "ft_ds.h"

void ft_printf(char *format, ...) 
{
    va_list args;
    char *str;
    t_format d_format;
   
    va_start(args, format);
    str = format;
    while(*(str = put_str(str)))
    {
	    d_format.precision = -1;
        str = parse_exp(str+1, &d_format, args);
        put_exp(d_format, args);
    }
}
