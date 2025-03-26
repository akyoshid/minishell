/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_token_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:12:26 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/25 21:15:20 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	set_token_type(t_token_list *token_node, int type)
{
	if (token_node == NULL)
		return ;
	((t_token *)token_node->content)->type = type;
}

void	set_token_word(t_token_list *token_node, char *word)
{
	if (token_node == NULL)
		return ;
	((t_token *)token_node->content)->word = word;
}
