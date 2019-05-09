/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:51:01 by agrossma          #+#    #+#             */
/*   Updated: 2017/11/13 18:00:13 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies the function f to every character of the string s.
** Every character is passed by adress to the function f so that it could be`
** modified is necessary.
** \param s The string to iterate on
** \param f The function to calls on every character of s
*/

void	ft_striter(char *s, void (*f)(char *))
{
	VOID_NULL_CHECK(s);
	VOID_NULL_CHECK(f);
	while (*s)
		f(s++);
}
