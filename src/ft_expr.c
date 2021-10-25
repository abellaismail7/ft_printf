#include <stdarg.h>
#include <unistd.h>
#include "ft_ds.h"
#include "ft_str.h"
#include "ft_nbr.h"

char *g_modifiers[] = {"hh", "h", "l", "ll", "q", "L", "j", "z", "Z", "t"};
void	    about_exp(t_format format, va_list list);

char	    *put_str(char *str)
{
    int i;

    i = 0;
    while(str[i] && str[i] != '%')
        i++;
    write(1, str, i);
    return str + i;
}

char*   parse_flags(char *exp, unsigned short *flags)
{
    char c;
    *flags = 0;
    while(*exp)
    {
        c = *exp;
        if(c == '#')
            *flags |= ALTERNATE_FORM;
        else if(c == '0')
            *flags |= FILLER;
        else if(c == '-')
            *flags |= ADJUSTLEFT;
        else if(c == ' ')
            *flags |= FORCE_SPACE;
        else if(c == '+')
            *flags |= FORCE_SIGN;
        else 
            break ;
        exp++;
    }
    return exp;
}

char*   parse_var(char *exp, int *dest)
{
    int res;

    res = 0;
    while(*exp >= '1' && *exp <= '9')
    {
        res *= 10;
        res += *exp - '0';
        exp++;
    }

    *dest = res;
    return exp;
}

char*   parse_exp(char *exp, t_format *format, va_list list)
{
    int i;
    int len;
    
    (void) list;
    i = 0;
    exp = parse_flags(exp, &format->flags);
    exp = parse_var(exp, &format->width);
    if(*exp == '.')
    {
        exp++;
        exp = parse_var(exp, &format->precision);
    }
    while(i < 10)
    {
        len = ft_strlen(g_modifiers[i]);
        
        if(ft_strncmp(exp, g_modifiers[i], len) == 0)
        {
            format->lenght_modifier = i; 
            exp += len;
            break ;
        }
        i++;
    }
    format->specifier = *exp;
    return exp + 1;
}

void	put_exp(t_format format, va_list list)
{
	if(format.specifier == 'd')
	{
		int d = va_arg(list, int);
		put_nbr(format, d);
	}
	else if(format.specifier == 'f')
	{
		float d = va_arg(list, double);
		put_float(format, d);
	}
	//about_exp(format,list);
}

#include<stdio.h>
void	    about_exp(t_format format, va_list list)
{
    (void) list;

    puts("====================");
    printf("alternate_form: %d\n", format.flags & ALTERNATE_FORM);
    printf("filler        : %d\n", format.flags & FILLER);
    printf("adjustement   : %d\n", format.flags & ADJUSTLEFT);
    printf("force_space   : %d\n", format.flags & FORCE_SPACE);
    printf("force_sign    : %d\n", format.flags & FORCE_SIGN);

    puts("");

    printf("width          : %d\n", format.width);
    printf("precision      : %d\n", format.precision);
    printf("lenght_modifier: %d\n", format.lenght_modifier);
    printf("specifier      : %d\n", format.specifier);
    puts("");
}
