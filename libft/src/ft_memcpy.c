#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (dst && src && n)
	{
		ptr1 = (unsigned char *)dst;
		ptr2 = (unsigned char *)src;
		while (n--)
		{
			*ptr1 = *ptr2;
			ptr1++;
			ptr2++;
		}
	}
	return (dst);
}
