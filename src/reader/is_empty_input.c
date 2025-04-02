/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:29:24 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/02 13:29:56 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_empty_input(char *input)
{
	char	*trimmed_input;

	trimmed_input = ft_xstrtrim(input, "\t\n ");
	if (ft_strcmp(trimmed_input, "") == 0)
	{
		free(trimmed_input);
		free(input);
		return (1);
	}
	else
	{
		free(trimmed_input);
		return (0);
	}
}
