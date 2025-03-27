/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:52:23 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/27 12:21:32 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	_replace_key_to_value(
	t_ctx *ctx, char **word_p, int *i_p, int var_key_len)
{
	char	*var_key;
	char	*var_value;
	int		var_value_len;
	char	*new_word;

	var_key = ft_xstrndup(*word_p + *i_p + 1, var_key_len);
	var_value = search_env_value(ctx->env_list, var_key);
	if (var_value == NULL)
		var_value = "";
	var_value_len = ft_strlen(var_value);
	new_word = xmalloc(
			ft_strlen(*word_p) + var_value_len - (var_key_len + 1) + 1);
	ft_strncpy(new_word, *word_p, *i_p);
	ft_strncpy(new_word + *i_p, var_value, var_value_len);
	ft_strcpy(
		new_word + *i_p + var_value_len, *word_p + *i_p + 1 + var_key_len);
	*i_p = *i_p + var_value_len;
	free(var_key);
	free(*word_p);
	*word_p = new_word;
}

static void	_expand_env_core(t_ctx *ctx, char **word_p, int *i_p)
{
	int		var_key_len;

	var_key_len = 0;
	while (is_avail_char_for_var_name((*word_p)[*i_p + 1 + var_key_len]) == 1)
	{
		var_key_len++;
		if (var_key_len == 1 && ft_isdigit((*word_p)[*i_p + 1]) == 1)
			break ;
	}
	if (var_key_len == 0)
		(*i_p)++;
	else
		_replace_key_to_value(ctx, word_p, i_p, var_key_len);
}

static void	_expand_env_in_double_quote(t_ctx *ctx, char **word_p, int *i_p)
{
	(*i_p)++;
	while ((*word_p)[*i_p] != '\"')
	{
		if ((*word_p)[*i_p] == '$')
			_expand_env_core(ctx, word_p, i_p);
		else
			(*i_p)++;
	}
	(*i_p)++;
}

static void	_expand_env_in_single_quote(char **word_p, int *i_p)
{
	(*i_p)++;
	while ((*word_p)[*i_p] != '\'')
		(*i_p)++;
	(*i_p)++;
}

void	expand_env(t_ctx *ctx, char **word_p)
{
	int		i;

	i = 0;
	while ((*word_p)[i] != '\0')
	{
		if ((*word_p)[i] == '\'')
			_expand_env_in_single_quote(word_p, &i);
		else if ((*word_p)[i] == '\"')
			_expand_env_in_double_quote(ctx, word_p, &i);
		else if ((*word_p)[i] == '$')
			_expand_env_core(ctx, word_p, &i);
		else
			i++;
	}
}
