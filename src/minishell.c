#include "minishell.h"

void	close_temp_files(void)
{
	int		fd;

	fd = open(".tmp", O_RDONLY);
	if (fd > 0)
		unlink(".tmp");
}

int	wait_process(void)
{
	int		status;

	status = 0;
	while (g_vars.count_process)
	{
		wait(&status);
		g_vars.current_pid = getpid();
		g_vars.last_exit_status = WEXITSTATUS(status);
		if (WEXITSTATUS(status) && (WEXITSTATUS(status) != 127))
			ft_print("Error: ",
				strerror(WEXITSTATUS(status)), "\n", NULL);
		else if (WEXITSTATUS(status) == 127)
			ft_print("Error: command not found\n", NULL);
		g_vars.count_process--;
	}
	if (g_vars.pipes != NULL)
	{
		ft_lst2clear(g_vars.pipes, free);
		g_vars.pipes = NULL;
	}
	close_temp_files();
	return (status);
}

int	run_all_token(t_list2 *token)
{
	int	res;

	while (token)
	{
		res = execute_command(&token);
		if (res == -1)
			return (-1);
		else if (res)
			return (1);
		if (g_vars.pipe_now == 0 || g_vars.pipe_now == 3)
			wait_process();
	}
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	char			*prompt;
	t_list2			*token;
	struct termios	term;

	g_vars = get_vars(argc, argv, envp);
	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(0, TCSANOW, &term);
	signal(SIGQUIT, wait_signal_slash);
	signal(SIGINT, wait_signal);
	while (g_vars.exit_code == -1)
	{
		command_line(&prompt, "lte-bash> ");
		g_vars.count_process = 0;
		if (prompt)
			token = get_token(prompt);
		run_all_token(token);
		ft_lst2clear(token, free);
		wait_process();
	}
	return (g_vars.exit_code);
}
