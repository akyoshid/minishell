/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 23:09:19 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/30 23:57:56 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	perform_heredoc(t_ctx *ctx, t_redir *content, int token_type)
{
	char	*temp_file_path;
	bool	delete_tab_flag;
	bool	no_expand_flag;

	temp_file_path = NULL;
	delete_tab_flag = false;
	no_expand_flag = false;
	if (token_type == TOKEN_REDIROP_IN_HEREDOC_DEL_TAB
		|| token_type == TOKEN_REDIROP_IN_HEREDOC_DEL_TAB_NO_EXPAND)
		delete_tab_flag = true;
	else if (token_type == TOKEN_REDIROP_IN_HEREDOC_NO_EXPAND
		|| token_type == TOKEN_REDIROP_IN_HEREDOC_DEL_TAB_NO_EXPAND)
		no_expand_flag = true;
	(void)ctx;
	(void)content;
	(void)temp_file_path;
	(void)delete_tab_flag;
	(void)no_expand_flag;
	// temp_file_path = exec_heredoc_core(
	// 		ctx, content->word, delete_tab_flag, no_expand_flag);
	// free(content->word);
	// content->word = temp_file_path;
}
