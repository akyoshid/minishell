/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_env_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:39:44 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/19 20:57:10 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	clear_env_node_content(void *void_content)
{
	t_env	*content;

	content = (t_env *)void_content;
	free(content->key);
	free(content->value);
	free(content);
}

void	clear_env_list(t_env_list **env_list)
{
	ft_lstclear(env_list, clear_env_node_content);
}
