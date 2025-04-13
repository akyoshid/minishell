/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrjoin3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:51:08 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/13 19:54:58 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_xstrjoin3(char const *s1, char const *s2, char const *s3)
{
	char	*temp1;
	char	*temp2;

	temp1 = ft_xstrjoin(s1, s2);
	temp2 = ft_xstrjoin(temp1, s3);
	free (temp1);
	return (temp2);
}
