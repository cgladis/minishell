#include "minishell.h"

static	int	check_exit_code(char **argv)
{
	if (!ft_strncmp(argv[0], "exit", 5))
	{
		if (ft_len((void **)argv) > 1)
			g_vars.exit_code = ft_atoi(argv[1]);
		else
			g_vars.exit_code = 0;
		return (1);
	}
	return (0);
}

static	void	check_pipe_now(int fl_pipe)
{
	if (!fl_pipe && (g_vars.pipe_now == 2 || g_vars.pipe_now == 1))
		g_vars.pipe_now = 3;
	else if (!fl_pipe && g_vars.pipe_now == 3)
		g_vars.pipe_now = 0;
}

int	check_pipe_error(t_list2 **token, t_list2	*current_token)
{
	if (!ft_strncmp(current_token->content, "|", 2))
	{
		*token = current_token->next;
		ft_print("syntax error near unexpected token\n", NULL);
		return (1);
	}
	return (0);
}

int	prepere_command(t_list2	*current_token, t_list2 **token, char ***argv,
				int *fl_pipe)
{
	int	res;

	while (current_token != NULL && ft_strncmp(current_token->content, ";", 2))
	{
		res = (check_redirect(&current_token));
		if (res == -1)
			return (-1);
		else if (res)
			continue ;
		*fl_pipe = check_pipe(&current_token);
		if (*fl_pipe)
			break ;
		*argv = ft_add_str_and_free_str1(*argv, current_token->content);
		current_token = current_token->next;
	}
	if (current_token != NULL)
	{
		if (!ft_strncmp(current_token->content, ";", 2))
			current_token = current_token->next;
	}
	*token = current_token;
	return (0);
}

int	execute_command(t_list2 **token)
{
	char	**argv;
	t_list2	*current_token;
	int		fl_pipe;
	int		res;

	argv = NULL;
	fl_pipe = 0;
	g_vars.fd_in = STDIN;
	g_vars.fd_out = STDOUT;
	current_token = *token;
	if (check_pipe_error(token, current_token))
		return (1);
	if (prepere_command(current_token, token, &argv, &fl_pipe) == -1)
		return (-1);
	check_pipe_now(fl_pipe);
	if (check_exit_code(argv) == 1)
		return (1);
	res = run_programm(argv);
	ft_free_str_lines(argv);
	return (res);
}
