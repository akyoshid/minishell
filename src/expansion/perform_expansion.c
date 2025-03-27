/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:59:35 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/26 19:09:32 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// Scheduled to add expand_filenameexpand_filename
void	perform_expansion(t_ctx *ctx, t_token_list **token_list_p)
{
	expand_env_in_token_list(ctx, token_list_p);
	// remove_quote(token_list_p);
}
