/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_op_token_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:39:59 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/22 17:07:38 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	_get_op_token_type_redir_in(char **input_p, int *i_p)
{
	(*i_p)++;
	if ((*input_p)[*i_p] != '<')
		return (TOKEN_REDIROP_IN);
	else
	{
		(*i_p)++;
		if ((*input_p)[*i_p] != '-')
			return (TOKEN_REDIROP_IN_HEREDOC);
		else
		{
			(*i_p)++;
			return (TOKEN_REDIROP_IN_HEREDOC_DEL_TAB);
		}
	}
}

static int	_get_op_token_type_redir_out(char **input_p, int *i_p)
{
	(*i_p)++;
	if ((*input_p)[*i_p] != '>')
		return (TOKEN_REDIROP_OUT);
	else
	{
		(*i_p)++;
		return (TOKEN_REDIROP_OUT_APPEND);
	}
}

static int	_get_op_token_type_and_list(char **input_p, int *i_p)
{
	(*i_p)++;
	if ((*input_p)[*i_p] == '&')
	{
		(*i_p)++;
		return (TOKEN_CNTLOP_AND_LIST);
	}
	else
	{
		ft_dprintf(2, "minishell: syntax error near unexpected token `&'\n");
		return (TOKEN_UNDEFINED);
	}
}

static int	_get_op_token_type_pipe_or_or_list(char **input_p, int *i_p)
{
	(*i_p)++;
	if ((*input_p)[*i_p] != '|')
		return (TOKEN_CNTLOP_PIPE);
	else
	{
		(*i_p)++;
		return (TOKEN_CNTLOP_OR_LIST);
	}
}

t_token_list	*create_op_token_node(char **input_p, int *i_p)
{
	t_token	*content;

	content = (t_token *)xmalloc(sizeof(t_token));
	content->word = NULL;
	if ((*input_p)[*i_p] == '<')
		content->type = _get_op_token_type_redir_in(input_p, i_p);
	else if ((*input_p)[*i_p] == '>')
		content->type = _get_op_token_type_redir_out(input_p, i_p);
	else if ((*input_p)[*i_p] == '&')
		content->type = _get_op_token_type_and_list(input_p, i_p);
	else if ((*input_p)[*i_p] == '|')
		content->type = _get_op_token_type_pipe_or_or_list(input_p, i_p);
	else
	{
		if ((*input_p)[*i_p] == '(')
			content->type = TOKEN_CNTLOP_L_PARENTHESE;
		else if ((*input_p)[*i_p] == ')')
			content->type = TOKEN_CNTLOP_R_PARENTHESE;
		else if ((*input_p)[*i_p] == ';')
			content->type = TOKEN_CNTLOP_SEMICOLON_LIST;
		(*i_p)++;
	}
	if (content->type == TOKEN_UNDEFINED)
		return (free(content), NULL);
	return (ft_xlstnew(content));
}
