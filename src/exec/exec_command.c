/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 02:29:02 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/08 11:43:16 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	exec_command(t_ctx *ctx, t_ast *ast_node)
{
	if (setup_redir(ctx, ast_node->redir_list) == -1)
		return ;
	if (ast_node->cmd_args == NULL)
		return ;
	if (check_cmd_is_builtin(ast_node->cmd_args[0]) == true)
		exec_builtin_command(ctx, ast_node->cmd_args);
	else
		exec_external_command(ctx, ast_node);
}
