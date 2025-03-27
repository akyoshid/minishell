/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_in_token_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:20:15 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/26 17:47:52 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	expand_env_in_token_list(t_ctx *ctx, t_token_list **token_list_p)
{
	t_token_list	*prev_node;
	t_token_list	*current_node;

	prev_node = NULL;
	current_node = *token_list_p;
	while (current_node != NULL)
	{
		if (get_token_type(current_node) == TOKEN_WORD)
		{
			expand_env(ctx, &((t_token *)current_node->content)->word);
			current_node = split_word(token_list_p, prev_node, current_node);
		}
		prev_node = current_node;
		current_node = current_node->next;
	}
}
