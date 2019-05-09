/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 09:41:01 by agrossma          #+#    #+#             */
/*   Updated: 2018/08/12 09:46:26 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcalloc(size_t count, size_t size)
{
	void	*zone;
	size_t	n;

	n = count * size;
	if ((zone = ft_memalloc(n)) == NULL)
		return (NULL);
	return (ft_memset(zone, 0, n));
}
