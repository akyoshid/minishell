/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:56:07 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/26 17:49:51 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	_proc_quote(char **original_word_p, int *word_len_p)
{
	bool	single_quote;

	single_quote = true;
	if (**original_word_p == '\"')
		single_quote = false;
	while (1)
	{
		(*original_word_p)++;
		(*word_len_p)++;
		if ((single_quote == true && **original_word_p == '\'')
			|| (single_quote == false && **original_word_p == '\"'))
			break ;
		if (**original_word_p == '\0')
		{
			ft_dprintf(2, "minishell: unexpected `null character' "
				"while looking for matching ");
			if (single_quote == true)
				ft_dprintf(2, "`\''\n");
			else
				ft_dprintf(2, "`\"'\n");
			exit (EXIT_USAGE);
		}
	}
}

static t_token_list	*_create_word_token_node(char **original_word_p)
{
	t_token	*content;
	int		word_len;

	content = (t_token *)xmalloc(sizeof(t_token));
	content->type = TOKEN_WORD;
	word_len = 0;
	while (**original_word_p != '\0' && is_ifs(**original_word_p) == 0)
	{
		if (**original_word_p == '\'' || **original_word_p == '\"')
			_proc_quote(original_word_p, &word_len);
		(*original_word_p)++;
		word_len++;
	}
	content->word = ft_xstrndup(*original_word_p - word_len, word_len);
	return (ft_xlstnew(content));
}

static t_token_list	*_split_word_core(char *original_word)
{
	t_token_list	*token_list;

	token_list = NULL;
	while (*original_word != '\0')
	{
		if (is_ifs(*original_word) == 1)
			original_word++;
		else
			ft_lstadd_back(
				&token_list, _create_word_token_node(&original_word));
	}
	return (token_list);
}

// Return the last token node after the split.
t_token_list	*split_word(t_token_list **token_list_p,
	t_token_list *prev_node, t_token_list *current_node)
{
	t_token_list	*new_list;
	t_token_list	*new_list_last_node;

	new_list = _split_word_core(get_token_word(current_node));
	if (new_list == NULL)
	{
		set_token_type(current_node, TOKEN_NOOP);
		return (current_node);
	}
	if (prev_node == NULL)
		*token_list_p = new_list;
	else
		prev_node->next = new_list;
	new_list_last_node = ft_lstlast(new_list);
	new_list_last_node->next = current_node->next;
	clear_token_node(current_node);
	return (new_list_last_node);
}
