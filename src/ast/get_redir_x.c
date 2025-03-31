/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 19:17:10 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/30 19:20:25 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	get_redir_type(t_redir_list *redir_node)
{
	if (redir_node == NULL)
		return (-1);
	return (((t_redir *)redir_node->content)->type);
}

char	*get_redir_word(t_redir_list *redir_node)
{
	if (redir_node == NULL)
		return (NULL);
	return (((t_redir *)redir_node->content)->word);
}
