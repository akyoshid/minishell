/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:13:06 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/20 12:25:56 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	reader_loop(t_ctx *ctx)
{
	char	*newline;

	(void)ctx;
	rl_outstream = stderr;
	while (1)
	{
		newline = readline("minishell$ ");
		if (newline == NULL)
			break ;
		if (*newline)
			add_history(newline);
		// exec command
		if (ft_strcmp(newline, "exit") == 0)
			break ;
		free(newline);
	}
	rl_clear_history();
}

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
