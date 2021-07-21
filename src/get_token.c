#include "get_token.h"

static void	check_prompt(char **prompt, char **str)
{
	if (*str == NULL)
		*str = ft_strdup("");
	*str = ft_cont_str_and_free(*str,
			get_word(prompt, " \t", ";|$><\"\'\\", ""), NULL);
	if (**prompt == '"')
	{
		*str = ft_cont_str_and_free(*str, double_quote(prompt), NULL);
	}
	if (**prompt == '\'')
		*str = ft_cont_str_and_free(*str, one_quote(prompt), NULL);
	if (**prompt == '\\')
		*str = ft_cont_str_and_free(*str,
				check_slash_in_prompt_like_term(prompt), NULL);
	if (**prompt == '$')
		*str = ft_cont_str_and_free(*str, add_variable(prompt), NULL);
}

char	*one_token(char **prompt)
{
	char	*str;

	str = NULL;
	*prompt = del_first_chars_in_str(*prompt, " \t");
	if (**prompt == ';')
		return (check_slash_in_quote_support(prompt, ";"));
	if (**prompt == '|')
		return (check_slash_in_quote_support(prompt, "|"));
	if (!ft_strncmp(*prompt, ">>", 2))
		return (check_slash_in_quote_support(prompt, ">>"));
	if (!ft_strncmp(*prompt, "<<", 2))
		return (check_slash_in_quote_support(prompt, "<<"));
	if (**prompt == '>')
		return (check_slash_in_quote_support(prompt, ">"));
	if (**prompt == '<')
		return (check_slash_in_quote_support(prompt, "<"));
	while (**prompt != ' ' && **prompt != '\t' && **prompt != ';'
		&& **prompt != '>' && **prompt != '<'
		&& **prompt != '|' && **prompt != '\0')
	{
		check_prompt(prompt, &str);
	}
	if (str == NULL)
		str = ft_strdup("");
	return (str);
}

t_list2	*get_token(char *prompt)
{
	t_list2	*token;
	char	*str;

	token = NULL;
	while (*prompt)
	{
		str = one_token(&prompt);
		if (*str != '\0')
			ft_lst2add_back(&token, ft_lst2new((str)));
		else
			free(str);
	}
	free(prompt);
	return (token);
}
