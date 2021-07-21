#include "libft.h"

unsigned int	ft_putchar(char simbol)
{
	write(1, &simbol, 1);
	return (1);
}
