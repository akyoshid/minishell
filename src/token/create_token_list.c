/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:40:49 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/22 18:33:52 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_token_list	*create_token_list(char **input_p, t_token_list *head)
{
	t_token_list	*token_list;
	int				i;
	int				char_type;
	t_token_list	*new_token_node;

	token_list = NULL;
	i = 0;
	while (1)
	{
		char_type = get_char_type((*input_p)[i]);
		if (char_type == CHAR_NON_METACHAR
			|| char_type == CHAR_METACHAR_NON_SPACE)
		{
			if (char_type == CHAR_NON_METACHAR)
				new_token_node = create_word_token_node(input_p, &i);
			else
				new_token_node = create_op_token_node(input_p, &i);
			if (new_token_node == NULL)
			{
				clear_token_list(&head);
				return (NULL);
			}
			ft_lstadd_back(&token_list, new_token_node);
		}
		else if (char_type == CHAR_METACHAR_SPACE)
			i++;
		else if (char_type == CHAR_NULLCHAR)
			break ;
	}
	if (head == NULL)
		head = token_list;
	else
		ft_lstadd_back(&head, token_list);
	// check_syntax (headに対して)
	// here_doc (token_listに対して)
	// (が閉じられていなかったり(つまり;で終了している)、&&, ||, |で終了しているものを処理
		// readline
		// create_token_list()
			// 再起的な呼び出しになる
			// 完全なリストの完成が終了条件
	return (token_list);
}
