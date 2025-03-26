/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:41:28 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/26 18:13:55 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	_print_token_type(int token_type)
{
	if (token_type == TOKEN_REDIROP_IN)
		printf("TOKEN_REDIROP_IN\n");
	else if (token_type == TOKEN_REDIROP_IN_HEREDOC)
		printf("TOKEN_REDIROP_IN_HEREDOC\n");
	else if (token_type == TOKEN_REDIROP_IN_HEREDOC_DEL_TAB)
		printf("TOKEN_REDIROP_IN_HEREDOC_DEL_TAB\n");
	else if (token_type == TOKEN_REDIROP_OUT)
		printf("TOKEN_REDIROP_OUT\n");
	else if (token_type == TOKEN_REDIROP_OUT_APPEND)
		printf("TOKEN_REDIROP_OUT_APPEND\n");
	else if (token_type == TOKEN_CNTLOP_PIPE)
		printf("TOKEN_CNTLOP_PIPE\n");
	else if (token_type == TOKEN_CNTLOP_AND_LIST)
		printf("TOKEN_CNTLOP_AND_LIST\n");
	else if (token_type == TOKEN_CNTLOP_OR_LIST)
		printf("TOKEN_CNTLOP_OR_LIST\n");
	else if (token_type == TOKEN_CNTLOP_L_PARENTHESE)
		printf("TOKEN_CNTLOP_L_PARENTHESE\n");
	else if (token_type == TOKEN_CNTLOP_R_PARENTHESE)
		printf("TOKEN_CNTLOP_R_PARENTHESE\n");
	else if (token_type == TOKEN_NOOP)
		printf("TOKEN_NOOP\n");
}

void	print_token_list(t_token_list *token_list)
{
	t_token_list	*current_node;
	int				token_type;

	current_node = token_list;
	while (current_node != NULL)
	{
		token_type = get_token_type(current_node);
		if (token_type == TOKEN_WORD)
			printf("%s\n", get_token_word(current_node));
		else
			_print_token_type(token_type);
		current_node = current_node->next;
	}
}
