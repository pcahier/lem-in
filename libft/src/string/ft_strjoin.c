/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:51:01 by agrossma          #+#    #+#             */
/*   Updated: 2018/03/20 17:02:29 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocate with malloc and return a fresh string finished by a '\0' resulting
** in the concatenation of s1 and s2.
** \param s1 The prefix string
** \param s2 The suffix string
** \return The fresh string or NULL if the allocation failed
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	join = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	MALLOC_CHECK(join);
	i = 0;
	j = 0;
	while (s1[i])
		join[j++] = s1[i++];
	i = 0;
	while (s2[i])
		join[j++] = s2[i++];
	return (join);
}
