/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:41:14 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/31 22:28:49 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	_get_rand_bytes(unsigned char *dst, int len)
{
	int	fd;
	int	read_rv;

	if (len <= 0)
		return (-1);
	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
	{
		print_error("/dev/urandom", NULL, NULL, true);
		return (-1);
	}
	read_rv = read(fd, dst, len);
	if (read_rv == -1)
	{
		print_error("read", NULL, NULL, true);
		return (close(fd), -1);
	}
	else if (read_rv != len)
	{
		print_error("read",
			"Failed to read the specified number of bytes", NULL, false);
		return (close(fd), -1);
	}
	return (close(fd), 0);
}

char	*get_heredoc_path(void)
{
	char			*tmp_file_path;
	unsigned char	rand[10];
	int				i;

	tmp_file_path = (char *)xmalloc(23);
	ft_strlcpy(tmp_file_path, "/tmp/sh-thd-", 23);
	if (_get_rand_bytes(rand, 10) != 0)
		return (free(tmp_file_path), NULL);
	i = 0;
	while (i < 10)
	{
		rand[i] = rand[i] % 36;
		if (rand[i] <= 9)
			tmp_file_path[i + 12] = rand[i] + '0';
		else
			tmp_file_path[i + 12] = rand[i] - 10 + 'a';
		i++;
	}
	tmp_file_path[22] = '\0';
	return (tmp_file_path);
}
