/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:16:02 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/01 11:26:57 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	expand_env_heredoc(t_ctx *ctx, char **new_line_p)
{
	int	i;

	i = 0;
	while ((*new_line_p)[i] != '\0')
	{
		if ((*new_line_p)[i] == '$')
			expand_env_core(ctx, new_line_p, &i);
		else
			i++;
	}
}
