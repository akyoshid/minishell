/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_in_token_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:20:15 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/30 23:40:09 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	expand_env_in_token_list(t_ctx *ctx, t_token_list **token_list_p)
{
	t_token_list	*prev_node;
	t_token_list	*current_node;
	int				prev_node_type;
	char			*current_node_word_original;

	prev_node = NULL;
	current_node = *token_list_p;
	while (current_node != NULL)
	{
		if (get_token_type(current_node) == TOKEN_WORD)
		{
			prev_node_type = get_token_type(prev_node);
			if (prev_node_type != TOKEN_REDIROP_IN_HEREDOC
				&& prev_node_type != TOKEN_REDIROP_IN_HEREDOC_DEL_TAB)
			{
				current_node_word_original
					= ft_xstrdup(get_token_word(current_node));
				expand_env(ctx, &((t_token *)current_node->content)->word);
				current_node = split_word(token_list_p,
						prev_node, current_node, current_node_word_original);
			}
		}
		prev_node = current_node;
		current_node = current_node->next;
	}
}
