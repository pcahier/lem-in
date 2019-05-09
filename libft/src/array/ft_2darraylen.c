/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argvlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 23:35:31 by agrossma          #+#    #+#             */
/*   Updated: 2018/04/09 12:24:26 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_2darraylen(void **array)
{
	size_t			i;
	unsigned char	**arr;

	i = 0;
	arr = (unsigned char **)array;
	if (!arr || !arr[i])
		return (0);
	while (arr[i])
		i++;
	return (i);
}
