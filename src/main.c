/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:13:06 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/11 15:20:16 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	_check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			ft_dprintf(STDERR_FILENO, "minishell: %s: invalid option\n"
				"Usage: minishell\n", argv[i]);
			exit(EXIT_USAGE);
		}
		i++;
	}
}

static void	_init_ctx(t_ctx *ctx, char **envp)
{
	ctx->exit_status = EXIT_SUCCESS;
	init_env_list(envp, ctx);
	init_sig_list(ctx);
	init_std_io_dup(ctx);
	ctx->stop_flag = false;
}

static void	_clear_ctx(t_ctx *ctx)
{
	clear_env_list(&ctx->env_list);
}

int	main(int argc, char **argv, char **envp)
{
	t_ctx	ctx;

	_check_args(argc, argv);
	_init_ctx(&ctx, envp);
	reader_loop(&ctx);
	_clear_ctx(&ctx);
	return (ctx.exit_status);
}
