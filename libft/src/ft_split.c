#include "libft.h"

static char	**getaaray(char **str, char const *s, char const *separator)
{
	char	*ptr;

	while (ft_strstr(s, separator))
	{
		ptr = ft_strstr(s, separator);
		if (ptr - s == 0 && *s != '\0')
			s++;
		else
		{
			if (*s == '\0')
				break ;
			str = ft_add_str_and_free_str1_str2(str, ft_substr(s, 0, ptr - s));
			if (*ptr != '\0')
				s = s + (ptr - s) + 1;
			else
				s = ptr;
		}
	}
	if (*s)
		str = ft_add_str_and_free_str1(str, (char *)s);
	return (str);
}

char	**ft_split(char *s, char const *separator)
{
	char	**str;

	if (!s)
		return (NULL);
	str = NULL;
	str = getaaray(str, s, separator);
	if (!(str))
		return (NULL);
	return (str);
}
