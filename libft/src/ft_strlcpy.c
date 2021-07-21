#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	rez;

	if (!dst || !src)
		return (0);
	rez = ft_strlen(src);
	if (!dstsize--)
		return (rez);
	while (*src && dstsize--)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*(dst) = '\0';
	return (rez);
}

size_t	ft_strw_lcpy(wchar_t *dst, const wchar_t *src, size_t dstsize)
{
	size_t	rez;

	if (!dst || !src)
		return (0);
	rez = ft_strw_len(src);
	if (!dstsize--)
		return (rez);
	while (*src && dstsize--)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*(dst) = '\0';
	return (rez);
}
