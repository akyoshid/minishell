/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 08:57:24 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/19 20:44:35 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*get_env_key(t_env_list *env_node)
{
	if (env_node == NULL)
		return (NULL);
	return (((t_env *)env_node->content)->key);
}

char	*get_env_value(t_env_list *env_node)
{
	if (env_node == NULL)
		return (NULL);
	return (((t_env *)env_node->content)->value);
}
