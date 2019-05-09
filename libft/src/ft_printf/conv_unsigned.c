/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:22:39 by agrossma          #+#    #+#             */
/*   Updated: 2017/12/18 14:24:32 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_conv_unsigned(char **format, va_list *ap, t_format *fmt)
{
	uintmax_t	nbr;

	(void)format;
	nbr = ft_ulen(ap, fmt);
	return (ft_print_unsigned_int(nbr, "0123456789", fmt, NULL));
}
