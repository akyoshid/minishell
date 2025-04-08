/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:51:34 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/08 11:24:32 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	_check_n_option(char *cmd_arg)
{
	int	i;

	i = 0;
	if (cmd_arg[i] != '-')
		return (false);
	i++;
	while (cmd_arg[i] != '\0')
	{
		if (cmd_arg[i] != 'n')
			return (false);
		i++;
	}
	if (i == 1)
		return (false);
	else
		return (true);
}

static int	_count_n_option(char **cmd_args)
{
	int	count;

	count = 0;
	while (1)
	{
		if (cmd_args[count + 1] == NULL)
			return (count);
		if (_check_n_option(cmd_args[count + 1]) == false)
			return (count);
		else
			count++;
	}
}

static void	_print_args(char **cmd_args)
{
	while (*cmd_args != NULL)
	{
		ft_printf("%s", *cmd_args);
		cmd_args++;
		if (*cmd_args != NULL)
			ft_printf(" ");
	}
}

void	echo_builtin(t_ctx *ctx, char **cmd_args)
{
	int	n_option_count;

	n_option_count = _count_n_option(cmd_args);
	_print_args(cmd_args + 1 + n_option_count);
	if (n_option_count == 0)
		ft_printf("\n");
	ctx->exit_status = EXIT_SUCCESS;
}
