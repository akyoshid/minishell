/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:56:14 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/02 12:59:50 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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
	clear_token_list(&token_list);
	print_ast(ast);
	clear_ast(ast);
	// exec_ast
}

void	reader_loop(t_ctx *ctx)
{
	char	*input;
	char	*prev_input;

	prev_input = NULL;
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
		exec_input(ctx, input);
		if (input[0] != '\t' && input[0] != '\n' && input[0] != ' '
			&& ft_strcmp(prev_input, input) != 0)
		{
			add_history(input);
			free(prev_input);
			prev_input = input;
			input = NULL;
		}
		else
		{
			free(input);
			input = NULL;
		}
	}
	free(input);
	free(prev_input);
	rl_clear_history();
}
