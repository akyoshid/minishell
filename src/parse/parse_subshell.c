/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_subshell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 23:23:14 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/31 16:15:45 by akyoshid         ###   ########.fr       */
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
		if ((token_type >= TOKEN_REDIROP_IN
				&& token_type <= TOKEN_REDIROP_OUT_APPEND)
			|| token_type == TOKEN_REDIROP_AMBIGUOUS)
			ft_lstadd_back(&new_node->redir_list,
				parse_redir(ctx, current_token_node_p));
		else
			break ;
	}
}

// First, call parse_and_or(), and keep parsing until
//  TOKEN_CNTLOP_R_PARENTHESE or NULL termination of the token list appears.
// Second, call parse_redir()
//  until one of the following control operator tokens:
//  - TOKEN_CNTLOP_PIPE
//  - TOKEN_CNTLOP_AND_LIST
//  - TOKEN_CNTLOP_OR_LIST
//  - TOKEN_CNTLOP_R_PARENTHESE
//  or NULL termination of the token list appears.
// Note that only TOKEN_CNTLOP_L_PARENTHESE
//  cannot be a control operator that stops parsing.
// It’s because TOKEN_CNTLOP_L_PARENTHESE
//  must always follow one of these tokens in the grammar:
//  - These tokens will terminate parse_command when they appear 
//    - TOKEN_CNTLOP_PIPE
//    - TOKEN_CNTLOP_AND_LIST
//    - TOKEN_CNTLOP_OR_LIST
//  - This token must always follow one of the above three in the grammar
//   (if we didn't go to parse_subshell in parse_command,
//    i.e. if the first token in parse_command is not TOKEN_CNTLOP_L_PARENTHESE)
//    - TOKEN_CNTLOP_L_PARENTHESE
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
