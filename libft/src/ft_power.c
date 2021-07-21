#include "libft.h"

long long	ft_power(long long base, unsigned int power)
{
	if (power == 0)
		return (1);
	base *= ft_power(base, power - 1);
	return (base);
}
