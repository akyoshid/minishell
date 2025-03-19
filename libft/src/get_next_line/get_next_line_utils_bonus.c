/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:03:37 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/22 02:41:16 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line_bonus.h"

// ### DESCRIPTION
// - Free `f_p->leftover` and `*p_p`, and assign NULL.
// - `p_p` will receive `&readbuff`, `&line`, or NULL.
// - If return_value is NULL, free `f_p`.
// `return_value` is NULL means there is nothing else to read in fd
// or an error has occurred.
// In that case, fd is supposed to be closed by the caller of `get_next_line()`.
// ### RETURN VALUE
// - Return `return_value`.
// ### ATTENTION
// - It is guaranteed that `leftover` passed to `return_value` is not NULL.
char	*gnl_free(t_fd *f_p, char **p_p, char *return_value)
{
	if (p_p != NULL)
	{
		free(*p_p);
		*p_p = NULL;
	}
	if (f_p != NULL)
	{
		if (return_value != NULL)
		{
			f_p->leftover[f_p->lo_len] = '\0';
			f_p->leftover = NULL;
			f_p->lo_len = 0;
		}
		else
		{
			free(f_p->leftover);
			delete_fd_node(f_p);
		}
	}
	return (return_value);
}

void	delete_fd_node(t_fd *f_p)
{
	if (f_p->fd == 0)
	{
		f_p->leftover = NULL;
		f_p->lo_len = 0;
		return ;
	}
	(f_p->prev)->next = f_p->next;
	if (f_p->next != NULL)
		(f_p->next)->prev = f_p->prev;
	free(f_p);
	f_p = NULL;
}

t_fd	*new_fd_node(t_fd *last_node, int fd)
{
	t_fd	*new_node;

	new_node = (t_fd *)malloc(1 * sizeof(t_fd));
	if (new_node == NULL)
		return (NULL);
	new_node->fd = fd;
	new_node->leftover = NULL;
	new_node->lo_eol_i = 0;
	new_node->lo_len = 0;
	new_node->readbuff = NULL;
	new_node->rb_len = 0;
	new_node->prev = last_node;
	new_node->next = NULL;
	last_node->next = new_node;
	return (new_node);
}

// ### RETURN VALUE
// - Return the node that corresponds to fd.
// - If there is no node that corresponds to fd,
// create a new node with the new_fd_node() & return it.
// - If fd < 0, return NULL.
// - If no node match fd & malloc() in new_fd_node() fail, return NULL.
// ### DESCRIPTION
// - The argument `lst` is guaranteed to be not NULL.
t_fd	*get_fd_node(t_fd *lst, int fd, int *return_code)
{
	t_fd	*last_node;

	if (fd < 0)
	{
		*return_code = GNL_FAILURE_FD;
		return (NULL);
	}
	while (lst != NULL)
	{
		if (lst->fd == fd)
			break ;
		last_node = lst;
		lst = lst->next;
	}
	if (lst == NULL)
		lst = new_fd_node(last_node, fd);
	if (lst == NULL)
		return (NULL);
	return (lst);
}
