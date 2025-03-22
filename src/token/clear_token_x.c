/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_token_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:36:44 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/21 09:38:38 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	clear_token_node_content(void *void_content)
{
	t_token	*content;

	content = (t_token *)void_content;
	free(content->word);
	free(content);
}

void	clear_token_list(t_token_list **token_list)
{
	ft_lstclear(token_list, clear_token_node_content);
}
