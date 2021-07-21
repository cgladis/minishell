#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (!dst || !src)
		return (NULL);
	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	if (&ptr1[len] < &ptr2[len])
	{
		while (len--)
		{
			*ptr1 = *ptr2;
			ptr1++;
			ptr2++;
		}
	}
	else
		while (len--)
			ptr1[len] = ptr2[len];
	return (dst);
}
