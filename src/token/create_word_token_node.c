/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_word_token_node.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:37:27 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/24 19:47:53 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	_proc_quote(char **input_p, int *word_len_p)
{
	bool	single_quote;

	single_quote = true;
	if (**input_p == '\"')
		single_quote = false;
	while (1)
	{
		(*input_p)++;
		(*word_len_p)++;
		if ((single_quote == true && **input_p == '\'')
			|| (single_quote == false && **input_p == '\"'))
			break ;
		if (**input_p == '\0')
		{
			ft_dprintf(2, "minishell: unexpected `newline' "
				"while looking for matching ");
			if (single_quote == true)
				ft_dprintf(2, "`\''\n");
			else
				ft_dprintf(2, "`\"'\n");
			return (1);
		}
	}
	return (0);
}

t_token_list	*create_word_token_node(char **input_p)
{
	t_token	*content;
	int		word_len;

	content = (t_token *)xmalloc(sizeof(t_token));
	content->type = TOKEN_WORD;
	word_len = 0;
	while (get_char_type(**input_p) == CHAR_NON_METACHAR)
	{
		if (**input_p == '\'' || **input_p == '\"')
		{
			if (_proc_quote(input_p, &word_len) == 1)
				return (free(content), NULL);
		}
		(*input_p)++;
		word_len++;
	}
	content->word = ft_xstrndup(*input_p - word_len, word_len);
	return (ft_xlstnew(content));
}
