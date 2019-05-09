/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:51:00 by agrossma          #+#    #+#             */
/*   Updated: 2017/11/10 13:53:13 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const t_byte	*s;
	t_byte			*d;
	t_byte			x;
	size_t			i;

	s = (const t_byte *)src;
	d = (t_byte *)dst;
	i = n;
	x = (t_byte)c;
	while (i--)
		if ((*d++ = *s++) == x)
			return (d);
	return (NULL);
}
