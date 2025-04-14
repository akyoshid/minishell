/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_directory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 01:48:38 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/14 01:51:06 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_directory(char *path)
{
	struct stat	file_stat;

	if (stat(path, &file_stat) == -1)
		return (0);
	if (S_ISDIR(file_stat.st_mode))
	{
		errno = EISDIR;
		return (1);
	}
	else
		return (0);
}
