/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:00:01 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/31 19:19:48 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// If an error occurs in a function that handles a file,
//  print the file name rather than the function name.
void	print_error(char *mes1, char *mes2, char *mes3, bool use_errno)
{
	if (mes1 == NULL && mes2 == NULL && mes3 == NULL && use_errno == false)
		return ;
	ft_dprintf(2, "minishell");
	if (mes1 != NULL)
		ft_dprintf(2, ": %s", mes1);
	if (mes2 != NULL)
		ft_dprintf(2, ": %s", mes2);
	if (mes3 != NULL)
		ft_dprintf(2, ": %s", mes3);
	if (use_errno == true)
		ft_dprintf(2, ": %s", strerror(errno));
	ft_dprintf(2, "\n");
}
