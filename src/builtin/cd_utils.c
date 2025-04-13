/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:12:08 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/13 20:43:21 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// On success, it returns 0.
// On error, it returns -1.
int	w_chdir(t_ctx *ctx, char *path)
{
	if (chdir(path) == -1)
	{
		print_error("cd", path, NULL, true);
		ctx->exit_status = EXIT_FAILURE;
		return (-1);
	}
	return (0);
}

static char	get_last_char(char *str)
{
	int	i;

	if (str == NULL || str[0] == '\0')
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (str[i - 1]);
}

void	update_wd_data(t_ctx *ctx, char *path)
{
	char	*new_cwd;

	new_cwd = getcwd(NULL, 0);
	if (new_cwd == NULL)
	{
		if (errno == ENOENT)
		{
			ft_dprintf(STDERR_FILENO, "minishell: cd: error retrieving current "
				"directory: getcwd: cannot access parent directories: "
				"No such file or directory\n");
			if (get_last_char(ctx->cwd) == '/')
				new_cwd = ft_xstrjoin(ctx->cwd, path);
			else
				new_cwd = ft_xstrjoin3(ctx->cwd, "/", path);
		}
		else
		{
			print_error("cd", "getcwd", NULL, true);
			new_cwd = ft_xstrdup(path);
		}
	}
	update_env_node(&ctx->env_list, "OLDPWD", ctx->cwd, false);
	update_env_node(&ctx->env_list, "PWD", new_cwd, false);
	free(ctx->cwd);
	ctx->cwd = new_cwd;
}
