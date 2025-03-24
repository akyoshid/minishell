/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prev_is_cntlop_r_parenthese.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:55:15 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/24 19:27:03 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	_check_syntax_prev_is_cntlop_r_parenthese_current_is_redirop(
	t_token_list *current_token_node)
{
	t_token_list	*next_token_node;
	int				next_token_type;
	t_token_list	*second_next_token_node;
	int				second_next_token_type;

	next_token_node = current_token_node->next;
	next_token_type = get_token_type(next_token_node);
	if (check_syntax_prev_is_redirop(next_token_type) == SYNTAX_OK)
	{
		second_next_token_node = next_token_node->next;
		second_next_token_type = get_token_type(second_next_token_node);
		return (check_syntax_prev_is_cntlop_r_parenthese(
				second_next_token_type, second_next_token_node));
	}
	else
		return (SYNTAX_ERROR);
}

int	check_syntax_prev_is_cntlop_r_parenthese(
	int current_token_type, t_token_list *current_token_node)
{
	if (current_token_type == NO_TOKEN
		|| current_token_type == TOKEN_CNTLOP_PIPE
		|| current_token_type == TOKEN_CNTLOP_AND_LIST
		|| current_token_type == TOKEN_CNTLOP_OR_LIST
		|| current_token_type == TOKEN_CNTLOP_R_PARENTHESE)
		return (SYNTAX_OK);
	else if (current_token_type == TOKEN_REDIROP_IN
		|| current_token_type == TOKEN_REDIROP_IN_HEREDOC
		|| current_token_type == TOKEN_REDIROP_IN_HEREDOC_DEL_TAB
		|| current_token_type == TOKEN_REDIROP_OUT
		|| current_token_type == TOKEN_REDIROP_OUT_APPEND)
		return (_check_syntax_prev_is_cntlop_r_parenthese_current_is_redirop(
				current_token_node));
	else
	{
		print_syntax_error(
			current_token_type, get_token_word(current_token_node));
		return (SYNTAX_ERROR);
	}
}
