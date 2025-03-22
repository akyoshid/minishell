/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:42:04 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/22 17:14:57 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	get_token_type(t_token_list *token_node)
{
	if (token_node == NULL)
		return (NO_TOKEN);
	return (((t_token *)token_node->content)->type);
}

char	*get_token_word(t_token_list *token_node)
{
	if (token_node == NULL)
		return (NULL);
	return (((t_token *)token_node->content)->word);
}
