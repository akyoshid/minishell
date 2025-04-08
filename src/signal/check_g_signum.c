/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_g_signum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:59:18 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/02 21:08:16 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_g_signum(void)
{
	if (g_signum == SIGINT)
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		rl_done = 1;
	}
	return (0);
}
