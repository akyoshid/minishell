/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 07:57:08 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/14 02:19:55 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*_get_path_cmd_is_path(t_ctx *ctx, char *cmd)
{
	char	*path;

	path = ft_xstrdup(cmd);
	if (access(path, F_OK) != 0)
	{
		print_error(cmd, NULL, NULL, true);
		ctx->exit_status = EXIT_NOTFOUND;
		free(path);
		return (NULL);
	}
	if (is_directory(path) == 1 || access(path, X_OK) != 0)
	{
		print_error(path, NULL, NULL, true);
		ctx->exit_status = EXIT_NOTEXEC;
		free(path);
		return (NULL);
	}
	return (path);
}

static char	*_get_path_env_path_is_empty(t_ctx *ctx, char *cmd)
{
	char	*path;

	path = ft_xstrjoin("./", cmd);
	if (access(path, F_OK) != 0)
	{
		print_error(cmd, NULL, NULL, true);
		ctx->exit_status = EXIT_NOTFOUND;
		free(path);
		return (NULL);
	}
	if (is_directory(path) == 1 || access(path, X_OK) != 0)
	{
		print_error(cmd, NULL, NULL, true);
		ctx->exit_status = EXIT_NOTEXEC;
		free(path);
		return (NULL);
	}
	return (path);
}

static void	_handle_path_not_found(
	t_ctx *ctx, char *cmd, char *last_match_path, int errno_cp)
{
	if (last_match_path == NULL)
	{
		print_error(cmd, "command not found", NULL, false);
		ctx->exit_status = EXIT_NOTFOUND;
	}
	else
	{
		errno = errno_cp;
		print_error(last_match_path, NULL, NULL, true);
		ctx->exit_status = EXIT_NOTEXEC;
		free(last_match_path);
	}
}

static char	*_get_path_env_path_is_not_empty(
	t_ctx *ctx, char *cmd, char **env_path_list, char *slash_cmd)
{
	char	*path;
	char	*last_match_path;
	int		errno_cp;
	int		i;

	last_match_path = NULL;
	errno_cp = 0;
	i = 0;
	while (env_path_list[i] != NULL)
	{
		path = ft_xstrjoin(env_path_list[i], slash_cmd);
		if (access(path, F_OK) == 0)
		{
			if (is_directory(path) != 1 && access(path, X_OK) == 0)
				return (free(last_match_path), path);
			free(last_match_path);
			last_match_path = path;
			errno_cp = errno;
		}
		else
			free(path);
		i++;
	}
	_handle_path_not_found(ctx, cmd, last_match_path, errno_cp);
	return (NULL);
}

// On success, it returns executable path.
// On error, it returns NULL.
// You must free() executable path.
char	*get_path(t_ctx *ctx, char *cmd)
{
	char	*env_path_value;
	char	**env_path_list;
	char	*slash_cmd;
	char	*path;

	if (cmd[0] == '\0' || ft_strcmp(cmd, ".") == 0 || ft_strcmp(cmd, "..") == 0)
	{
		print_error(cmd, "command not found", NULL, false);
		return (ctx->exit_status = EXIT_NOTFOUND, NULL);
	}
	if (ft_strchr(cmd, '/') != NULL)
		return (_get_path_cmd_is_path(ctx, cmd));
	env_path_value = search_env_value(ctx, ctx->env_list, "PATH");
	if (env_path_value == NULL || env_path_value[0] == '\0')
		return (_get_path_env_path_is_empty(ctx, cmd));
	else
	{
		env_path_list = ft_xsplit(env_path_value, ':');
		slash_cmd = ft_xstrjoin("/", cmd);
		path = _get_path_env_path_is_not_empty(
				ctx, cmd, env_path_list, slash_cmd);
		free_2d_array(env_path_list);
		free(slash_cmd);
		return (path);
	}
}
