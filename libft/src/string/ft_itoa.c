/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:50:59 by agrossma          #+#    #+#             */
/*   Updated: 2018/03/26 17:11:14 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Calculate the lenght of an integer and his weight
** @param n The integer to calculate the length and weight
** @param len The adress of lenght of the integer
** @param weight The adress of the weight of the integer
*/

static void	ft_intlen(int n, size_t *len, int *weight)
{
	*len = 1;
	if (n >= 0)
	{
		*len = 0;
		n = -n;
	}
	*weight = 1;
	while (n / *weight < -9)
	{
		*weight *= 10;
		*len += 1;
	}
}

/*
** Allocate (with malloc) and converts the integer passed in the parameters to
** a string.
** @param n The integer to convert
** \return The string representing the integer or NULL if the allocation failed
*/

char		*ft_itoa(int n)
{
	char	*conv;
	size_t	len;
	int		weight;
	size_t	current;

	ft_intlen(n, &len, &weight);
	MALLOC_CHECK((conv = ft_strnew(len + 1)));
	current = 0;
	if (n < 0)
		conv[current++] = '-';
	if (n > 0)
		n = -n;
	while (weight >= 1)
	{
		conv[current++] = -(n / weight % 10) + 48;
		weight /= 10;
	}
	return (conv);
}
