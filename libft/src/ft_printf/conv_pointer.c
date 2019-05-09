/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:45:12 by agrossma          #+#    #+#             */
/*   Updated: 2017/12/18 13:44:37 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_conv_pointer(char **format, va_list *ap, t_format *fmt)
{
	char		*base;
	uintmax_t	nbr;

	(void)format;
	fmt->len_mod = z;
	if (fmt->has_precision)
		fmt->zero_padding = 0;
	base = "0123456789abcdef";
	nbr = ft_ulen(ap, fmt);
	return (ft_print_int_prefix(nbr, base, fmt, "0x"));
}
