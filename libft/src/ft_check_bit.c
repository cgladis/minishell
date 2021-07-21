#include "libft.h"

int	ft_check_bit(double number, int position)
{
	int					result;
	unsigned long long	*ptr;

	if (position > 127 || position < 0)
		return (0);
	ptr = (unsigned long long *)&number;
	result = (*ptr & ((unsigned long long)1 << position)) != 0;
	return (result);
}
