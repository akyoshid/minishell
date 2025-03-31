/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_or.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 23:16:12 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/31 16:15:00 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// Keep parsing
//  until a token except TOKEN_CNTLOP_AND_LIST or TOKEN_CNTLOP_OR_LIST
//  or NULL termination of the token list
//  appears after parse_pipe().
// parse_pipe() terminates with the appearance of
//  one of the following control operator tokens:
//  - TOKEN_CNTLOP_AND_LIST
//  - TOKEN_CNTLOP_OR_LIST
//  - TOKEN_CNTLOP_R_PARENTHESE
//  or NULL termination of the token list.
// This means parse_pipe() terminates at the appearance of the following tokens:
//  - TOKEN_CNTLOP_R_PARENTHESE
//  or NULL termination of the token list.
t_ast	*parse_and_or(t_ctx *ctx, t_token_list **current_token_node_p)
{
	t_ast	*left;
	int		token_type;
	t_ast	*new_node;

	left = parse_pipe(ctx, current_token_node_p);
	while (*current_token_node_p != NULL)
	{
		token_type = get_token_type(*current_token_node_p);
		if (token_type != TOKEN_CNTLOP_AND_LIST
			&& token_type != TOKEN_CNTLOP_OR_LIST)
			break ;
		new_node = (t_ast *)xmalloc(sizeof(t_ast));
		if (token_type == TOKEN_CNTLOP_AND_LIST)
			new_node->type = AST_AND;
		else
			new_node->type = AST_OR;
		new_node->cmd_args = NULL;
		new_node->subshell_ast = NULL;
		new_node->redir_list = NULL;
		new_node->left = left;
		*current_token_node_p = (*current_token_node_p)->next;
		new_node->right = parse_pipe(ctx, current_token_node_p);
		left = new_node;
	}
	return (left);
}
