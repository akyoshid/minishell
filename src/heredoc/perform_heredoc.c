/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 23:09:19 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/01 12:14:27 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	_init_heredoc_info(
	t_heredoc_info *info, t_redir *content, int token_type)
{
	info->delimiter = content->word;
	info->tmp_file_path = NULL;
	info->delete_tab_flag = false;
	info->no_expand_flag = false;
	if (token_type == TOKEN_REDIROP_IN_HEREDOC_DEL_TAB
		|| token_type == TOKEN_REDIROP_IN_HEREDOC_DEL_TAB_NO_EXPAND)
		info->delete_tab_flag = true;
	else if (token_type == TOKEN_REDIROP_IN_HEREDOC_NO_EXPAND
		|| token_type == TOKEN_REDIROP_IN_HEREDOC_DEL_TAB_NO_EXPAND)
		info->no_expand_flag = true;
}

static int	_handle_null_new_line(t_heredoc_info *info, int gnl_return_code)
{
	if (gnl_return_code == GNL_SUCCESS_FIN)
	{
		ft_dprintf(2, "\nminishell: warning: here-document "
			"delimited by end-of-file (wanted `%s')\n", info->delimiter);
		return (HEREDOC_READER_LOOP_SUCCESS);
	}
	else
	{
		if (gnl_return_code == GNL_FAILURE_BUFFER_SIZE)
			print_error("get_next_line", "Invalid BUFFER_SIZE", NULL, false);
		else if (gnl_return_code == GNL_FAILURE_FD)
			print_error("get_next_line", "Invalid fd", NULL, false);
		else if (gnl_return_code == GNL_FAILURE_MALLOC)
		{
			print_error("malloc", "cannot allocate memory", NULL, false);
			exit(EXIT_USAGE);
		}
		else if (gnl_return_code == GNL_FAILURE_READ)
			print_error("read", NULL, NULL, true);
		return (HEREDOC_READER_LOOP_FAILURE);
	}
}

static int	_handle_non_null_new_line(
	t_ctx *ctx, t_heredoc_info *info, char *new_line)
{
	if (info->delete_tab_flag == true)
		delete_tab(new_line);
	if (cmp_delimiter(info->delimiter, new_line) == 0)
	{
		free(new_line);
		return (HEREDOC_READER_LOOP_SUCCESS);
	}
	else
	{
		if (info->no_expand_flag == false)
			expand_env_heredoc(ctx, &new_line);
		if (write(info->fd, new_line, ft_strlen(new_line)) == -1)
		{
			print_error("write", NULL, NULL, true);
			free(new_line);
			return (HEREDOC_READER_LOOP_FAILURE);
		}
		free(new_line);
		return (HEREDOC_READER_LOOP_CONTINUE);
	}
}

// new_line must be freed within _handle_non_null_new_line
static int	_heredoc_reader_loop(t_ctx *ctx, t_heredoc_info *info)
{
	char	*new_line;
	int		gnl_return_code;
	int		status;

	status = HEREDOC_READER_LOOP_CONTINUE;
	while (status == HEREDOC_READER_LOOP_CONTINUE)
	{
		ft_dprintf(2, "> ");
		new_line = get_next_line(0, &gnl_return_code);
		if (new_line == NULL)
			status = _handle_null_new_line(info, gnl_return_code);
		else
			status = _handle_non_null_new_line(ctx, info, new_line);
	}
	return (status);
}

// On success, perform_heredoc() returns 0.
// On error, it returns -1.
int	perform_heredoc(t_ctx *ctx, t_redir *content, int token_type)
{
	t_heredoc_info	info;
	int				status;

	_init_heredoc_info(&info, content, token_type);
	info.tmp_file_path = get_heredoc_path();
	if (info.tmp_file_path == NULL)
		return (-1);
	info.fd = open(info.tmp_file_path, O_CREAT | O_EXCL | O_WRONLY, 0666);
	if (info.fd == -1)
		return (print_error(info.tmp_file_path, NULL, NULL, true),
			free(info.tmp_file_path), -1);
	status = _heredoc_reader_loop(ctx, &info);
	close(info.fd);
	free(content->word);
	content->word = info.tmp_file_path;
	if (status == HEREDOC_READER_LOOP_SUCCESS)
		return (0);
	else
		return (-1);
}
