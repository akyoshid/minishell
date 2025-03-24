/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:40:49 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/24 17:20:12 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static t_token_list	*_create_token_node(char **input_p, int char_type)
{
	if (char_type == CHAR_NON_METACHAR)
		return (create_word_token_node(input_p));
	else
		return (create_op_token_node(input_p));
}

t_token_list	*create_token_list(char *input)
{
	t_token_list	*token_list;
	int				char_type;
	t_token_list	*new_token_node;

	token_list = NULL;
	while (1)
	{
		char_type = get_char_type(*input);
		if (char_type == CHAR_NON_METACHAR
			|| char_type == CHAR_METACHAR_NON_SPACE)
		{
			new_token_node = _create_token_node(&input, char_type);
			if (new_token_node == NULL)
				return (clear_token_list(&token_list), NULL);
			ft_lstadd_back(&token_list, new_token_node);
		}
		else if (char_type == CHAR_METACHAR_SPACE)
			input++;
		else if (char_type == CHAR_NULLCHAR)
			break ;
	}
	if (check_syntax(token_list) == SYNTAX_ERROR)
		return (clear_token_list(&token_list), NULL);
	return (token_list);
}
