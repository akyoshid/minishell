/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcard_in_token_list.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:00:00 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/14 11:45:43 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static t_token_list	*_create_wildcard_token_node(char *word)
{
	t_token	*content;

	content = (t_token *)xmalloc(sizeof(t_token));
	content->type = TOKEN_WORD;
	content->word = ft_xstrdup(word);
	return (ft_xlstnew(content));
}

static t_token_list	*_insert_expanded_tokens(
	t_token_list *current_node, char **matched_files)
{
	t_token_list	*last_node;
	t_token_list	*current_next_node;
	int				i;

	last_node = current_node;
	current_next_node = current_node->next;
	i = 0;
	while (matched_files[i] != NULL)
	{
		if (i == 0)
		{
			free(get_token_word(current_node));
			set_token_word(current_node, ft_xstrdup(matched_files[i]));
		}
		else
		{
			last_node->next = _create_wildcard_token_node(matched_files[i]);
			last_node = last_node->next;
		}
		i++;
	}
	last_node->next = current_next_node;
	return (last_node);
}

static t_token_list	*_expand_wildcard_in_token(
	t_token_list *prev_node, t_token_list *current_node, int prev_node_type)
{
	char	*current_node_word;
	char	**matched_files;
	int		file_count;

	current_node_word = get_token_word(current_node);
	if (has_wildcard(current_node_word) != 1)
		return (current_node);
	matched_files = get_matched_files(current_node_word, &file_count);
	if (file_count > 1 && prev_node_type >= TOKEN_REDIROP_IN
		&& prev_node_type <= TOKEN_REDIROP_OUT_APPEND)
		set_token_type(prev_node, TOKEN_REDIROP_AMBIGUOUS);
	else
		current_node = _insert_expanded_tokens(current_node, matched_files);
	free_2d_array(matched_files);
	return (current_node);
}

void	expand_wildcard_in_token_list(t_token_list **token_list_p)
{
	t_token_list	*prev_node;
	t_token_list	*current_node;
	int				prev_node_type;

	if (token_list_p == NULL || *token_list_p == NULL)
		return ;
	prev_node = NULL;
	current_node = *token_list_p;
	while (current_node != NULL)
	{
		if (get_token_type(current_node) == TOKEN_WORD)
		{
			prev_node_type = get_token_type(prev_node);
			if (prev_node_type != TOKEN_REDIROP_IN_HEREDOC
				&& prev_node_type != TOKEN_REDIROP_IN_HEREDOC_DEL_TAB)
				current_node = _expand_wildcard_in_token(
						prev_node, current_node, prev_node_type);
		}
		prev_node = current_node;
		current_node = current_node->next;
	}
}
