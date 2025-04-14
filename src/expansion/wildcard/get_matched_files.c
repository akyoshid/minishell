/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matched_files.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:30:00 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/14 09:17:44 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static int	_handle_reading_period(char *pattern, char *d_name)
{
	if (ft_strcmp(d_name, ".") == 0 || ft_strcmp(d_name, "..") == 0)
		return (0);
	if (d_name[0] == '.')
	{
		if (pattern[0] == '.')
			return (1);
		else
			return (0);
	}
	return (1);
}

static int	_count_matched_files(char *pattern)
{
	DIR				*dir;
	struct dirent	*entry;
	int				count;

	dir = opendir(".");
	if (dir == NULL)
	{
		print_error("opendir", NULL, NULL, true);
		return (0);
	}
	count = 0;
	while (1)
	{
		entry = readdir(dir);
		if (entry == NULL)
			break ;
		if (_handle_reading_period(pattern, entry->d_name) == 0)
			continue ;
		if (is_pattern_matched(pattern, entry->d_name))
			count++;
	}
	closedir(dir);
	return (count);
}

static void	_fill_matched_files(char **matched_files, char *pattern, int count)
{
	DIR				*dir;
	struct dirent	*entry;
	int				i;

	dir = opendir(".");
	if (dir == NULL)
	{
		print_error("opendir", NULL, NULL, true);
		return ;
	}
	i = 0;
	while (i < count)
	{
		entry = readdir(dir);
		if (entry == NULL)
			break ;
		if (_handle_reading_period(pattern, entry->d_name) == 0)
			continue ;
		if (is_pattern_matched(pattern, entry->d_name))
		{
			matched_files[i] = ft_xstrdup(entry->d_name);
			i++;
		}
	}
	closedir(dir);
}

static char	**_handle_get_matched_files_error(char *pattern, int *count_p)
{
	char	**matched_files;

	matched_files = (char **)ft_xcalloc(2, sizeof(char *));
	matched_files[0] = ft_xstrdup(pattern);
	*count_p = 1;
	return (matched_files);
}

char	**get_matched_files(char *pattern, int *count_p)
{
	char	**matched_files;

	if (has_wildcard(pattern) != 1)
		return (_handle_get_matched_files_error(pattern, count_p));
	*count_p = _count_matched_files(pattern);
	if (*count_p == 0)
		return (_handle_get_matched_files_error(pattern, count_p));
	matched_files = (char **)ft_xcalloc(*count_p + 1, sizeof(char *));
	_fill_matched_files(matched_files, pattern, *count_p);
	if (matched_files[0] == NULL)
		return (_handle_get_matched_files_error(pattern, count_p));
	return (matched_files);
}
