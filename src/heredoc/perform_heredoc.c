/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 23:09:19 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/15 19:35:31 by akyoshid         ###   ########.fr       */
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

static int	_handle_null_input(t_heredoc_info *info)
{
	ft_dprintf(2, "minishell: warning: here-document "
		"delimited by end-of-file (wanted `%s')\n", info->delimiter);
	return (HEREDOC_READER_LOOP_SUCCESS);
}

static int	_handle_non_null_input(
	t_ctx *ctx, t_heredoc_info *info, char *input)
{
	if (info->delete_tab_flag == true)
		delete_tab(input);
	if (cmp_delimiter(info->delimiter, input) == 0)
	{
		free(input);
		return (HEREDOC_READER_LOOP_SUCCESS);
	}
	else
	{
		if (info->no_expand_flag == false)
			expand_env_heredoc(ctx, &input);
		if (write(info->fd, input, ft_strlen(input)) == -1
			|| write(info->fd, "\n", 1) == -1)
		{
			print_error("write", NULL, NULL, true);
			free(input);
			return (HEREDOC_READER_LOOP_FAILURE);
		}
		free(input);
		return (HEREDOC_READER_LOOP_CONTINUE);
	}
}

// input must be freed within _handle_non_null_input
static int	_heredoc_reader_loop(t_ctx *ctx,
	t_heredoc_info *info, t_token_list **current_token_node_p)
{
	char	*input;
	int		status;

	status = HEREDOC_READER_LOOP_CONTINUE;
	rl_event_hook = check_g_signum_in_heredoc;
	trap_signal_in_rl(ctx);
	while (status == HEREDOC_READER_LOOP_CONTINUE)
	{
		input = readline("> ");
		if (g_signum != 0)
			status = handle_sigint_in_heredoc(ctx, current_token_node_p, input);
		else if (input == NULL)
			status = _handle_null_input(info);
		else
			status = _handle_non_null_input(ctx, info, input);
	}
	trap_signal_out_of_rl(ctx);
	rl_event_hook = check_g_signum;
	return (status);
}

// On success, perform_heredoc() returns 0.
// On error, it returns -1.
int	perform_heredoc(t_ctx *ctx,
	t_redir *content, int token_type, t_token_list **current_token_node_p)
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
	status = _heredoc_reader_loop(ctx, &info, current_token_node_p);
	close(info.fd);
	free(content->word);
	content->word = info.tmp_file_path;
	if (status == HEREDOC_READER_LOOP_SUCCESS)
		return (0);
	else
		return (-1);
}
