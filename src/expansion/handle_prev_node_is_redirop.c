/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_prev_node_is_redirop.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:50:12 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/02 10:50:59 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_token_list	*handle_prev_node_is_redirop(
	t_token_list *prev_node, t_token_list *current_node,
	char *current_node_word_original, t_token_list *new_list)
{
	if (count_token_node(new_list) == 1)
		free(current_node_word_original);
	else
	{
		free(get_token_word(current_node));
		set_token_word(current_node, current_node_word_original);
		set_token_type(prev_node, TOKEN_REDIROP_AMBIGUOUS);
	}
	clear_token_list(&new_list);
	return (current_node);
}
