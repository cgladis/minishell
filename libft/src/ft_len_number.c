#include "libft.h"

unsigned int	ft_len_number(unsigned int base, unsigned long long number)
{
	unsigned int	length;

	length = 1;
	while (number / base)
	{
		number = number / base;
		length++;
	}
	return (length);
}
