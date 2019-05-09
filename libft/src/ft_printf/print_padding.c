/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:50:02 by agrossma          #+#    #+#             */
/*   Updated: 2018/08/01 13:32:23 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_padding(size_t strlen, size_t padding_width,
						char padding, int fd)
{
	while (strlen < padding_width)
	{
		ft_putchar_fd(padding, fd);
		strlen++;
	}
}
