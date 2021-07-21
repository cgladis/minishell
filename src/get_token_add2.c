#include "get_token.h"

char	*check_slash_in_prompt_like_bash(char **prompt)
{
	*prompt = shift_str(*prompt, 1);
	if (**prompt == '\\')
	{
		*prompt = shift_str(*prompt, 1);
		if (**prompt == '\\')
			return (ft_strdup("\\"));
	}
	return (ft_strdup(""));
}

char	*one_quote(char **prompt)
{
	char	*str;

	str = ft_strdup("");
	*prompt = shift_str(*prompt, 1);
	while (**prompt != '\'')
	{
		if (**prompt == '\0')
			*prompt = my_readline(ft_strdup("\n"), "quote> ");
		str = ft_cont_str_and_free(str, get_word(prompt, "", "\\\'", ""), NULL);
		while (**prompt == '\\')
			str = ft_cont_str_and_free(str, check_slash_in_quote(prompt), NULL);
	}
	*prompt = shift_str(*prompt, 1);
	return (str);
}

char	*add_variable(char **prompt)
{
	char	*result;
	char	*variable;
	char	tmp;
	char	*ptr;

	*prompt = shift_str(*prompt, 1);
	if (**prompt == '?')
	{
		*prompt = shift_str(*prompt, 1);
		return (ft_itoa(g_vars.last_exit_status));
	}
	ptr = *prompt;
	while (ft_isalnum(*ptr) || *ptr == '_')
		ptr++;
	tmp = *ptr;
	*ptr = '\0';
	variable = ft_strdup(*prompt);
	result = variable_value(variable, g_vars.envp);
	free(variable);
	*ptr = tmp;
	*prompt = shift_str(*prompt, ptr - *prompt);
	return (result);
}

char	*double_quote(char **prompt)
{
	char	*str;

	str = ft_strdup("");
	*prompt = shift_str(*prompt, 1);
	while (**prompt != '\"')
	{
		if (**prompt == '\0')
		{
			free(*prompt);
			*prompt = my_readline(ft_strdup("\n"), "quote> ");
		}
		str = ft_cont_str_and_free(str, get_word(prompt, "", "\\\"$", ""), NULL);
		if (**prompt == '$')
			str = ft_cont_str_and_free(str, add_variable(prompt), NULL);
		while (**prompt == '\\')
			str = ft_cont_str_and_free(str, check_slash_in_quote(prompt), NULL);
	}
	*prompt = shift_str(*prompt, 1);
	return (str);
}
