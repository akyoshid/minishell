/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token_list_into_ast.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:47:58 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/10 18:30:07 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_ast	*parse_token_list_into_ast(t_ctx *ctx, t_token_list *token_list)
{
	t_ast	*ast;

	ctx->stop_flag = false;
	ast = parse_and_or(ctx, &token_list);
	if (ctx->stop_flag == true)
	{
		ctx->stop_flag = false;
		clear_ast(ast);
		return (NULL);
	}
	else
		return (ast);
}
