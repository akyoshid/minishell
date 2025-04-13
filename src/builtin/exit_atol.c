/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_atol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 00:26:17 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/13 13:46:00 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	_handle_error_non_numeric(
	t_ctx *ctx, char *arg, bool *fin_flag)
{
	if (ctx->in_pipe_flag == false)
	{
		ft_dprintf(STDERR_FILENO,
			"exit\nminishell: exit: %s: numeric argument required\n", arg);
		close_std_io_dup(ctx);
		exit(EXIT_USAGE);
	}
	else
	{
		ft_dprintf(STDERR_FILENO,
			"minishell: exit: %s: numeric argument required\n", arg);
		ctx->exit_status = EXIT_USAGE;
		*fin_flag = true;
	}
}

static void	_atol_proc_prefix(char **str_p, int *sign_p)
{
	while (**str_p == '\t' || **str_p == '\n' || **str_p == '\v'
		|| **str_p == '\f' || **str_p == '\r' || **str_p == ' ')
		(*str_p)++;
	*sign_p = 1;
	if (**str_p == '-')
		*sign_p = -1;
	if (**str_p == '+' || **str_p == '-')
		(*str_p)++;
}

long	exit_atol(t_ctx *ctx, char *str, bool *fin_flag)
{
	char	*original_str;
	long	num;
	int		sign;

	original_str = str;
	_atol_proc_prefix(&str, &sign);
	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (sign == 1
			&& (num > LONG_MAX / 10 || (num == LONG_MAX / 10 && *str > '7')))
			_handle_error_non_numeric(ctx, original_str, fin_flag);
		if (sign == -1
			&& (num > LONG_MAX / 10 || (num == LONG_MAX / 10 && *str > '8')))
			_handle_error_non_numeric(ctx, original_str, fin_flag);
		num = num * 10 + (*str - '0');
		str++;
	}
	while (*str == '\t' || *str == ' ')
		str++;
	if (*str != '\0' || *original_str == '\0')
		_handle_error_non_numeric(ctx, original_str, fin_flag);
	return (num * sign);
}
