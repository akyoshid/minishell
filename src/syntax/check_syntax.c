/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 06:43:43 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/24 19:25:50 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	_check_syntax_switch(
	t_token_list *current_token_node,
	int prev_token_type, int current_token_type)
{
	if (prev_token_type == NO_TOKEN)
		return (check_syntax_current_is_head(current_token_type));
	else if (prev_token_type == TOKEN_WORD)
		return (check_syntax_prev_is_word(current_token_type));
	else if (prev_token_type >= TOKEN_REDIROP_IN
		&& prev_token_type <= TOKEN_REDIROP_OUT_APPEND)
		return (check_syntax_prev_is_redirop(current_token_type));
	else if (prev_token_type >= TOKEN_CNTLOP_PIPE
		&& prev_token_type <= TOKEN_CNTLOP_L_PARENTHESE)
		return (
			check_syntax_prev_is_cntlop_pipe_and_or_list_l_parenthese(
				current_token_type));
	else if (prev_token_type == TOKEN_CNTLOP_R_PARENTHESE)
		return (
			check_syntax_prev_is_cntlop_r_parenthese(
				current_token_type, current_token_node));
	else
		return (SYNTAX_ERROR);
}

static int	_check_subshell_nest_level(
	int current_token_type, int *subshell_nest_level_p)
{
	if (current_token_type == TOKEN_CNTLOP_L_PARENTHESE)
		(*subshell_nest_level_p)++;
	else if (current_token_type == TOKEN_CNTLOP_R_PARENTHESE)
	{
		(*subshell_nest_level_p)--;
		if (*subshell_nest_level_p < 0)
		{
			print_syntax_error(TOKEN_CNTLOP_R_PARENTHESE, NULL);
			return (SYNTAX_ERROR);
		}
	}
	else if (current_token_type == NO_TOKEN)
	{
		if (*subshell_nest_level_p > 0)
		{
			print_syntax_error(NO_TOKEN, NULL);
			return (SYNTAX_ERROR);
		}
	}
	return (SYNTAX_OK);
}

int	check_syntax(t_token_list *token_list)
{
	t_token_list	*current_token_node;
	int				prev_token_type;
	int				current_token_type;
	int				subshell_nest_level;

	current_token_node = token_list;
	prev_token_type = NO_TOKEN;
	subshell_nest_level = 0;
	while (1)
	{
		current_token_type = get_token_type(current_token_node);
		if (_check_subshell_nest_level(
				current_token_type, &subshell_nest_level) == SYNTAX_ERROR)
			return (SYNTAX_ERROR);
		if (_check_syntax_switch(
				current_token_node, prev_token_type, current_token_type)
			== SYNTAX_ERROR)
			return (SYNTAX_ERROR);
		if (current_token_type == NO_TOKEN)
			break ;
		prev_token_type = current_token_type;
		current_token_node = current_token_node->next;
	}
	return (_check_subshell_nest_level(
			current_token_type, &subshell_nest_level));
}
