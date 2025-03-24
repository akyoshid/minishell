/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prev_is_redirop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:29:04 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/24 19:29:19 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_syntax_prev_is_redirop(int current_token_type)
{
	if (current_token_type == TOKEN_WORD)
		return (SYNTAX_OK);
	else
	{
		print_syntax_error(current_token_type, NULL);
		return (SYNTAX_ERROR);
	}
}
