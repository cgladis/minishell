#include "minishell.h"

char	*get_name_env(char *str)
{
	char	*name;
	char	*ptr;

	ptr = str;
	if (ft_isdigit(*str))
		return (NULL);
	while (ft_isalnum(*ptr) || *ptr == '_')
	{
		ptr++;
	}
	if ((*ptr != '=' && *ptr != '\0') || str == ptr)
		return (NULL);
	if (*ptr == '=')
	{
		*ptr = '\0';
		name = ft_strdup(str);
		*ptr = '=';
		return (name);
	}
	name = ft_strdup(str);
	return (name);
}

char	*get_value_env(char *str)
{
	char	*value;

	value = ft_strchr(str, '=');
	if (value)
		value = strdup(value + 1);
	return (value);
}

char	**record_envp(char **envp)
{
	char	**sort_envp;
	char	*name;
	char	*value;

	sort_envp = NULL;
	while (*envp)
	{
		name = get_name_env(*envp);
		if (name)
		{
			value = get_value_env(*envp);
			if (value)
				sort_envp = ft_add_str_and_free_str1_str2(sort_envp,
						ft_cont_str_and_free(name, ft_strdup("=\""),
							value, ft_strdup("\""), NULL));
			else
				sort_envp = ft_add_str_and_free_str1_str2(sort_envp, name);
		}
		envp++;
	}
	return (sort_envp);
}
