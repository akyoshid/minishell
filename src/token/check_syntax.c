/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 06:43:43 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/22 18:35:01 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

enum e_check_syntax_return_value
{
	SYNTAX_OK,
	SYNTAX_ERROR,
};

void	print_syntax_error(int current_token_type)
{
	ft_dprintf(2, "minishell: syntax error near unexpected token ");
	if (current_token_type == NO_TOKEN)
		ft_dprintf(2, "`newline'\n");
	else if (current_token_type == TOKEN_REDIROP_IN)
		ft_dprintf(2, "`<'\n");
	else if (current_token_type == TOKEN_REDIROP_IN_HEREDOC)
		ft_dprintf(2, "`<<'\n");
	else if (current_token_type == TOKEN_REDIROP_IN_HEREDOC_DEL_TAB)
		ft_dprintf(2, "`<<-'\n");
	else if (current_token_type == TOKEN_REDIROP_OUT)
		ft_dprintf(2, "`>'\n");
	else if (current_token_type == TOKEN_REDIROP_OUT_APPEND)
		ft_dprintf(2, "`>>'\n");
	else if (current_token_type == TOKEN_CNTLOP_PIPE)
		ft_dprintf(2, "`|'\n");
	else if (current_token_type == TOKEN_CNTLOP_AND_LIST)
		ft_dprintf(2, "`&&'\n");
	else if (current_token_type == TOKEN_CNTLOP_OR_LIST)
		ft_dprintf(2, "`||'\n");
	else if (current_token_type == TOKEN_CNTLOP_SEMICOLON_LIST)
		ft_dprintf(2, "`;'\n");
	else if (current_token_type == TOKEN_CNTLOP_L_PARENTHESE)
		ft_dprintf(2, "`('\n");
	else if (current_token_type == TOKEN_CNTLOP_R_PARENTHESE)
		ft_dprintf(2, "`)'\n");
}

int	check_syntax_current_is_head(int head_token_type)
{
	if (head_token_type == NO_TOKEN
		|| head_token_type == TOKEN_WORD
		|| head_token_type == TOKEN_REDIROP_IN
		|| head_token_type == TOKEN_REDIROP_IN_HEREDOC
		|| head_token_type == TOKEN_REDIROP_IN_HEREDOC_DEL_TAB
		|| head_token_type == TOKEN_REDIROP_OUT
		|| head_token_type == TOKEN_REDIROP_OUT_APPEND
		|| head_token_type == TOKEN_CNTLOP_L_PARENTHESE)
		return (SYNTAX_OK);
	else
	{
		print_syntax_error(head_token_type);
		return (SYNTAX_ERROR);
	}
}

int	check_syntax_prev_is_word(int current_token_type)
{
	return (SYNTAX_OK);
}

int	check_syntax_prev_is_redirop(int current_token_type, bool in_proc_quote)
{
	if (current_token_type == NO_TOKEN && in_proc_quote == true
		|| current_token_type == TOKEN_WORD)
		return (SYNTAX_OK);
	else
	{
		print_syntax_error(current_token_type);
		return (SYNTAX_ERROR);
	}
}

int	check_syntax_prev_is_redirop_in_heredoc(
	int current_token_type, bool in_proc_quote)
{
	if (current_token_type == NO_TOKEN && in_proc_quote == true
		|| current_token_type == TOKEN_WORD)
		return (SYNTAX_OK);
	else
	{
		print_syntax_error(current_token_type);
		return (SYNTAX_ERROR);
	}
}

int	check_syntax_prev_is_cntlop_pipe(int current_token_type, bool in_proc_quote)
{
	if (current_token_type == NO_TOKEN)
	if (current_token_type == NO_TOKEN && in_proc_quote == false)
	else if (current_token_type == NO_TOKEN && in_proc_quote == true)
	else if (current_token_type == TOKEN_WORD)
	else if (current_token_type == TOKEN_REDIROP_IN)
	else if (current_token_type == TOKEN_REDIROP_IN_HEREDOC)
	else if (current_token_type == TOKEN_REDIROP_IN_HEREDOC_DEL_TAB)
	else if (current_token_type == TOKEN_REDIROP_OUT)
	else if (current_token_type == TOKEN_REDIROP_OUT_APPEND)
	else if (current_token_type == TOKEN_CNTLOP_PIPE)
	else if (current_token_type == TOKEN_CNTLOP_AND_LIST)
	else if (current_token_type == TOKEN_CNTLOP_OR_LIST)
	else if (current_token_type == TOKEN_CNTLOP_SEMICOLON_LIST)
	else if (current_token_type == TOKEN_CNTLOP_L_PARENTHESE)
	else if (current_token_type == TOKEN_CNTLOP_R_PARENTHESE)
		return (SYNTAX_OK);
	else
	{
		print_syntax_error(current_token_type);
		return (SYNTAX_ERROR);
	}
}

