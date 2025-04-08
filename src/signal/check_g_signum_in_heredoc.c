/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_g_signum_in_heredoc.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 23:37:30 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/02 23:37:51 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_g_signum_in_heredoc(void)
{
	if (g_signum == SIGINT)
		rl_done = 1;
	return (0);
}
