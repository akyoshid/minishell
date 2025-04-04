/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token_list_into_ast.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:47:58 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/02 22:36:56 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_ast	*parse_token_list_into_ast(t_ctx *ctx, t_token_list *token_list)
{
	t_ast	*ast;

	ast = parse_and_or(ctx, &token_list);
	if (ctx->exit_status != 0)
	{
		clear_ast(ast);
		return (NULL);
	}
	return (ast);
}
