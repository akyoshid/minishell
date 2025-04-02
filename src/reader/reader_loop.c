/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:56:14 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/02 22:37:40 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

volatile sig_atomic_t	g_signum = 0;

void	exec_input(t_ctx *ctx, char *input)
{
	t_token_list	*token_list;
	t_ast			*ast;

	token_list = create_token_list(input);
	if (token_list == NULL)
	{
		ctx->exit_status = EXIT_USAGE;
		return ;
	}
	perform_expansion(ctx, &token_list);
	print_token_list(token_list);
	ast = parse_token_list_into_ast(ctx, token_list);
	if (ast == NULL)
	{
		clear_token_list(&token_list);
		return ;
	}
	clear_token_list(&token_list);
	print_ast(ast);
	clear_ast(ast);
	// exec_ast
}

void	reader_loop(t_ctx *ctx)
{
	char	*input;
	char	*prev_input;

	input = NULL;
	prev_input = NULL;
	rl_outstream = stderr;
	rl_event_hook = check_g_signum;
	while (1)
	{
		handle_signal(ctx);
		input = readline("minishell$ ");
		if (input == NULL)
		{
			ft_dprintf(STDERR_FILENO, "exit\n");
			break ;
		}
		if (is_empty_input(input) == 1)
			continue ;
		ctx->exit_status = 0;
		exec_input(ctx, input);
		update_history(&input, &prev_input);
	}
	free(input);
	free(prev_input);
	rl_clear_history();
}
