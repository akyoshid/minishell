/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_avail_char_for_var_name.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:08:32 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/26 14:32:23 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// In the POSIX standard,
//  environment variable names must meet the following conditions:
// 1. Only alphabetic characters (a-z, A-Z), digits (0-9), and underscores (_)
//     are allowed.
// 2. The first character cannot be a digit.
//    (It must start with an alphabetic character or an underscore).
int	is_avail_char_for_var_name(int c)
{
	if (c == '_')
		return (1);
	else if (ft_isalnum(c) == 1)
		return (1);
	else
		return (0);
}
