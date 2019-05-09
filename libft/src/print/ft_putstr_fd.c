/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:51:01 by agrossma          #+#    #+#             */
/*   Updated: 2017/11/10 19:43:36 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes the string s in the file descriptor fd
** \param s The string to write
** \param fd The file descriptor where to write
*/

void	ft_putstr_fd(char const *s, int fd)
{
	int		c;

	if (s == NULL)
		return ;
	c = ft_strlen(s);
	write(fd, s, c);
}
