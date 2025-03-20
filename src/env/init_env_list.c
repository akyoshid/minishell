/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:43:39 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/19 21:05:43 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

#define DEFPATH "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"

void	init_env_list(char **envp, t_ctx *ctx)
{
	ctx->env_list = create_env_list(envp);
	if (search_env_node(ctx->env_list, "PATH") == NULL)
		ft_lstadd_back(&ctx->env_list,
			create_env_node(ft_xstrdup("PATH"), ft_xstrdup(DEFPATH)));
}
