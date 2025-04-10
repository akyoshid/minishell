/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal_in_heredoc.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 23:39:48 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/10 18:19:28 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	handle_signal_in_heredoc(
	t_ctx *ctx, t_token_list **current_token_node_p, char *input)
{
	free(input);
	while (*current_token_node_p != NULL)
		*current_token_node_p = (*current_token_node_p)->next;
	ctx->exit_status = 128 + g_signum;
	g_signum = 0;
	ctx->stop_flag = true;
	return (HEREDOC_READER_LOOP_FAILURE);
}
