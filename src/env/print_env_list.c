/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:40:11 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/19 21:25:56 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	print_env_list(t_env_list *env_list)
{
	t_env_list	*current_node;

	current_node = env_list;
	while (current_node != NULL)
	{
		printf("%s=", get_env_key(current_node));
		printf("%s\n", get_env_value(current_node));
		current_node = current_node->next;
	}
}
