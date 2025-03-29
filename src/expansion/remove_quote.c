/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:28:25 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/29 18:45:58 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	_remove_quote_core(
	char *current_node_word, int *i_p, t_token_list *prev_node)
{
	bool	single_quote;
	int		prev_node_type;

	single_quote = true;
	if (current_node_word[*i_p] == '\"')
		single_quote = false;
	ft_strcpy(current_node_word + *i_p, current_node_word + *i_p + 1);
	while (1)
	{
		if ((single_quote == true && current_node_word[*i_p] == '\'')
			|| (single_quote == false && current_node_word[*i_p] == '\"'))
			break ;
		(*i_p)++;
	}
	ft_strcpy(current_node_word + *i_p, current_node_word + *i_p + 1);
	prev_node_type = get_token_type(prev_node);
	if (prev_node_type == TOKEN_REDIROP_IN_HEREDOC)
		set_token_type(prev_node, TOKEN_REDIROP_IN_HEREDOC_NO_EXPAND);
	if (prev_node_type == TOKEN_REDIROP_IN_HEREDOC_DEL_TAB)
		set_token_type(prev_node, TOKEN_REDIROP_IN_HEREDOC_DEL_TAB_NO_EXPAND);
}

void	remove_quote(t_token_list *token_list)
{
	t_token_list	*prev_node;
	t_token_list	*current_node;
	char			*current_node_word;
	int				i;

	prev_node = NULL;
	current_node = token_list;
	while (current_node != NULL)
	{
		if (get_token_type(current_node) == TOKEN_WORD)
		{
			current_node_word = get_token_word(current_node);
			i = 0;
			while (current_node_word[i] != '\0')
			{
				if (current_node_word[i] == '\''
					|| current_node_word[i] == '\"')
					_remove_quote_core(current_node_word, &i, prev_node);
				else
					i++;
			}
		}
		prev_node = current_node;
		current_node = current_node->next;
	}
}
