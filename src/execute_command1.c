#include "minishell.h"

int	run_programm(char **argv)
{
	if (no_fork(argv))
	{
		g_vars.current_pid = 0;
	}
	else
	{
		g_vars.count_process++;
		g_vars.current_pid = run_fork();
	}
	if (g_vars.current_pid == 0)
	{
		if (try_execve(g_vars.path, argv, g_vars.envp) == -1)
			exit(errno);
		else
			return (0);
	}
	else if (g_vars.current_pid == -1)
		exit (errno);
	else
		g_vars.last_exit_status = 0;
	return (0);
}
