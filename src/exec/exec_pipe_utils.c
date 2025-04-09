/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 07:55:50 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/09 17:46:00 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	init_pipe_fd_set(t_pipe_fd_set *pipe_fd_set)
{
	pipe_fd_set->current_read = -1;
	pipe_fd_set->current_write = -1;
	pipe_fd_set->next_read = STDIN_FILENO;
}

t_pipe_fd_set	*update_pipe_fd_set(t_pipe_fd_set *pipe_fd_set, int pipe_fd[2])
{
	close_current_pipe_fd_set(pipe_fd_set);
	pipe_fd_set->current_read = pipe_fd_set->next_read;
	if (pipe_fd == NULL)
	{
		pipe_fd_set->next_read = -1;
		pipe_fd_set->current_write = STDOUT_FILENO;
	}
	else
	{
		pipe_fd_set->next_read = pipe_fd[PIPE_READ];
		pipe_fd_set->current_write = pipe_fd[PIPE_WRITE];
	}
	return (pipe_fd_set);
}

void	close_pipe_fd(int pipe_fd)
{
	if (pipe_fd != STDIN_FILENO
		&& pipe_fd != STDOUT_FILENO
		&& pipe_fd != STDERR_FILENO
		&& pipe_fd != -1)
		close(pipe_fd);
}

void	close_current_pipe_fd_set(t_pipe_fd_set *pipe_fd_set)
{
	close_pipe_fd(pipe_fd_set->current_read);
	close_pipe_fd(pipe_fd_set->current_write);
}

void	close_pipe_fd_set(t_pipe_fd_set *pipe_fd_set)
{
	close_pipe_fd(pipe_fd_set->current_read);
	close_pipe_fd(pipe_fd_set->current_write);
	close_pipe_fd(pipe_fd_set->next_read);
}
