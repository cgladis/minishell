#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (!dst || !src || !n)
		return (NULL);
	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	while (n--)
	{
		*ptr1 = *ptr2;
		if (*ptr2 == (unsigned char)c)
			return (ptr1 + 1);
		ptr1++;
		ptr2++;
	}
	return (NULL);
}
