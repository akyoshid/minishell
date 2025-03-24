/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prev_is_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:28:36 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/24 19:28:52 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_syntax_prev_is_word(int current_token_type)
{
	if (current_token_type == NO_TOKEN
		|| current_token_type == TOKEN_WORD
		|| current_token_type == TOKEN_REDIROP_IN
		|| current_token_type == TOKEN_REDIROP_IN_HEREDOC
		|| current_token_type == TOKEN_REDIROP_IN_HEREDOC_DEL_TAB
		|| current_token_type == TOKEN_REDIROP_OUT
		|| current_token_type == TOKEN_REDIROP_OUT_APPEND
		|| current_token_type == TOKEN_CNTLOP_PIPE
		|| current_token_type == TOKEN_CNTLOP_AND_LIST
		|| current_token_type == TOKEN_CNTLOP_OR_LIST
		|| current_token_type == TOKEN_CNTLOP_R_PARENTHESE)
		return (SYNTAX_OK);
	else
	{
		print_syntax_error(current_token_type, NULL);
		return (SYNTAX_ERROR);
	}
}
