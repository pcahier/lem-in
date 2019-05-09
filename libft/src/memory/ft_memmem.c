/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 00:40:05 by agrossma          #+#    #+#             */
/*   Updated: 2018/08/08 03:02:57 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmem(const void *big, size_t big_len, const void *little,
		size_t little_len)
{
	t_byte	*b;
	t_byte	*l;
	char	*last;
	char	*cur;

	b = (t_byte *)big;
	l = (t_byte *)little;
	if (big_len < little_len || big_len == 0 || little_len == 0)
		return (NULL);
	if (little_len == 1)
		return (ft_memchr(big, (int)*l, big_len));
	last = (char *)b + big_len - little_len;
	cur = (char *)b;
	while (cur <= last)
	{
		if (cur[0] == l[0] && ft_memcmp(cur, l, little_len) == 0)
			return ((void *)cur);
		cur++;
	}
	return (NULL);
}
