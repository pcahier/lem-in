/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:51:00 by agrossma          #+#    #+#             */
/*   Updated: 2017/11/11 14:16:09 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocate (with malloc) and returns a new link. The members of the new link
** are initialized by copy of the funtion's parameters.
** \param content The content to add inside the new link
** \param content_size The size of the content to add in the new link
** \return The new link or NULL if the allocation failed
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;

	if ((elem = (t_list *)ft_memalloc(sizeof(t_list))) != NULL)
	{
		if (content == NULL)
		{
			elem->content = NULL;
			elem->content_size = 0;
		}
		else
		{
			elem->content = ft_memalloc(content_size);
			elem->content = ft_memcpy(elem->content, content, content_size);
			elem->content_size = content_size;
		}
		elem->next = NULL;
	}
	return (elem);
}
