/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_operand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:08:41 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/13 18:12:18 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*get_operand(t_cmd_info *cmd_info, int index)
{
	int	first_operand_index;

	first_operand_index = 1 + cmd_info->option_count;
	if (cmd_info->double_dash_flag == true)
		first_operand_index++;
	return (cmd_info->args[first_operand_index + index]);
}
