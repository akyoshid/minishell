/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 21:01:02 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/30 21:02:01 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// The programmer is responsible for
//  `token_typ` of `current_toke_node` is TOKEN_REDIROP
//  and `token_typ` of next `current_toke_node` is TOKEN_WORD.
t_redir_list	*parse_redir(t_ctx *ctx, t_token_list **current_token_node_p)
{
	t_redir	*content;
	int		token_type;

	content = (t_redir *)xmalloc(sizeof(t_redir));
	token_type = get_token_type(*current_token_node_p);
	if (token_type >= TOKEN_REDIROP_IN
		&& token_type <= TOKEN_REDIROP_IN_HEREDOC_DEL_TAB_NO_EXPAND)
		content->type = REDIR_IN;
	else if (token_type == TOKEN_REDIROP_OUT)
		content->type = REDIR_OUT;
	else if (token_type == TOKEN_REDIROP_OUT_APPEND)
		content->type = REDIR_OUT_APPEND;
	*current_token_node_p = (*current_token_node_p)->next;
	content->word = ft_xstrdup(get_token_word(*current_token_node_p));
	if (token_type == TOKEN_REDIROP_IN_HEREDOC
		|| token_type == TOKEN_REDIROP_IN_HEREDOC_DEL_TAB_NO_EXPAND)
		perform_heredoc(ctx, content, token_type);
	*current_token_node_p = (*current_token_node_p)->next;
	return (ft_xlstnew(content));
}
