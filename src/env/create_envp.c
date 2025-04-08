/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 02:26:21 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/08 03:07:43 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	_count_env_node(t_env_list *env_list)
{
	int			i;
	t_env_list	*current_node;

	i = 0;
	current_node = env_list;
	while (current_node != NULL)
	{
		i++;
		current_node = current_node->next;
	}
	return (i);
}

static int	_count_env_key_len(t_env_list *env_node)
{
	char	*key;
	int		i;

	key = get_env_key(env_node);
	i = 0;
	while (key[i] != '\0')
		i++;
	return (i);
}

static int	_count_env_value_len(t_env_list *env_node)
{
	char	*value;
	int		i;

	value = get_env_value(env_node);
	i = 0;
	while (value[i] != '\0')
		i++;
	return (i);
}

char	**create_envp(t_ctx *ctx)
{
	char		**envp;
	int			i;
	t_env_list	*current_node;
	int			env_key_len;
	int			env_value_len;

	envp = (char **)xmalloc(
			(_count_env_node(ctx->env_list) + 1) * sizeof(char *));
	i = 0;
	current_node = ctx->env_list;
	while (current_node != NULL)
	{
		env_key_len = _count_env_key_len(current_node);
		env_value_len = _count_env_value_len(current_node);
		envp[i] = (char *)xmalloc(env_key_len + env_value_len + 2);
		ft_strcpy(envp[i], get_env_key(current_node));
		ft_strcpy(envp[i] + env_key_len, "=");
		ft_strcpy(envp[i] + env_key_len + 1, get_env_value(current_node));
		i++;
		current_node = current_node->next;
	}
	envp[i] = NULL;
	return (envp);
}
