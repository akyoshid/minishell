/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 20:11:39 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/30 20:31:26 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	clear_cmd_args(char **cmd_args)
{
	int	i;

	if (cmd_args == NULL)
		return ;
	i = 0;
	while (cmd_args[i] != NULL)
	{
		free(cmd_args[i]);
		i++;
	}
	free(cmd_args);
}

void	clear_redir_node_content(void *void_content)
{
	t_redir	*content;

	content = (t_redir *)void_content;
	free(content->word);
	free(content);
}

void	clear_redir_list(t_redir_list **redir_list)
{
	ft_lstclear(redir_list, clear_redir_node_content);
}

void	clear_ast(t_ast *ast)
{
	if (ast == NULL)
		return ;
	clear_ast(ast->left);
	clear_ast(ast->right);
	if (ast->type == AST_COMMAND)
	{
		clear_cmd_args(ast->cmd_args);
		clear_redir_list(&ast->redir_list);
	}
	else if (ast->type == AST_SUBSHELL)
	{
		clear_ast(ast->subshell_ast);
		clear_redir_list(&ast->redir_list);
	}
	free(ast);
}
