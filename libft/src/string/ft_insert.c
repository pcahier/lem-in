/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 23:03:13 by agrossma          #+#    #+#             */
/*   Updated: 2018/12/06 10:55:26 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_insert(char *s1, const char *s2, size_t pos)
{
	char	*new;

	new = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (new == NULL)
		return (NULL);
	ft_strncpy(new, s1, pos);
	ft_strcat(new, s2);
	ft_strcat(new, s1 + pos);
	ft_strdel(&s1);
	return (new);
}
