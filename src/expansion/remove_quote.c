/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:28:25 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/27 13:29:53 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	_remove_quote_core(char *current_node_word, int *i_p)
{
	bool	single_quote;

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
}

void	remove_quote(t_token_list *token_list)
{
	t_token_list	*current_node;
	char			*current_node_word;
	int				i;

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
					_remove_quote_core(current_node_word, &i);
				else
					i++;
			}
		}
		current_node = current_node->next;
	}
}
