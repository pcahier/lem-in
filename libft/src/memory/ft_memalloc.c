/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:51:00 by agrossma          #+#    #+#             */
/*   Updated: 2017/11/13 17:41:18 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocate (with malloc) and return a new memory area (initialized with 0s)
** \param size The size of the memory area to allocate
** \return The memory area or NULL if fail
*/

void	*ft_memalloc(size_t size)
{
	void	*area;

	NULL_CHECK((area = malloc(size)));
	ft_bzero(area, size);
	return (area);
}
