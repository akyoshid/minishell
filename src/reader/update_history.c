/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:28:04 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/02 13:28:34 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	update_history(char **input_p, char **prev_input_p)
{
	if ((*input_p)[0] != '\t' && (*input_p)[0] != '\n' && (*input_p)[0] != ' '
		&& ft_strcmp(*prev_input_p, *input_p) != 0)
	{
		add_history(*input_p);
		free(*prev_input_p);
		*prev_input_p = *input_p;
		*input_p = NULL;
	}
	else
	{
		free(*input_p);
		*input_p = NULL;
	}
}
