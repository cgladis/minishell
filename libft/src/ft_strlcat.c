#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	rez;

	if (!dst || !src)
		return (0);
	if (!dstsize)
		return (ft_strlen(src));
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dst >= dstsize)
		return (len_src + dstsize);
	else
	{
		rez = dstsize - len_dst - 1;
		if (rez > len_src)
			rez = len_src;
		dst = dst + len_dst;
		ft_memcpy(dst, src, rez);
		dst[rez] = '\0';
	}
	return (len_dst + len_src);
}
