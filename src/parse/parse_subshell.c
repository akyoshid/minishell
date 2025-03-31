/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_subshell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 23:23:14 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/30 21:39:35 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	_parse_subshell_redir(
	t_ctx *ctx, t_token_list **current_token_node_p, t_ast *new_node)
{
	int	token_type;

	while (*current_token_node_p != NULL)
	{
		token_type = get_token_type(*current_token_node_p);
		if (token_type >= TOKEN_REDIROP_IN
			&& token_type <= TOKEN_REDIROP_OUT_APPEND)
			ft_lstadd_back(&new_node->redir_list,
				parse_redir(ctx, current_token_node_p));
		else
			break ;
	}
}

t_ast	*parse_subshell(t_ctx *ctx, t_token_list **current_token_node_p)
{
	t_ast	*new_node;

	if (get_token_type(*current_token_node_p) != TOKEN_CNTLOP_L_PARENTHESE)
		return (NULL);
	*current_token_node_p = (*current_token_node_p)->next;
	new_node = (t_ast *)xmalloc(sizeof(t_ast));
	new_node->type = AST_SUBSHELL;
	new_node->cmd_args = NULL;
	new_node->redir_list = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->subshell_ast = parse_and_or(ctx, current_token_node_p);
	if (*current_token_node_p == NULL
		|| get_token_type(*current_token_node_p) != TOKEN_CNTLOP_R_PARENTHESE)
		return (clear_ast(new_node->subshell_ast), free(new_node), NULL);
	*current_token_node_p = (*current_token_node_p)->next;
	_parse_subshell_redir(ctx, current_token_node_p, new_node);
	return (new_node);
}
