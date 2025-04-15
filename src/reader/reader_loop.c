/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:56:14 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/15 19:35:19 by akyoshid         ###   ########.fr       */
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
	ast = parse_token_list_into_ast(ctx, token_list);
	if (ast == NULL)
	{
		clear_token_list(&token_list);
		return ;
	}
	clear_token_list(&token_list);
	exec_ast(ctx, ast);
	clear_ast(ast);
}

char	*_w_readline(void)
{
	char	*input;

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && isatty(STDERR_FILENO))
		input = readline("\033[1;36mminishell\033[0m$ ");
	else
		input = readline("minishell$ ");
	return (input);
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
		trap_signal_in_rl(ctx);
		input = _w_readline();
		if (input == NULL)
		{
			ft_dprintf(STDERR_FILENO, "exit\n");
			break ;
		}
		if (is_empty_input(input) == 1)
			continue ;
		trap_signal_out_of_rl(ctx);
		exec_input(ctx, input);
		update_history(&input, &prev_input);
	}
	free(input);
	free(prev_input);
	rl_clear_history();
}
