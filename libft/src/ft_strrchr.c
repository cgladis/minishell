#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	if (!s)
		return (NULL);
	ptr = NULL;
	while (*s)
	{
		if (*s == (char)c)
			ptr = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (ptr);
}
