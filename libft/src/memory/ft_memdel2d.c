/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossm@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:29:39 by agrossma          #+#    #+#             */
/*   Updated: 2018/04/09 12:04:47 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel2d(void **array)
{
	int		i;

	if (array == NULL || *array == NULL)
		return ;
	i = 0;
	while (array[i])
		ft_memdel(&(array[i++]));
	free(array);
}
