/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 00:09:44 by napark            #+#    #+#             */
/*   Updated: 2021/12/13 00:42:45 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lexer(char *line)
{
	char	**tokens;
	int		exit_status;

	tokens = ft_split_set(line, " \t\r\v\f\n");
	if (join_quotes(&tokens) == EXIT_FAILURE)
	{
		ft_free_str_array(&tokens);
		return (EXIT_FAILURE);
	}
	if (tokens == NULL)
		return (EXIT_FAILURE);
	tokens = adjust_tokens(tokens);
	if (tokens == NULL)
		return (EXIT_FAILURE);
	set_lex_toks(tokens);
	if (!is_valid_syntax(tokens))
	{
		ft_putstr_fd("minishell: Invalid Syntax at unspecified token\n", 2);
		ft_free_str_array(&tokens);
		return (EXIT_SYNTAX_ERROR);
	}
	exit_status = parser(tokens);
	ft_free_str_array(&tokens);
	return (exit_status);
}