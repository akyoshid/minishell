/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:00:01 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/14 01:10:16 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// If an error occurs in a function that handles a file,
//  print the file name rather than the function name.
void	print_error(char *mes1, char *mes2, char *mes3, bool use_errno)
{
	int	errno_cp;

	if (mes1 == NULL && mes2 == NULL && mes3 == NULL && use_errno == false)
		return ;
	errno_cp = errno;
	ft_dprintf(2, "minishell");
	if (mes1 != NULL)
		ft_dprintf(2, ": %s", mes1);
	if (mes2 != NULL)
		ft_dprintf(2, ": %s", mes2);
	if (mes3 != NULL)
		ft_dprintf(2, ": %s", mes3);
	if (use_errno == true)
		ft_dprintf(2, ": %s", strerror(errno_cp));
	ft_dprintf(2, "\n");
}
