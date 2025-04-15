/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trap_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:03:48 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/15 19:35:07 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	_set_signum(int signum)
{
	g_signum = signum;
}

static void	_w_sigaction(int signum, void (*handler)(int))
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(struct sigaction));
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if (sigaction(signum, &sa, NULL))
		print_error("sigaction", NULL, NULL, true);
}

// Ctrl-C -> SIGINT
// Ctrl-\ -> SIGQUIT
void	trap_signal_in_rl(t_ctx *ctx)
{
	if (g_signum != 0)
	{
		ctx->exit_status = 128 + g_signum;
		g_signum = 0;
	}
	_w_sigaction(SIGINT, _set_signum);
	_w_sigaction(SIGQUIT, SIG_IGN);
}

void	trap_signal_out_of_rl(t_ctx *ctx)
{
	_w_sigaction(SIGINT, SIG_IGN);
	if (g_signum != 0)
	{
		ctx->exit_status = 128 + g_signum;
		g_signum = 0;
	}
}

void	reset_signal_handler(void)
{
	_w_sigaction(SIGINT, SIG_DFL);
	_w_sigaction(SIGQUIT, SIG_DFL);
}
