/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_is_head.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:28:03 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/24 19:28:20 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_syntax_current_is_head(int head_token_type)
{
	if (head_token_type == NO_TOKEN
		|| head_token_type == TOKEN_WORD
		|| head_token_type == TOKEN_REDIROP_IN
		|| head_token_type == TOKEN_REDIROP_IN_HEREDOC
		|| head_token_type == TOKEN_REDIROP_IN_HEREDOC_DEL_TAB
		|| head_token_type == TOKEN_REDIROP_OUT
		|| head_token_type == TOKEN_REDIROP_OUT_APPEND
		|| head_token_type == TOKEN_CNTLOP_L_PARENTHESE)
		return (SYNTAX_OK);
	else
	{
		print_syntax_error(head_token_type, NULL);
		return (SYNTAX_ERROR);
	}
}
