/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast_visual_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 01:11:09 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/04 01:11:26 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	print_node_type(t_ast *ast_node)
{
	if (ast_node->type == AST_COMMAND)
	{
		printf("COMMAND");
		if (ast_node->cmd_args != NULL && ast_node->cmd_args[0] != NULL)
			printf(" '%s'", ast_node->cmd_args[0]);
	}
	else if (ast_node->type == AST_PIPE)
		printf("PIPE");
	else if (ast_node->type == AST_AND)
		printf("AND");
	else if (ast_node->type == AST_OR)
		printf("OR");
	else if (ast_node->type == AST_SUBSHELL)
		printf("SUBSHELL");
}

void	print_args(t_ast *ast_node, const char *prefix)
{
	int	i;

	if (ast_node->type == AST_COMMAND && ast_node->cmd_args != NULL)
	{
		i = 1;
		while (ast_node->cmd_args[i] != NULL)
		{
			printf("%s└─ arg[%d]: '%s'\n", prefix, i, ast_node->cmd_args[i]);
			i++;
		}
	}
}

void	print_redir_one(t_redir_list *redir, const char *prefix)
{
	int		redir_type;
	char	*redir_word;

	redir_type = get_redir_type(redir);
	redir_word = get_redir_word(redir);
	printf("%s└─ ", prefix);
	if (redir_type == REDIR_IN)
		printf("< '%s'\n", redir_word);
	else if (redir_type == REDIR_OUT)
		printf("> '%s'\n", redir_word);
	else if (redir_type == REDIR_OUT_APPEND)
		printf(">> '%s'\n", redir_word);
	else if (redir_type == REDIR_AMBIGUOUS)
		printf("<?> '%s'\n", redir_word);
}

void	print_redirections(t_ast *ast_node, const char *prefix)
{
	t_redir_list	*current;

	if ((ast_node->type == AST_COMMAND || ast_node->type == AST_SUBSHELL)
		&& ast_node->redir_list != NULL)
	{
		current = ast_node->redir_list;
		while (current != NULL)
		{
			print_redir_one(current, prefix);
			current = current->next;
		}
	}
}
