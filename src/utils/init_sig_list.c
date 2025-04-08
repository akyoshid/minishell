/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sig_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 06:07:55 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/08 06:29:00 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	_fill_sig_list_1(t_ctx *ctx)
{
	ctx->sig_list[SIGHUP] = "Hangup";
	ctx->sig_list[SIGINT] = "Interrupt";
	ctx->sig_list[SIGQUIT] = "Quit";
	ctx->sig_list[SIGILL] = "Illegal instruction";
	ctx->sig_list[SIGTRAP] = "BPT trace/trap";
	ctx->sig_list[SIGABRT] = "ABORT instruction";
	ctx->sig_list[SIGFPE] = "Floating point exception";
	ctx->sig_list[SIGKILL] = "Killed";
	ctx->sig_list[SIGBUS] = "Bus error";
	ctx->sig_list[SIGSEGV] = "Segmentation fault";
	ctx->sig_list[SIGSYS] = "Bad system call";
	ctx->sig_list[SIGPIPE] = "Broken pipe";
	ctx->sig_list[SIGALRM] = "Alarm clock";
	ctx->sig_list[SIGTERM] = "Terminated";
}

static void	_fill_sig_list_2(t_ctx *ctx)
{
	ctx->sig_list[SIGURG] = "Urgent IO condition";
	ctx->sig_list[SIGSTOP] = "Stopped (signal)";
	ctx->sig_list[SIGTSTP] = "Stopped";
	ctx->sig_list[SIGCONT] = "Continue";
	ctx->sig_list[SIGCHLD] = "Child death or stop";
	ctx->sig_list[SIGTTIN] = "Stopped (tty input)";
	ctx->sig_list[SIGTTOU] = "Stopped (tty output)";
	ctx->sig_list[SIGIO] = "I/O ready";
	ctx->sig_list[SIGXCPU] = "CPU limit";
	ctx->sig_list[SIGXFSZ] = "File limit";
	ctx->sig_list[SIGVTALRM] = "Alarm (virtual)";
	ctx->sig_list[SIGPROF] = "Alarm (profile)";
	ctx->sig_list[SIGWINCH] = "Window changed";
	ctx->sig_list[SIGUSR1] = "User signal 1";
	ctx->sig_list[SIGUSR2] = "User signal 2";
}

void	init_sig_list(t_ctx *ctx)
{
	int	i;

	i = 0;
	while (i < NSIG)
	{
		ctx->sig_list[i] = "Unknown signal";
		i++;
	}
	_fill_sig_list_1(ctx);
	_fill_sig_list_2(ctx);
}
