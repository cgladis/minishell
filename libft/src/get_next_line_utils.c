#include "get_next_line.h"

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*str;

	str = (char *)malloc((ft_gnl_strlen(s1) + ft_gnl_strlen(s2) + 1)
			* sizeof(char));
	if (!str)
		return (NULL);
	ft_gnl_strlcpy(str, s1, ft_gnl_strlen(s1) + 1);
	ft_gnl_strlcat(str, s2, ft_gnl_strlen(s1) + ft_gnl_strlen(s2) + 1);
	free(s1);
	return (str);
}

unsigned long long	ft_gnl_strlen(const char *s)
{
	unsigned long long	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_gnl_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	rez;

	if (!dst || !src)
		return (0);
	rez = ft_gnl_strlen(src);
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

size_t	ft_gnl_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	rez;

	if (!dst || !src)
		return (0);
	if (!dstsize)
		return (ft_gnl_strlen(src));
	len_dst = ft_gnl_strlen(dst);
	len_src = ft_gnl_strlen(src);
	if (len_dst >= dstsize)
		return (len_src + dstsize);
	else
	{
		rez = dstsize - len_dst - 1;
		if (rez > len_src)
			rez = len_src;
		dst = dst + len_dst;
		ft_gnl_memcpy(dst, src, rez);
		dst[rez] = '\0';
	}
	return (len_dst + len_src);
}

void	*ft_gnl_memcpy(void *dst, const void *src, size_t n)
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
