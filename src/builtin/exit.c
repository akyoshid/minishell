/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:11:38 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/13 01:59:02 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	_w_exit(t_ctx *ctx, int status, bool *fin_flag)
{
	if (ctx->in_pipe_flag == false && ctx->in_subshell_flag == false)
	{
		ft_dprintf(STDERR_FILENO, "exit\n");
		close_std_io_dup(ctx);
		exit(status);
	}
	else
	{
		ctx->exit_status = status;
		*fin_flag = true;
	}
}

static void	_handle_too_many_args(t_ctx *ctx)
{
	if (ctx->in_pipe_flag == false && ctx->in_subshell_flag == false)
		ft_dprintf(STDERR_FILENO,
			"exit\nminishell: exit: too many arguments\n");
	else
		ft_dprintf(STDERR_FILENO, "minishell: exit: too many arguments\n");
	ctx->exit_status = EXIT_FAILURE;
}

void	exit_builtin(t_ctx *ctx, char **cmd_args)
{
	int		i;
	bool	fin_flag;
	long	num;

	i = 1;
	fin_flag = false;
	if (cmd_args[1] != NULL && ft_strcmp(cmd_args[1], "--") == 0)
		i++;
	if (cmd_args[i] == NULL)
		_w_exit(ctx, ctx->exit_status, &fin_flag);
	if (fin_flag == true)
		return ;
	num = exit_atol(ctx, cmd_args[i], &fin_flag);
	if (fin_flag == true)
		return ;
	i++;
	if (cmd_args[i] == NULL)
		_w_exit(ctx, num, &fin_flag);
	else
		_handle_too_many_args(ctx);
}
