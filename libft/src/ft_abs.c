#include "libft.h"

long double	ft_abs(long double nomber)
{
	if (nomber < 0)
		nomber = -nomber;
	return (nomber);
}
