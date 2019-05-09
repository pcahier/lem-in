/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:51:02 by agrossma          #+#    #+#             */
/*   Updated: 2017/11/13 18:01:45 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies the function f to every character of the string s using its index
** to create a new string resulting in the succesives applications of f.
** \param s The string to iterate on
** \param f The function to apply
** \return The new string created by the applications of f
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	int				j;

	NULL_CHECK(s);
	NULL_CHECK(f);
	MALLOC_CHECK((str = ft_strdup(s)));
	i = 0;
	j = 0;
	while (s[j])
	{
		str[j] = f(i++, s[j]);
		j++;
	}
	return (str);
}
