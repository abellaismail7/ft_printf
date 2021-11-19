
#include "ft_ds.h"
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
void	put_char(t_format format, int c)
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
}

void	put_fstr(t_format format, char *str)
{
	int len;
	format.flags &= ~FILLZERO;
	len = ft_strlen(str);
	if(format.precision != -1)
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
}

