/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:20:03 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/31 16:12:01 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	_add_cmd_args(
	t_token_list **current_token_node_p, t_ast *new_node,
	t_parse_command_info *info, char *word)
{
	if (info->arg_count >= info->arg_cap - 1)
	{
		new_node->cmd_args = (char **)ft_xrealloc(
				new_node->cmd_args,
				sizeof(char *) * info->arg_cap,
				sizeof(char *) * info->arg_cap * 2);
		info->arg_cap *= 2;
	}
	new_node->cmd_args[info->arg_count] = ft_xstrdup(word);
	info->arg_count++;
	new_node->cmd_args[info->arg_count] = NULL;
	*current_token_node_p = (*current_token_node_p)->next;
}

// if (token_type == TOKEN_NOOP), enter the else statement
static int	_parse_command_core_switch(
	t_ctx *ctx, t_token_list **current_token_node_p,
	t_ast *new_node, t_parse_command_info *info)
{
	int	token_type;

	token_type = get_token_type(*current_token_node_p);
	if (token_type >= TOKEN_CNTLOP_PIPE
		&& token_type <= TOKEN_CNTLOP_R_PARENTHESE)
		return (BREAK);
	else if ((token_type >= TOKEN_REDIROP_IN
			&& token_type <= TOKEN_REDIROP_OUT_APPEND)
		|| token_type == TOKEN_REDIROP_AMBIGUOUS)
		ft_lstadd_back(&new_node->redir_list,
			parse_redir(ctx, current_token_node_p));
	else if (token_type == TOKEN_WORD)
		_add_cmd_args(current_token_node_p, new_node,
			info, get_token_word(*current_token_node_p));
	else
	{
		info->noop_flag = true;
		*current_token_node_p = (*current_token_node_p)->next;
	}
	return (CONTINUE);
}

static t_ast	*_parse_command_core(
	t_ctx *ctx, t_token_list **current_token_node_p, t_ast *new_node)
{
	t_parse_command_info	info;

	info.arg_count = 0;
	info.arg_cap = 10;
	info.noop_flag = false;
	new_node->cmd_args = (char **)xmalloc(sizeof(char *) * (info.arg_cap));
	while (*current_token_node_p != NULL)
	{
		if (_parse_command_core_switch(
				ctx, current_token_node_p, new_node, &info) == BREAK)
			break ;
	}
	if (info.arg_count == 0
		&& (info.noop_flag == true || new_node->redir_list != NULL))
		_add_cmd_args(NULL, new_node, &info, ":");
	else if (info.arg_count == 0 && new_node->redir_list == NULL)
		return (free(new_node->cmd_args), NULL);
	return (new_node);
}

// If the first token is TOKEN_CNTLOP_L_PARENTHESE,
//  call parse_subshell() and parse as a subshell
//  until TOKEN_CNTLOP_R_PARENTHESE appears, and then continue parsing
//  until one of the following control operator tokens:
//  - TOKEN_CNTLOP_PIPE
//  - TOKEN_CNTLOP_AND_LIST
//  - TOKEN_CNTLOP_OR_LIST
//  - TOKEN_CNTLOP_R_PARENTHESE
//  or NULL termination of the token list appears.
// Otherwise, parse as a command
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
//   (if we didn't go to parse_subshell,
//    i.e., if the first token is not TOKEN_CNTLOP_L_PARENTHESE)
//    - TOKEN_CNTLOP_L_PARENTHESE
t_ast	*parse_command(t_ctx *ctx, t_token_list **current_token_node_p)
{
	t_ast	*new_node;

	if (*current_token_node_p == NULL)
		return (NULL);
	if (get_token_type(*current_token_node_p) == TOKEN_CNTLOP_L_PARENTHESE)
		return (parse_subshell(ctx, current_token_node_p));
	new_node = (t_ast *)xmalloc(sizeof(t_ast));
	new_node->type = AST_COMMAND;
	new_node->cmd_args = NULL;
	new_node->subshell_ast = NULL;
	new_node->redir_list = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	if (_parse_command_core(ctx, current_token_node_p, new_node) == NULL)
		return (free(new_node), NULL);
	return (new_node);
}
