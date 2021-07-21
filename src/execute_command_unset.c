#include "minishell.h"

char	*find_variable(char *var, char **envp)
{
	char	*val;
	char	*varstr;

	val = NULL;
	varstr = ft_cont_str(var, "=", NULL);
	while (*envp)
	{
		if (!ft_strncmp(*envp, varstr, ft_strlen(varstr)))
			val = *envp;
		envp++;
	}
	free(varstr);
	return (val);
}

char	**copy_envp_without_var(char *var, char **envp)
{
	char	**new_envp;

	new_envp = NULL;
	while (*envp)
	{
		if (*envp != var)
			new_envp = ft_add_str_and_free_str1(new_envp, *envp);
		envp++;
	}
	return (new_envp);
}

char	**del_variable(char *var, char **envp)
{
	char	**new_envp;

	new_envp = NULL;
	new_envp = copy_envp_without_var(var, envp);
	ft_free_str_lines(envp);
	return (new_envp);
}

int	execute_command_unset(char **argv, char **envp)
{
	char	*current_var;

	argv++;
	if (envp == NULL)
		return (0);
	if (g_vars.pipe_now != 0)
		return (0);
	while (*argv)
	{
		current_var = find_variable(*argv, g_vars.envp);
		if (current_var != NULL)
			g_vars.envp = del_variable(current_var, g_vars.envp);
		argv++;
	}
	return (0);
}
