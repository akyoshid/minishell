/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast_visual.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:00:00 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/04 01:15:42 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	print_ast_node_visual(
				t_ast *ast_node, const char *prefix, int is_last);

static char	*get_child_prefix(const char *prefix, int is_last)
{
	if (is_last)
		return (ft_xstrjoin(prefix, "   "));
	else
		return (ft_xstrjoin(prefix, "│  "));
}

static void	print_ast_children(t_ast *ast_node, const char *new_prefix)
{
	if (ast_node->left != NULL)
	{
		if (ast_node->right == NULL)
			print_ast_node_visual(ast_node->left, new_prefix, 1);
		else
			print_ast_node_visual(ast_node->left, new_prefix, 0);
	}
	if (ast_node->right != NULL)
		print_ast_node_visual(ast_node->right, new_prefix, 1);
}

static void	print_ast_node_visual(
	t_ast *ast_node, const char *prefix, int is_last)
{
	char	*new_prefix;
	char	*node_prefix;

	if (ast_node == NULL)
		return ;
	if (is_last)
		node_prefix = "└─ ";
	else
		node_prefix = "├─ ";
	printf("%s%s", prefix, node_prefix);
	print_node_type(ast_node);
	printf("\n");
	new_prefix = get_child_prefix(prefix, is_last);
	print_args(ast_node, new_prefix);
	print_redirections(ast_node, new_prefix);
	if (ast_node->type == AST_SUBSHELL && ast_node->subshell_ast != NULL)
		print_ast_node_visual(ast_node->subshell_ast, new_prefix, 1);
	else
		print_ast_children(ast_node, new_prefix);
	free(new_prefix);
}

void	print_ast_visual(t_ast *ast)
{
	printf("===== AST Structure =====\n");
	if (ast != NULL)
		print_ast_node_visual(ast, "", 1);
	else
		printf("(empty)\n");
	printf("=========================\n");
}
