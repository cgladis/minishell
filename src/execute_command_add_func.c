#include "minishell.h"

void	change_str(char **dst, char *str)
{
	free(*dst);
	*dst = strdup(str);
}

int	check_pipe(t_list2 **token)
{
	int		*pipe_fd;
	int		check;
	t_list2	*current_token;

	current_token = *token;
	check = 0;
	if (!ft_strncmp(current_token->content, "|", 2))
	{
		pipe_fd = (int *) malloc(sizeof(int) * 2);
		pipe(pipe_fd);
		ft_lst2add_back(&g_vars.pipes, ft_lst2new(pipe_fd));
		check = 1;
		*token = current_token->next;
		if (g_vars.pipe_now == 0 || g_vars.pipe_now == 3)
			g_vars.pipe_now = 1;
		else
			g_vars.pipe_now = 2;
	}
	return (check);
}

int	check_build_in(char **argv, char **envp)
{
	if (!ft_strncmp(*argv, "pwd", 4))
		return (execute_command_pwd(argv, envp));
	if (!ft_strncmp(*argv, "env", 4))
		return (execute_command_env(argv, envp));
	if (!ft_strncmp(*argv, "echo", 5))
		return (execute_command_echo(argv, envp));
	if (!ft_strncmp(*argv, "export", 7))
		return (execute_command_export(argv, envp));
	if (!ft_strncmp(*argv, "cd", 3))
		return (execute_command_cd(argv, envp));
	if (!ft_strncmp(*argv, "unset", 6))
		return (execute_command_unset(argv, envp));
	if (!ft_strncmp(*argv, "exit", 5))
		return (execute_command_exit(argv, envp));
	return (-1);
}

int	no_fork(char **argv)
{
	if (!ft_strncmp(argv[0], "cd", 3))
		return (1);
	if (!ft_strncmp(argv[0], "unset", 6))
		return (1);
	if (!ft_strncmp(argv[0], "export", 7) && ft_len((void **)argv) > 1)
		return (1);
	return (0);
}
