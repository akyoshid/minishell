/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 06:24:27 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/08 03:19:37 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// On success, it returns 0.
// On error, it returns -1.
static int	_setup_redir_in(t_ctx *ctx, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		print_error("open", NULL, NULL, true);
		ctx->exit_status = EXIT_FAILURE;
		return (-1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		print_error("dup2", NULL, NULL, true);
		ctx->exit_status = EXIT_FAILURE;
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

// On success, it returns 0.
// On error, it returns -1.
static int	_setup_redir_out(t_ctx *ctx, char *filename, bool append_flag)
{
	int	fd;

	if (append_flag == false)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (fd == -1)
	{
		print_error("open", NULL, NULL, true);
		ctx->exit_status = EXIT_FAILURE;
		return (-1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		print_error("dup2", NULL, NULL, true);
		ctx->exit_status = EXIT_FAILURE;
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

// On success, it returns 0.
// On error, it returns -1.
static int	_setup_redir_node(t_ctx *ctx, t_redir_list *redir_node)
{
	int	redir_type;

	redir_type = get_redir_type(redir_node);
	if (redir_type == REDIR_IN)
		return (_setup_redir_in(ctx, get_redir_word(redir_node)));
	else if (redir_type == REDIR_OUT)
		return (_setup_redir_out(ctx, get_redir_word(redir_node), false));
	else if (redir_type == REDIR_OUT_APPEND)
		return (_setup_redir_out(ctx, get_redir_word(redir_node), true));
	else if (redir_type == REDIR_AMBIGUOUS)
	{
		print_error(
			get_redir_word(redir_node), "ambiguous redirect", NULL, false);
		ctx->exit_status = EXIT_FAILURE;
		return (-1);
	}
	return (0);
}

// On success, it returns 0.
// On error, it returns -1.
int	setup_redir(t_ctx *ctx, t_redir_list *redir_list)
{
	t_redir_list	*current_redir_node;

	current_redir_node = redir_list;
	while (current_redir_node != NULL)
	{
		if (_setup_redir_node(ctx, current_redir_node) == -1)
			return (-1);
		current_redir_node = current_redir_node->next;
	}
	return (0);
}
