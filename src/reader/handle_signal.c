/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:03:48 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/02 20:25:36 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	_set_up_sigint_flag(int signum)
{
	g_sigint_flag = true;
	(void)signum;
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
	if (g_sigint_flag == true)
	{
		g_sigint_flag = false;
		ctx->exit_status = 128 + SIGINT;
	}
	_set_sigaction(SIGINT, _set_up_sigint_flag);
	_set_sigaction(SIGQUIT, SIG_IGN);
}
