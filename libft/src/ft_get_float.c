#include "libft.h"

static int	round_n(long double n)
{
	if ((int)(n * 10) % 10 >= 5)
		return (1);
	else
		return (0);
}

static int	round_n2(long double n, int i)
{
	if ((int)n + i > 9)
		return (1);
	else
		return (0);
}

static int	get_nbr_and_hvost(int length, int precision_and_length,
				long double n, char *nbr)
{
	int	i;

	if (precision_and_length)
	{
		if (!length)
		{
			*nbr = '.';
			nbr++;
		}
		i = get_nbr_and_hvost(length - 1, precision_and_length - 1,
				(n - (int)n) * 10, nbr + 1);
		*nbr = get_simbol(((int)n + i) % 10);
		return (round_n2(n, i));
	}
	if (!length)
	{
		*nbr = '.';
		nbr++;
	}
	i = round_n(n);
	*nbr = get_simbol(((int)n + i) % 10);
	return (round_n2(n, i));
}

static char	*get_nbr(int length, int precision, long double n)
{
	char	*nbr;
	char	*nbr1;

	nbr = malloc(sizeof (char ) * length + precision + 1 + (precision != 0));
	nbr[length + precision + (precision != 0)] = '\0';
	if (get_nbr_and_hvost(length, precision + length - 1, n, nbr))
	{
		nbr1 = ft_strjoin("1", nbr);
		free(nbr);
		return (nbr1);
	}
	return (nbr);
}

char	*ft_get_float(long double nbr, int precision)
{
	unsigned int	len;

	if (precision < 0)
		precision = 0;
	len = 1;
	while (nbr >= 10)
	{
		nbr /= 10;
		len++;
	}
	return (get_nbr(len, precision, nbr));
}
