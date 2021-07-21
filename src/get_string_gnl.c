#include "minishell.h"

void	get_string(char *stop_world)
{
	char	*current_str;
	int		fd;

	fd = open(".tmp", O_CREAT | O_WRONLY | O_TRUNC, 00777);
	current_str = ft_strdup("");
	while (ft_strncmp(current_str, stop_world, ft_strlen(stop_world) + 1))
	{
		free(current_str);
		current_str = my_readline(ft_strdup(""), "heredoc> ");
		if (!ft_strncmp(current_str, stop_world,
				ft_strlen(stop_world) + 1))
			continue ;
		write(fd, current_str, ft_strlen(current_str));
		write(fd, "\n", 1);
	}
	free(current_str);
	close(fd);
}
