/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:30:21 by agrossma          #+#    #+#             */
/*   Updated: 2018/10/26 00:07:13 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrealloc(void *ptr, size_t new_size, size_t old_size)
{
	void	*new;

	if (ptr == NULL)
		return (ft_memalloc(new_size));
	else if (new_size == 0)
	{
		ft_memdel(&ptr);
		return (NULL);
	}
	if (new_size <= old_size)
		return (ptr);
	if (!(new = ft_memalloc(new_size)))
		return (NULL);
	ft_memcpy(new, ptr, old_size);
	ft_memdel(&ptr);
	return (new);
}
