#include "ft_ds.h"
#include "ft_nbr.h"
#include "util.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;
	int	j;

	if (n == 0)
		return (0);
	i = 0;
	j = n - 1;
	while (s1[i] && s1[i] == s2[i] && i < j)
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}


int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

#include "unistd.h"
int	put_char(t_format format, int c)
{
	if (format.flags & ADJUSTLEFT) {
		write(1, &c, 1); // test !printable
		set_filler(format, format.width - 1); 
	}
	else
	{
		set_filler(format, format.width - 1); 
		write(1, &c, 1);
	}
	return max(format.width, 1);
}

int	put_fstr(t_format format, char *str)
{
	int len;

	if (str == 0)
		return write(1, "(null)", 6);

	format.flags &= ~FILLZERO;
	len = ft_strlen(str);
	if(format.precision != -1 && format.precision < len)
		len = format.precision;
	if (format.flags & ADJUSTLEFT) {
		write(1, str, len);
		set_filler(format, format.width - len); 
	}
	else
	{
		set_filler(format, format.width - len); 
		write(1, str, len);
	}
	return max(format.width, len) ;
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;
	char			*str;

	str = (char *) s;
	uc = c;
	while (*str)
	{
		if (*str == uc)
			return (str);
		str++;
	}
	if (uc == 0)
		return (str);
	else
		return (0);
}

int put_what(t_format format)
{
	int i;

	i = 1;
	if(format.specifier == '%')
	{
		write(1, "%", 1);
		return 1;
	}
	write(1, "%", 1);
	if(format.flags & ALTERNATE_FORM)
		write(1, "#", (i++ > 0));

	if(format.flags & FORCE_SIGN)
		write(1, "+", (i++ > 0));
	else if(format.flags & FORCE_SPACE)
		write(1, " ", (i++ > 0));
	if(format.flags & ADJUSTLEFT)
		write(1, "-", (i++ > 0));
	else if(format.flags & FILLZERO)
		write(1, "0", (i++ > 0));

	if(format.width != 0)
		i += _ft_putnbr(format.width);
	if(format.precision != 0)
	{
		write(1, ".", 1);
		i += _ft_putnbr(format.precision);
	}
	write(1, &(format.specifier), 1);
	return ++i;
}
