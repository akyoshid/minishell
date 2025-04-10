/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:19:46 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/10 17:20:12 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// On success, it returns 0.
// On error, it returns -1.
int	setup_pipe(t_pipe_fd_set *pipe_fd_set)
{
	if (w_dup2(pipe_fd_set->current_read, STDIN_FILENO) == -1)
	{
		print_error("dup2", NULL, NULL, true);
		close_pipe_fd_set(pipe_fd_set);
		return (-1);
	}
	if (w_dup2(pipe_fd_set->current_write, STDOUT_FILENO) == -1)
	{
		print_error("dup2", NULL, NULL, true);
		close_pipe_fd_set(pipe_fd_set);
		return (-1);
	}
	close_pipe_fd_set(pipe_fd_set);
	return (0);
}
