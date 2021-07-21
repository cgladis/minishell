#include "libft.h"

int	find_char(char const *search_string, char c)
{
	int	count;

	count = 1;
	while (*search_string)
	{
		if (*search_string == c)
			return (count);
		search_string++;
		count++;
	}
	return (0);
}

char	*ft_strstr(const char *s, const char *separator)
{
	char	*ptr;

	if (!s)
		return (NULL);
	if (*separator == '\0')
		return ((char *)s);
	ptr = (char *)s;
	while (*ptr)
	{
		if (find_char(separator, *ptr))
			return (ptr);
		ptr++;
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	if (!s)
		return (NULL);
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr++;
	}
	if (c == '\0')
		return (ptr);
	return (NULL);
}
