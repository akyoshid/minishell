/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 08:57:24 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/12 19:37:21 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	set_env_value(t_env_list *env_node, char *value)
{
	if (env_node == NULL)
		return ;
	((t_env *)env_node->content)->value = value;
}
