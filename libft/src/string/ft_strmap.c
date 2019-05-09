/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:51:02 by agrossma          #+#    #+#             */
/*   Updated: 2017/11/13 18:01:29 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies the function f to every character of the string s to create a new
** string resulting in the succesives applications of f.
** \param s The string to iterate on
** \param f The function to apply
** \return The new string created by the applications of f
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	NULL_CHECK(s);
	NULL_CHECK(f);
	MALLOC_CHECK((str = ft_strdup(s)));
	i = 0;
	while (s[i])
	{
		str[i] = f(s[i]);
		i++;
	}
	return (str);
}
