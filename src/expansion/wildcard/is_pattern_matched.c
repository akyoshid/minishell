/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pattern_matched.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:00:00 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/14 11:05:23 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static void	_pattern_is_wc(
	char **pattern_p, char **file_p, char **wc_pos_p, char **file_match_head_p)
{
	*wc_pos_p = *pattern_p;
	(*pattern_p)++;
	*file_match_head_p = *file_p;
}

static void	_match_with_pattern(char **pattern_p, char **file_p)
{
	(*pattern_p)++;
	(*file_p)++;
}

static void	_mismatch_with_pattern(
	char **pattern_p, char **file_p, char *wc_pos, char **file_match_head_p)
{
	*pattern_p = wc_pos + 1;
	(*file_match_head_p)++;
	*file_p = *file_match_head_p;
}

bool	is_pattern_matched(char *pattern, char *file)
{
	char	*file_match_head;
	char	*wc_pos;

	file_match_head = NULL;
	wc_pos = NULL;
	while (*file != '\0')
	{
		if (*pattern == '*')
			_pattern_is_wc(&pattern, &file, &wc_pos, &file_match_head);
		else if (*pattern == *file)
			_match_with_pattern(&pattern, &file);
		else if (wc_pos != NULL)
			_mismatch_with_pattern(&pattern, &file, wc_pos, &file_match_head);
		else
			return (false);
	}
	while (*pattern == '*')
		pattern++;
	if (*pattern == '\0')
		return (1);
	else
		return (0);
}
