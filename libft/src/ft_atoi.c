#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t		i;
	int			flag;
	long int	result;

	result = 0;
	flag = 0;
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		flag = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (flag)
		result = -result;
	return ((int)result);
}
