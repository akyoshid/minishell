/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:48:38 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/29 21:07:30 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// === DESCRIPTION ===
// Resize a memory block.
// Returns a pointer to the resized memory block,
//  or NULL if the allocation fails
// @ptr: Pointer to memory block
// @old_size: Current size of the memory block
// @new_size: New size of the memory block
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	if (old_size < new_size)
		ft_memmove(new_ptr, ptr, old_size);
	else
		ft_memmove(new_ptr, ptr, new_size);
	free(ptr);
	return (new_ptr);
}
