#include "minishell.h"

void	add_env(char *var, char *value)
{
	if (value != NULL)
		g_vars.envp = ft_add_str_and_free_str1_str2(g_vars.envp,
				ft_cont_str(var, "=", value, NULL));
	else
		g_vars.envp = ft_add_str_and_free_str1(g_vars.envp, var);
}

void	set_value(char *var, char *value, char **envp)
{
	char	*name;

	while (envp && *envp)
	{
		name = get_name_env(*envp);
		if (name)
		{
			if (!ft_strcmp(name, var) && value != NULL)
			{
				free(*envp);
				free(name);
				*envp = ft_cont_str(var, "=", value, NULL);
				return ;
			}
			else if (!ft_strcmp(name, var) && value == NULL)
			{
				free(name);
				return ;
			}
			free(name);
		}
		envp++;
	}
	add_env(var, value);
}

int	add_export(char **argv)
{
	char	*name;
	char	*value;

	while (*argv)
	{
		name = get_name_env(*argv);
		if (name)
		{
			value = get_value_env(*argv);
			set_value(name, value, g_vars.envp);
			free(name);
			free(value);
		}
		else
			ft_print("export: '", *argv, "': not a valid identifier\n", NULL);
		argv++;
	}
	return (0);
}

void	print_export(char **envp)
{
	char	**sort_envp;
	char	**ptr;

	sort_envp = record_envp(envp);
	ptr = sort_envp;
	ft_str_sort(sort_envp);
	while (*sort_envp)
	{
		ft_print("declare -x ", *sort_envp, "\n", NULL);
		sort_envp++;
	}
	ft_free_str_lines(ptr);
}

int	execute_command_export(char **argv, char **envp)
{
	if (ft_len((void **)argv) > 1 && g_vars.pipe_now == 0)
	{
		add_export(argv + 1);
		return (0);
	}
	else if (ft_len((void **)argv) == 1)
	{
		print_export(envp);
		exit(0);
	}
	return (0);
}
