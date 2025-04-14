/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_new_list_is_null.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:51:27 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/14 11:04:49 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

t_token_list	*handle_new_list_is_null(
	t_token_list *prev_node, t_token_list *current_node,
	char *current_node_word_original)
{
	int	prev_node_type;

	free(get_token_word(current_node));
	prev_node_type = get_token_type(prev_node);
	if (prev_node_type >= TOKEN_REDIROP_IN
		&& prev_node_type <= TOKEN_REDIROP_OUT_APPEND)
	{
		set_token_word(current_node, current_node_word_original);
		set_token_type(prev_node, TOKEN_REDIROP_AMBIGUOUS);
	}
	else
	{
		free(current_node_word_original);
		set_token_word(current_node, NULL);
		set_token_type(current_node, TOKEN_NOOP);
	}
	return (current_node);
}
