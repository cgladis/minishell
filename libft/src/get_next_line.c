#include "get_next_line.h"
#include "libft.h"

static int	next_line(char **temp_str, char **str, char **line)
{
	unsigned long long	index_simbol;

	index_simbol = find_char(*temp_str, '\n');
	if (index_simbol)
	{
		*(*temp_str + index_simbol - 1) = '\0';
		*line = ft_gnl_strjoin(*line, *temp_str);
		*str = ft_strdup(*temp_str + index_simbol);
		free(*temp_str);
		return (1);
	}
	else
	{
		*line = ft_gnl_strjoin(*line, *temp_str);
		free(*str);
		*str = NULL;
	}
	return (0);
}

static int	check_ret(int ret, char **line)
{
	if (ret < 0)
	{
		free(*line);
		*line = NULL;
		return (1);
	}
	return (0);
}

void	get_next_line_sub(char **temp_str, int *ret, int fd)
{
	*temp_str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	*ret = read(fd, *temp_str, BUFFER_SIZE);
}

int	get_next_line(int fd, char **line)
{
	static char	*str[5000];
	char		*temp_str;
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (-1);
	*line = ft_strdup("\0");
	if (str[fd])
	{
		temp_str = str[fd];
		if (next_line(&temp_str, &str[fd], line))
			return (1);
	}
	get_next_line_sub(&temp_str, &ret, fd);
	while (ret > 0)
	{
		*(temp_str + ret) = '\0';
		if (next_line(&temp_str, &str[fd], line))
			return (1);
		ret = read(fd, temp_str, BUFFER_SIZE);
	}
	free(temp_str);
	if (check_ret(ret, line))
		return (-1);
	return (0);
}
