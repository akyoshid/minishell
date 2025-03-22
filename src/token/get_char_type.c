/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:39:20 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/21 09:39:37 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// A metacharacter is a space, tab, newline,
//  or one of the following characters: ‘|’, ‘&’, ‘;’, ‘(’, ‘)’, ‘<’, or ‘>’.
// In minishell, ';' is not supported.
int	get_char_type(char c)
{
	if (c == '\0')
		return (CHAR_NULLCHAR);
	else if (c == ' ' || c == '\t' || c == '\n')
		return (CHAR_METACHAR_SPACE);
	else if (c == '|' || c == '&' || c == ';'
		|| c == '(' || c == ')' || c == '<' || c == '>')
		return (CHAR_METACHAR_NON_SPACE);
	else
		return (CHAR_NON_METACHAR);
}
