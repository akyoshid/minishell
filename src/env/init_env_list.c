/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:43:39 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/13 23:51:30 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

#define DEFPATH "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"

static int	_shlvl_strtol(char *str)
{
	char	*endptr;
	long	value;

	if (str == NULL || *str == '\0')
		return (0);
	errno = 0;
	value = ft_strtol_base_10(str, &endptr);
	if (errno != 0 || endptr == str)
		return (0);
	while (*endptr == ' ' || *endptr == '\t')
		endptr++;
	if (*endptr != '\0')
		return (0);
	return (value);
}

static void	_set_shlvl(t_ctx *ctx)
{
	char	*old_level_str;
	long	level;
	char	*new_level_str;

	old_level_str = search_env_value(ctx, ctx->env_list, "SHLVL");
	level = _shlvl_strtol(old_level_str);
	level++;
	if (level < 0)
		level = 0;
	else if (level >= 1000)
	{
		new_level_str = ft_xltoa(level);
		ft_dprintf(STDERR_FILENO,
			"minishell: warning: shell level (%s) too high, resetting to 1\n",
			new_level_str);
		free(new_level_str);
		level = 1;
	}
	new_level_str = ft_xitoa(level);
	update_env_node(&ctx->env_list, "SHLVL", new_level_str, false);
	free(new_level_str);
}

void	init_env_list(char **envp, t_ctx *ctx)
{
	ctx->env_list = create_env_list(envp);
	if (search_env_node(ctx->env_list, "PATH") == NULL)
		ft_lstadd_back(&ctx->env_list,
			create_env_node(ft_xstrdup("PATH"), ft_xstrdup(DEFPATH)));
	_set_shlvl(ctx);
}
