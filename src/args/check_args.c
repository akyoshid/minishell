/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:13:10 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/12 11:13:27 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// On success, it returns 0.
// On error, it returns -1.
int	check_args(t_ctx *ctx, t_cmd_info *cmd_info)
{
	if (count_option(ctx, cmd_info) == -1)
		return (-1);
	if (count_operand(ctx, cmd_info) == -1)
		return (-1);
	return (0);
}
