#include "libft.h"

unsigned long long	ft_strlen(const char *s)
{
	unsigned long long	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

unsigned long long	ft_strw_len(const wchar_t *s)
{
	unsigned long long	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
