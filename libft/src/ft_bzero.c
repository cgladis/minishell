#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	if (!s || !n)
		return ;
	ptr = (char *)s;
	while (n--)
	{
		*ptr = '\0';
		ptr++;
	}
}
