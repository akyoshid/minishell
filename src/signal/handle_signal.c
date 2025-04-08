/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:03:48 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/08 13:16:52 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	_set_signum(int signum)
{
	g_signum = signum;
}

static void	_set_sigaction(int signum, void (*handler)(int))
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
void	handle_signal(t_ctx *ctx)
{
	if (g_signum != 0)
	{
		ctx->exit_status = 128 + g_signum;
		g_signum = 0;
	}
	_set_sigaction(SIGINT, _set_signum);
	_set_sigaction(SIGQUIT, SIG_IGN);
}

void	reset_signal_handler(void)
{
	_set_sigaction(SIGINT, SIG_DFL);
	_set_sigaction(SIGQUIT, SIG_DFL);
}
