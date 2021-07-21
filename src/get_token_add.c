#include "get_token.h"

char	*variable_value(char *var, char **envp)
{
	int		i;
	char	*val;
	char	*varstr;

	if (!envp)
		return (strdup(""));
	i = 0;
	val = NULL;
	varstr = ft_cont_str(var, "=", NULL);
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], varstr, ft_strlen(varstr)))
			val = strdup(envp[i] + ft_strlen(varstr));
		else if (!ft_strncmp(envp[i], var, ft_strlen(var) + 1))
			val = ft_strdup("");
		i++;
		if (val != NULL)
			break ;
	}
	free(varstr);
	return (val);
}

char	*check_slash_in_quote_support(char **prompt, char *c)
{
	*prompt = shift_str(*prompt, ft_strlen(c));
	return (ft_strdup(c));
}

char	*check_slash_in_quote(char **prompt)
{
	*prompt = shift_str(*prompt, 1);
	if (**prompt == '\\')
		return (check_slash_in_quote_support(prompt, "\\"));
	if (**prompt == '0')
		return (check_slash_in_quote_support(prompt, ""));
	if (**prompt == 'a')
		return (check_slash_in_quote_support(prompt, "\a"));
	if (**prompt == 'b')
		return (check_slash_in_quote_support(prompt, "\b"));
	if (**prompt == 't')
		return (check_slash_in_quote_support(prompt, "\t"));
	if (**prompt == 'n')
		return (check_slash_in_quote_support(prompt, "\n"));
	if (**prompt == 'v')
		return (check_slash_in_quote_support(prompt, "\v"));
	if (**prompt == 'f')
		return (check_slash_in_quote_support(prompt, "\f"));
	if (**prompt == 'r')
		return (check_slash_in_quote_support(prompt, "\r"));
	if (**prompt == 'e')
		return (check_slash_in_quote_support(prompt, "\e"));
	return (ft_strdup("\\"));
}

char	*check_slash_in_prompt(char **prompt)
{
	*prompt = shift_str(*prompt, 1);
	if (**prompt == '\\')
		return (check_slash_in_prompt_like_term(prompt));
	if (**prompt == '0')
		return (check_slash_in_quote_support(prompt, ""));
	if (**prompt == 'a')
		return (check_slash_in_quote_support(prompt, "\a"));
	if (**prompt == 'b')
		return (check_slash_in_quote_support(prompt, "\b"));
	if (**prompt == 't')
		return (check_slash_in_quote_support(prompt, "\t"));
	if (**prompt == 'n')
		return (check_slash_in_quote_support(prompt, "\n"));
	if (**prompt == 'v')
		return (check_slash_in_quote_support(prompt, "\v"));
	if (**prompt == 'f')
		return (check_slash_in_quote_support(prompt, "\f"));
	if (**prompt == 'r')
		return (check_slash_in_quote_support(prompt, "\r"));
	if (**prompt == 'e')
		return (check_slash_in_quote_support(prompt, "\e"));
	return (ft_strdup("\\"));
}

char	*check_slash_in_prompt_like_term(char **prompt)
{
	*prompt = shift_str(*prompt, 1);
	if (**prompt == '\\')
		return (check_slash_in_prompt(prompt));
	return (ft_strdup(""));
}
