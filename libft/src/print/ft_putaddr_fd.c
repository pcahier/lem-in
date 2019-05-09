/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:54:55 by agrossma          #+#    #+#             */
/*   Updated: 2017/12/16 17:09:47 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putaddr_fd(void *ptr, int fd)
{
	long int			div;
	char				tmp;
	unsigned long int	n;

	n = (unsigned long int)ptr;
	div = 16;
	ft_putstr_fd("0x", fd);
	while (n / div >= 16)
		div *= 16;
	while (div > 0)
	{
		tmp = '0' + n / div;
		if (tmp > '9')
		{
			tmp += 39;
			write(fd, &tmp, 1);
		}
		else
			write(fd, &tmp, 1);
		n %= div;
		div /= 16;
	}
}
