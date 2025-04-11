/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_valid_option.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 22:35:07 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/11 22:42:01 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// If there are no invalid options, return 0.
// If there are some invalid options, return the index of first invalid option.
static int	_get_invalid_option_i(char *option, char *valid_option_set)
{
	int	i;

	i = 1;
	while (option[i] != '\0')
	{
		if (valid_option_set == NULL)
			return (i);
		if (ft_strchr(valid_option_set, option[i]) != NULL)
			i++;
		else
			return (i);
	}
	return (0);
}

// If there are no invalid options, return the number of options.
// If there are some invalid options, return -1.
int	count_valid_option(
	t_ctx *ctx, char **cmd_args, char *valid_option_set, char *usage)
{
	int	i;
	int	inv_option_i;

	i = 1;
	while (cmd_args[i] != NULL)
	{
		if (cmd_args[i][0] != '-' || (cmd_args[i][0] == '-'
			&& (cmd_args[i][1] == '\0' || cmd_args[i][1] == '-')))
			break ;
		else
		{
			inv_option_i = _get_invalid_option_i(cmd_args[i], valid_option_set);
			if (inv_option_i == 0)
				i++;
			else
			{
				ft_dprintf(STDERR_FILENO,
					"minishell: %s: -%c: invalid option\n%s: usage: %s\n",
					cmd_args[0], cmd_args[i][inv_option_i], cmd_args[0], usage);
				ctx->exit_status = EXIT_USAGE;
				return (-1);
			}
		}
	}
	return (i - 1);
}
