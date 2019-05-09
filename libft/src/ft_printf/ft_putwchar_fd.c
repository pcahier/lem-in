/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 13:27:32 by agrossma          #+#    #+#             */
/*   Updated: 2018/08/01 13:29:14 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwchar_fd(wchar_t wchar, int fd)
{
	if (wchar <= 0x7F)
		ft_putchar_fd(wchar, fd);
	else if (wchar <= 0x7FF)
	{
		ft_putchar_fd((wchar >> 6) + 0xC0, fd);
		ft_putchar_fd((wchar & 0x3F) + 0x80, fd);
	}
	else if (wchar <= 0xFFFF)
	{
		ft_putchar_fd((wchar >> 12) + 0xE0, fd);
		ft_putchar_fd(((wchar >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((wchar & 0x3F) + 0x80, fd);
	}
	else if (wchar <= 0x10FFFF)
	{
		ft_putchar_fd((wchar >> 18) + 0xF0, fd);
		ft_putchar_fd(((wchar >> 12) & 0x3F) + 0x80, fd);
		ft_putchar_fd(((wchar >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((wchar & 0x3F) + 0x80, fd);
	}
}
