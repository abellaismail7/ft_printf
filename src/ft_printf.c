#include <stdarg.h>
#include <unistd.h>
#include "ft_expr.h"
#include "util.h"
#include "ft_ds.h"

int ft_printf(char *format, ...) 
{
    va_list args;
    char *str;
    t_format d_format;
    int counter;
    int tmp;
   
    va_start(args, format);
    str = format;
    counter = 0;
    while(1)
    {
        tmp = put_str(str);
        counter += tmp;
        str += tmp;
        if(*str == 0)
            break;
        clear_format(&d_format);
        str = parse_exp(str+1, &d_format);
        counter += put_exp(&d_format, args);
    }
    return counter;
}
