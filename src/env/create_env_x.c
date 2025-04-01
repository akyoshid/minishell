/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:59:41 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/01 14:17:27 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_env_list	*create_env_node(char *key, char *value)
{
	t_env	*content;

	if (ft_strchr(value, '\'') != NULL || ft_strchr(value, '\"') != NULL)
	{
		ft_dprintf(STDERR_FILENO,
			"minishell: `%s=%s': "
			"value contains forbidden quote character\n", key, value);
		exit(EXIT_USAGE);
	}
	content = (t_env *)xmalloc(sizeof(t_env));
	content->key = key;
	content->value = value;
	return (ft_xlstnew(content));
}

t_env_list	*create_env_list(char **envp)
{
	char		*equal_p;
	char		*key;
	char		*value;
	t_env_list	*head;

	head = NULL;
	while (*envp != NULL)
	{
		equal_p = ft_strchr(*envp, '=');
		key = ft_xstrndup(*envp, equal_p - *envp);
		value = ft_xstrdup(equal_p + 1);
		ft_lstadd_back(&head, create_env_node(key, value));
		envp++;
	}
	return (head);
}
