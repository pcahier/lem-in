/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:27:40 by agrossma          #+#    #+#             */
/*   Updated: 2018/04/09 13:29:57 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_memsize(void *ptr)
{
	size_t			size;
	unsigned char	*copy;

	size = 0;
	copy = (unsigned char *)ptr;
	while (copy[size])
		size++;
	return (size);
}
