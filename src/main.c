/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:13:06 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/20 17:30:34 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	_init_ctx(t_ctx *ctx, char **envp)
{
	init_env_list(envp, ctx);
	ctx->exit_status = EXIT_SUCCESS;
}

static int	_is_empty_input(char *input)
{
	char	*trimmed_input;

	trimmed_input = ft_xstrtrim(input, "\t\n ");
	if (ft_strcmp(trimmed_input, "") == 0)
	{
		free(trimmed_input);
		free(input);
		return (1);
	}
	else
	{
		free(trimmed_input);
		return (0);
	}
}

static void	_reader_loop(t_ctx *ctx)
{
	char	*input;

	(void)ctx;
	rl_outstream = stderr;
	while (1)
	{
		input = readline("minishell$ ");
		if (input == NULL)
		{
			ft_dprintf(STDERR_FILENO, "exit\n");
			break ;
		}
		if (ft_strcmp(input, "exit") == 0) // handle exit as command
			break ;
		if (_is_empty_input(input) == 1)
			continue ;
		// exec command
		if (input[0] != '\t' && input[0] != '\n' && input[0] != ' ')
			add_history(input);
		free(input);
	}
	rl_clear_history();
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
	_reader_loop(&ctx);
	_clear_ctx(&ctx);
	return (ctx.exit_status);
}
