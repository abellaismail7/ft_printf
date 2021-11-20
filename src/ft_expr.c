#include <stdarg.h>
#include <unistd.h>
#include "ft_ds.h"
#include "ft_str.h"
#include "ft_nbr.h"
#include "util.h"

void	about_exp(t_format format, va_list list);

int	put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	write(1, str, i);
	return i;
}

char	*parse_flags(char *exp, unsigned short *flags)
{
	char	c;

	*flags = 0;
	while (*exp)
	{
		c = *exp;
		if (c == '#')
			*flags |= ALTERNATE_FORM;
		else if (c == '0')
			*flags |= FILLZERO;
		else if (c == '-')
			*flags |= ADJUSTLEFT;
		else if (c == ' ')
			*flags |= FORCE_SPACE;
		else if (c == '+')
			*flags |= FORCE_SIGN;
		else
			break ;
		exp++;
	}
	return exp;
}

char	*parse_var(char *exp, int *dest)
{
	int	res;

	res = 0;
	while (*exp >= '0' && *exp <= '9')
	{
		res *= 10;
		res += *exp - '0';
		exp++;
	}
	*dest = res;
	return exp;
}

char	*parse_exp(char *exp, t_format *format)
{
	exp = parse_flags(exp, &format->flags);
	exp = parse_var(exp, &format->width);
	if (*exp == '.')
	{
		exp++;
		exp = parse_var(exp, &format->precision);
	}
	format->specifier = *exp;
	return exp + 1;
}

int	put_exp(t_format format, va_list list)
{
	int sp;
	int count;

	count = 0;
	sp = format.specifier;
	if (sp == 'd' || sp == 'i')
		count = put_nbr(format, va_arg(list, int));
	else if (sp == 'c')
		count = put_char(format, va_arg(list, int));
	else if (sp == 'p')
		count = put_addr(format, va_arg(list, unsigned long long));
	else if (sp == 's')
		count = put_fstr(format, va_arg(list, char *));
	else if (sp == 'u')
		count = put_udec(format, va_arg(list, unsigned int));
	else if (sp == 'x' || sp == 'X')
		count = put_hex(format, va_arg(list, unsigned long long), sp == 'X');
	else
		count = put_what(format);	
	return count;
}
