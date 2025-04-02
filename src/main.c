/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:13:06 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/02 12:57:03 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	_init_ctx(t_ctx *ctx, char **envp)
{
	init_env_list(envp, ctx);
	ctx->exit_status = EXIT_SUCCESS;
}

static void	_clear_ctx(t_ctx *ctx)
{
	clear_env_list(&ctx->env_list);
}

int	main(int argc, char **argv, char **envp)
{
	t_ctx	ctx;

	(void)argc;
	(void)argv;
	_init_ctx(&ctx, envp);
	reader_loop(&ctx);
	_clear_ctx(&ctx);
	return (ctx.exit_status);
}
