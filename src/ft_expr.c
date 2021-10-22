#include <stdarg.h>
#include <unistd.h>
#include "ft_ds.h"
#include "ft_str.h"

char *g_modifiers[] = {"hh", "h", "l", "ll", "q", "L", "j", "z", "Z", "t"};
char	    *put_str(char *str)
{
    int i;

    i = 0;
    while(str[i] && str[i] != '%')
        i++;
    write(1, str, i);
    return str + i;
}

char*   parse_flags(char *exp, t_flags *flags)
{
    char c;
    flags->alternate_form = 0;
    flags->filler         = ' ';
    flags->adjustement    = RIGHT;
    flags->force_space    = 0;
    flags->force_sign     = 1;
    while(*exp)
    {
        c = *exp;
        if(c == '#')
            flags->alternate_form = 1;
        else if(c == '0')
            flags->filler      = c;
        else if(c == '-')
            flags->adjustement = LEFT; 
        else if(c == ' ')
            flags->force_space = 1;
        else if(c == '+')
            flags->force_sign  = 1;
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

#include<stdio.h>
void	    put_exp(t_format format, va_list list)
{
    (void) list;

    puts("====================");
    printf("alternate_form: %d\n", format.flags.alternate_form);
    printf("filler        : %d\n", format.flags.filler);
    printf("adjustement   : %d\n", format.flags.adjustement);
    printf("force_space   : %d\n", format.flags.force_space);
    printf("force_sign    : %d\n", format.flags.force_sign);

    puts("");

    printf("width          : %d\n", format.width);
    printf("precision      : %d\n", format.precision);
    printf("lenght_modifier: %d\n", format.lenght_modifier);
    printf("specifier      : %d\n", format.specifier);
    puts("");
}
