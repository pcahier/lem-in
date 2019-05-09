/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:27:18 by agrossma          #+#    #+#             */
/*   Updated: 2017/12/18 16:38:40 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_conv_hex(char **format, va_list *ap, t_format *fmt)
{
	uintmax_t	nbr;

	nbr = ft_ulen(ap, fmt);
	if (nbr == 0)
		return (ft_print_unsigned_int(nbr, "0", fmt, NULL));
	else if (**format == 'X' && fmt->alt_form)
		return (ft_print_int_prefix(nbr, "0123456789ABCDEF", fmt, "0X"));
	else if (**format == 'x' && fmt->alt_form)
		return (ft_print_int_prefix(nbr, "0123456789abcdef", fmt, "0x"));
	else if (**format == 'X' && !fmt->alt_form)
		return (ft_print_unsigned_int(nbr, "0123456789ABCDEF", fmt, "0X"));
	else
		return (ft_print_unsigned_int(nbr, "0123456789abcdef", fmt, "0x"));
}
