/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:38:00 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/30 21:42:28 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	_print_cmd_args(char **cmd_args)
{
	if (cmd_args == NULL)
		return ;
	while (*cmd_args != NULL)
	{
		printf("%s ", *cmd_args);
		cmd_args++;
	}
}

static void	_print_redir_list(t_redir_list *redir_list)
{
	t_redir_list	*current_node;
	int				redir_type;

	current_node = redir_list;
	while (current_node != NULL)
	{
		redir_type = get_redir_type(current_node);
		if (redir_type == REDIR_IN)
			printf("< ");
		else if (redir_type == REDIR_OUT)
			printf("> ");
		else if (redir_type == REDIR_OUT_APPEND)
			printf(">> ");
		else
			printf("\033[31mError in _print_redir_list\033[0m ");
		printf("%s ", get_redir_word(current_node));
		current_node = current_node->next;
	}
}

static void	_print_ast_node(t_ast *ast_node)
{
	if (ast_node == NULL)
		return ;
	_print_ast_node(ast_node->left);
	if (ast_node->type == AST_COMMAND)
	{
		_print_cmd_args(ast_node->cmd_args);
		_print_redir_list(ast_node->redir_list);
	}
	else if (ast_node->type == AST_PIPE)
		printf("| ");
	else if (ast_node->type == AST_AND)
		printf("&& ");
	else if (ast_node->type == AST_OR)
		printf("|| ");
	else if (ast_node->type == AST_SUBSHELL)
	{
		printf("( ");
		_print_ast_node(ast_node->subshell_ast);
		printf(") ");
		_print_redir_list(ast_node->redir_list);
	}
	_print_ast_node(ast_node->right);
}

void	print_ast(t_ast *ast)
{
	_print_ast_node(ast);
	printf("\n");
}
