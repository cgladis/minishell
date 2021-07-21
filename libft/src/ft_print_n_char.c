#include "libft.h"

unsigned int	ft_print_n_char(unsigned int n, char simbol)
{
	unsigned int	i;

	i = 0;
	while (n--)
	{
		ft_putchar(simbol);
		i++;
	}
	return (i);
}
