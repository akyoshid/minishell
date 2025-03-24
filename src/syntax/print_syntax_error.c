/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_syntax_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:49:43 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/24 19:25:56 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	print_syntax_error(int current_token_type, char *token_word)
{
	ft_dprintf(2, "minishell: syntax error near unexpected token ");
	if (current_token_type == NO_TOKEN)
		ft_dprintf(2, "`newline'\n");
	else if (current_token_type == TOKEN_WORD)
		ft_dprintf(2, "`%s'\n", token_word);
	else if (current_token_type == TOKEN_REDIROP_IN)
		ft_dprintf(2, "`<'\n");
	else if (current_token_type == TOKEN_REDIROP_IN_HEREDOC)
		ft_dprintf(2, "`<<'\n");
	else if (current_token_type == TOKEN_REDIROP_IN_HEREDOC_DEL_TAB)
		ft_dprintf(2, "`<<-'\n");
	else if (current_token_type == TOKEN_REDIROP_OUT)
		ft_dprintf(2, "`>'\n");
	else if (current_token_type == TOKEN_REDIROP_OUT_APPEND)
		ft_dprintf(2, "`>>'\n");
	else if (current_token_type == TOKEN_CNTLOP_PIPE)
		ft_dprintf(2, "`|'\n");
	else if (current_token_type == TOKEN_CNTLOP_AND_LIST)
		ft_dprintf(2, "`&&'\n");
	else if (current_token_type == TOKEN_CNTLOP_OR_LIST)
		ft_dprintf(2, "`||'\n");
	else if (current_token_type == TOKEN_CNTLOP_L_PARENTHESE)
		ft_dprintf(2, "`('\n");
	else if (current_token_type == TOKEN_CNTLOP_R_PARENTHESE)
		ft_dprintf(2, "`)'\n");
}
