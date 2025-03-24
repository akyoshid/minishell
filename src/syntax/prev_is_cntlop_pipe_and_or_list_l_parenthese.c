/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prev_is_cntlop_pipe_and_or_list_l_parenthes        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:52:52 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/24 19:29:49 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_syntax_prev_is_cntlop_pipe_and_or_list_l_parenthese(
	int current_token_type)
{
	if (current_token_type == TOKEN_WORD
		|| current_token_type == TOKEN_REDIROP_IN
		|| current_token_type == TOKEN_REDIROP_IN_HEREDOC
		|| current_token_type == TOKEN_REDIROP_IN_HEREDOC_DEL_TAB
		|| current_token_type == TOKEN_REDIROP_OUT
		|| current_token_type == TOKEN_REDIROP_OUT_APPEND
		|| current_token_type == TOKEN_CNTLOP_L_PARENTHESE)
		return (SYNTAX_OK);
	else
	{
		print_syntax_error(current_token_type, NULL);
		return (SYNTAX_ERROR);
	}
}
