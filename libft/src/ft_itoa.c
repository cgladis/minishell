#include "libft.h"

static char	*ft_addchar(char *str, char ch)
{
	size_t	len;

	len = ft_strlen(str);
	str[len] = ch;
	str[len + 1] = '\0';
	return (str);
}

static char	*ft_itoa_rev(char *str, long n)
{
	if (n > 9)
	{
		str = ft_itoa_rev(str, n / 10);
		str = ft_addchar(str, n % 10 + '0');
		return (str);
	}
	str = ft_addchar(str, n % 10 + '0');
	return (str);
}

static char	*ft_init_itoa(int len, long n)
{
	char	*str;

	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str = ft_itoa_rev(str, n);
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	long	tmp;

	len = 1;
	if (n < 0)
	{
		len++;
		tmp = -n;
	}
	else
		tmp = n;
	while (tmp > 9)
	{
		tmp = tmp / 10;
		len++;
	}
	return (ft_init_itoa(len, n));
}
