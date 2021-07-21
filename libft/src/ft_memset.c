#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	if (b && len)
	{
		ptr = (unsigned char *)b;
		while (len--)
		{
			*ptr = (unsigned char)c;
			ptr++;
		}
	}
	return (b);
}
