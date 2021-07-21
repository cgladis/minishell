#include "libft.h"

static int	my_putnbr(long n)
{
	char	simbol;
	int		count;

	count = 0;
	if (n > 9)
		count = my_putnbr(n / 10);
	simbol = n % 10 + '0';
	write(1, &simbol, 1);
	count += 1;
	return (count);
}

unsigned int	ft_putnbr(long long n)
{
	int	count;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		count += 1;
		n = -n;
	}
	count += my_putnbr(n);
	return (count);
}
