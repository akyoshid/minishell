/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:13:06 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/13 18:23:46 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	_check_argv(t_ctx *ctx, char **argv)
{
	t_cmd_info	cmd_info;

	init_cmd_info1(&cmd_info, argv, "minishell", "");
	init_cmd_info2(&cmd_info, 0, true);
	if (check_args(ctx, &cmd_info) == -1)
		exit(ctx->exit_status);
}

static void	_init_ctx(t_ctx *ctx, char **envp)
{
	ctx->exit_status = EXIT_SUCCESS;
	ctx->cwd = getcwd(NULL, 0);
	if (ctx->cwd == NULL)
	{
		print_error("getcwd", NULL, NULL, true);
		exit(EXIT_FAILURE);
	}
	init_env_list(envp, ctx);
	init_sig_list(ctx);
	ctx->stop_flag = false;
	init_std_io_dup(ctx);
	ctx->in_pipe_flag = false;
}

static void	_clear_ctx(t_ctx *ctx)
{
	free(ctx->cwd);
	clear_env_list(&ctx->env_list);
}

int	main(int argc, char **argv, char **envp)
{
	t_ctx	ctx;

	(void)argc;
	_check_argv(&ctx, argv);
	_init_ctx(&ctx, envp);
	reader_loop(&ctx);
	_clear_ctx(&ctx);
	return (ctx.exit_status);
}
