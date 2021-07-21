#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char					*ptr;
	unsigned long long		length;

	length = ft_strlen(s1) + 1;
	ptr = (char *)malloc(sizeof(char) * length);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, length);
	return (ptr);
}