int	check_syntax_prev_is_(int current_token_type, bool in_proc_quote)
{
	if (current_token_type == NO_TOKEN)
	if (current_token_type == NO_TOKEN && in_proc_quote == false)
	else if (current_token_type == NO_TOKEN && in_proc_quote == true)
	else if (current_token_type == TOKEN_WORD)
	else if (current_token_type == TOKEN_REDIROP_IN)
	else if (current_token_type == TOKEN_REDIROP_IN_HEREDOC)
	else if (current_token_type == TOKEN_REDIROP_IN_HEREDOC_DEL_TAB)
	else if (current_token_type == TOKEN_REDIROP_OUT)
	else if (current_token_type == TOKEN_REDIROP_OUT_APPEND)
	else if (current_token_type == TOKEN_CNTLOP_PIPE)
	else if (current_token_type == TOKEN_CNTLOP_AND_LIST)
	else if (current_token_type == TOKEN_CNTLOP_OR_LIST)
	else if (current_token_type == TOKEN_CNTLOP_SEMICOLON_LIST)
	else if (current_token_type == TOKEN_CNTLOP_L_PARENTHESE)
	else if (current_token_type == TOKEN_CNTLOP_R_PARENTHESE)
		return (SYNTAX_OK);
	else
	{
		print_syntax_error(current_token_type);
		return (SYNTAX_ERROR);
	}
}

// 文法を確認する関数
// エラーがあれば即exit
int	check_syntax(t_token_list *token_list, bool in_proc_quote)
{
	t_token_list	*current_token_node;
	int				prev_token_type;
	int				current_token_type;
	int				r_parenthese_count;

	current_token_node = token_list;
	prev_token_type = NO_TOKEN;
	r_parenthese_count = 0;
	while (1)
	{
		current_token_type = get_token_type(current_token_node);
		if (current_token_type == TOKEN_CNTLOP_R_PARENTHESE)
			r_parenthese_count++;
		if (current_token_type == TOKEN_CNTLOP_L_PARENTHESE)
		{
			r_parenthese_count--;
			if (r_parenthese_count < 0)
				print_syntax_error(TOKEN_CNTLOP_L_PARENTHESE); // なんかしないと
		}
		if (prev_token_type == -1)
			check_syntax_current_is_head(current_token_type);
		else if (prev_token_type == TOKEN_WORD)
			check_syntax_prev_is_word(current_token_type);
		else if (prev_token_type == TOKEN_REDIROP_IN
			|| prev_token_type == TOKEN_REDIROP_IN_HEREDOC
			|| prev_token_type == TOKEN_REDIROP_IN_HEREDOC_DEL_TAB
			|| prev_token_type == TOKEN_REDIROP_OUT
			|| prev_token_type == TOKEN_REDIROP_OUT_APPEND)
			check_syntax_prev_is_redirop(current_token_type, in_proc_quote);
		else if (prev_token_type == TOKEN_CNTLOP_PIPE)
			check_syntax_prev_is_cntlop_pipe(current_token_type);
		else if (prev_token_type == TOKEN_CNTLOP_AND_LIST)
			check_syntax_prev_is_cntlop_and_list(current_token_type);
		else if (prev_token_type == TOKEN_CNTLOP_OR_LIST)
			check_syntax_prev_is_cntlop_or_list(current_token_type);
		else if (prev_token_type == TOKEN_CNTLOP_SEMICOLON_LIST)
			check_syntax_prev_is_cntlop_semicolon_list(current_token_type);
		else if (prev_token_type == TOKEN_CNTLOP_L_PARENTHESE)
			check_syntax_prev_is_cntlop_l_parenthese(current_token_type);
		else if (prev_token_type == TOKEN_CNTLOP_R_PARENTHESE)
			check_syntax_prev_is_cntlop_r_parenthese(current_token_type);
		if (current_token_node == NULL)
		{
			if (prev_token_type == TOKEN_WORD)
			break ;
		}
		prev_token_type = current_token_type;
		current_token_node = current_token_node->next;
	}
	



	current_token_type = get_token_type(token_list);
	if ((current_token_type >= TOKEN_WORD
		&& current_token_type <= TOKEN_REDIROP_OUT_APPEND)
		|| current_token_type == TOKEN_CNTLOP_L_PARENTHESE)
}
