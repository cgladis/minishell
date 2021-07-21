#include "minishell.h"

int	try_execve(char **path, char **command, char **envp)
{
	char	*path_part;
	char	*command_name;

	command_name = ft_strdup(*command);
	if (check_build_in(command, envp) != -1)
	{
		free(command_name);
		return (0);
	}
	while (*path)
	{
		if (*(*path + (int)ft_strlen(*path)) != '/' && **path != '\0')
			path_part = ft_cont_str_and_free(ft_strdup(*path),
					ft_strdup("/"), NULL);
		else
			path_part = ft_strdup(*path);
		*command = ft_cont_str_and_free(path_part, *command, NULL);
		execve(*command, command, envp);
		change_str(&*command, command_name);
		path++;
	}
	change_str(&*command, command_name);
	free(command_name);
	errno = 127;
	return (-1);
}

static void	run_pipes_add(int *fd_current, int *fd_previous)
{
	if (g_vars.pipe_now == 3)
	{
		close(fd_current[1]);
		dup2(fd_current[0], STDIN);
		close(fd_current[0]);
	}
	else if (g_vars.pipe_now == 1)
	{
		close(fd_current[0]);
		dup2(fd_current[1], STDOUT);
		close(fd_current[1]);
	}
	else if (g_vars.pipe_now == 2)
	{
		dup2(fd_previous[0], STDIN);
		close(fd_current[0]);
		dup2(fd_current[1], STDOUT);
		close(fd_current[1]);
	}
}

void	run_pipes(void)
{
	int	*fd_current;
	int	*fd_previous;

	fd_previous = NULL;
	if (g_vars.pipe_now == 0)
		return ;
	fd_current = ft_lst2last(g_vars.pipes)->content;
	if (ft_len_lst2(g_vars.pipes) > 1)
		fd_previous = ft_lst2last(g_vars.pipes)->previous->content;
	run_pipes_add(fd_current, fd_previous);
}

//void	init_ch_red(int *fd, t_list2 **current_token, t_list2 **token)
//{
//	*fd = 0;
//	*current_token = *token;
//}
