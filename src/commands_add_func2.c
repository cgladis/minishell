#include "minishell.h"

char	**get_path(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			path = ft_split(envp[i] + 5, ":");
		i++;
	}
	if (path)
		path = ft_union_lines(ft_add_str(NULL, ""), path);
	else
		path = ft_add_str(NULL, "");
	return (path);
}

t_global	get_vars(int argc, char **argv, char **envp)
{
	t_global	vars;

	(void)argc;
	(void)argv;
	vars.envp = NULL;
	while (*envp)
	{
		vars.envp = ft_add_str_and_free_str1(vars.envp, *envp);
		envp++;
	}
	vars.argv = argv;
	vars.path = get_path(vars.envp);
	vars.exit_code = -1;
	vars.pipes = NULL;
	vars.pipe_now = 0;
	vars.count_process = 0;
	vars.last_exit_status = 0;
	vars.ebash_pid = getpid();
	vars.current_pid = 0;
	vars.pwd = variable_value("PWD", vars.envp);
	vars.home = variable_value("HOME", vars.envp);
	vars.need_signal = 0;
	return (vars);
}
