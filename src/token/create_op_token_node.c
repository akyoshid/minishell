/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_op_token_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:39:59 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/23 17:48:37 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	_get_op_token_type_redir_in(char **input_p)
{
	(*input_p)++;
	if (**input_p != '<')
		return (TOKEN_REDIROP_IN);
	else
	{
		(*input_p)++;
		if (**input_p != '-')
			return (TOKEN_REDIROP_IN_HEREDOC);
		else
		{
			(*input_p)++;
			return (TOKEN_REDIROP_IN_HEREDOC_DEL_TAB);
		}
	}
}

static int	_get_op_token_type_redir_out(char **input_p)
{
	(*input_p)++;
	if (**input_p != '>')
		return (TOKEN_REDIROP_OUT);
	else
	{
		(*input_p)++;
		return (TOKEN_REDIROP_OUT_APPEND);
	}
}

static int	_get_op_token_type_pipe_and_or_list(char **input_p)
{
	(*input_p)++;
	if (*(*input_p - 1) == '&')
	{
		if (**input_p == '&')
		{
			(*input_p)++;
			return (TOKEN_CNTLOP_AND_LIST);
		}
		else
		{
			ft_dprintf(2, "minishell: "
				"syntax error near unexpected token `&'\n");
			return (TOKEN_UNDEFINED);
		}
	}
	else
	{
		if (**input_p == '|')
		{
			(*input_p)++;
			return (TOKEN_CNTLOP_OR_LIST);
		}
		else
			return (TOKEN_CNTLOP_PIPE);
	}
}

static int	_get_op_token_type_semicolon_list(void)
{
	ft_dprintf(2, "minishell: syntax error near unexpected token `;'\n");
	return (TOKEN_UNDEFINED);
}

t_token_list	*create_op_token_node(char **input_p)
{
	t_token	*content;

	content = (t_token *)xmalloc(sizeof(t_token));
	content->word = NULL;
	if (**input_p == '<')
		content->type = _get_op_token_type_redir_in(input_p);
	else if (**input_p == '>')
		content->type = _get_op_token_type_redir_out(input_p);
	else if (**input_p == '&' || **input_p == '|')
		content->type = _get_op_token_type_pipe_and_or_list(input_p);
	else
	{
		if (**input_p == '(')
			content->type = TOKEN_CNTLOP_L_PARENTHESE;
		else if (**input_p == ')')
			content->type = TOKEN_CNTLOP_R_PARENTHESE;
		else if (**input_p == ';')
			content->type = _get_op_token_type_semicolon_list();
		(*input_p)++;
	}
	if (content->type == TOKEN_UNDEFINED)
		return (free(content), NULL);
	return (ft_xlstnew(content));
}
