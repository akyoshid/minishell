/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_word_token_node.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:37:27 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/22 11:52:34 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	_quote_reader(char **input_p, bool single_quote)
{
	char	*new_line;
	char	*input_ap_new_line_char;

	new_line = readline("> ");
	if (new_line == NULL)
	{
		ft_dprintf(2, "minishell: unexpected EOF while looking for matching ");
		if (single_quote == true)
			ft_dprintf(2, "`\''\n");
		else
			ft_dprintf(2, "`\"'\n");
		ft_dprintf(STDERR_FILENO, "exit\n");
		exit(EXIT_USAGE);
	}
	input_ap_new_line_char = ft_xstrjoin(*input_p, "\n");
	free(*input_p);
	*input_p = ft_xstrjoin(input_ap_new_line_char, new_line);
	free(input_ap_new_line_char);
	free(new_line);
}

// Process until the quote closes.
void	proc_quote(char **input_p, int *i_p, int *word_len_p)
{
	bool	single_quote;

	single_quote = true;
	if ((*input_p)[*i_p] == '\"')
		single_quote = false;
	while (1)
	{
		(*i_p)++;
		(*word_len_p)++;
		if ((single_quote == true && (*input_p)[*i_p] == '\'')
			|| (single_quote == false && (*input_p)[*i_p] == '\"'))
			break ;
		if ((*input_p)[*i_p]  == '\0')
		{
			// 文法チェック
			_quote_reader(input_p, single_quote);
		}
	}
}

t_token_list	*create_word_token_node(char **input_p, int *i_p)
{
	t_token	*content;
	int		word_len;

	content = (t_token *)xmalloc(sizeof(t_token));
	content->type = TOKEN_WORD;
	word_len = 0;
	while (get_char_type((*input_p)[*i_p]) == CHAR_NON_METACHAR)
	{
		if ((*input_p)[*i_p] == '\'' || (*input_p)[*i_p] == '\"')
			proc_quote(input_p, i_p, &word_len);
		(*i_p)++;
		word_len++;
	}
	content->word = ft_xstrndup((*input_p) + *i_p - word_len, word_len);
	return (ft_xlstnew(content));
}
