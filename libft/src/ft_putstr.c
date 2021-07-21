#include "libft.h"

unsigned int	ft_putstr(char *str)
{
	unsigned int	length;

	if (str)
	{
		length = ft_strlen(str);
		if (length > 0)
		{
			write(1, str, length);
			return (length);
		}
	}
	return (0);
}
