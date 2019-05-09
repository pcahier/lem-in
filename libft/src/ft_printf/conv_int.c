/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:04:37 by agrossma          #+#    #+#             */
/*   Updated: 2017/12/18 15:21:09 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t	ft_get_int_type(va_list *ap, t_format *fmt)
{
	intmax_t	nbr;

	nbr = va_arg(*ap, intmax_t);
	if (fmt->len_mod == hh)
		nbr = (signed char)nbr;
	else if (fmt->len_mod == h)
		nbr = (short)nbr;
	else if (fmt->len_mod == l)
		nbr = (long)nbr;
	else if (fmt->len_mod == ll)
		nbr = (long long)nbr;
	else if (fmt->len_mod == j)
		nbr = (intmax_t)nbr;
	else if (fmt->len_mod == z)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

ssize_t			ft_conv_int(char **format, va_list *ap, t_format *fmt)
{
	intmax_t	nbr;
	char		*prefix;

	(void)format;
	if (fmt->has_precision)
		fmt->zero_padding = 0;
	nbr = ft_get_int_type(ap, fmt);
	if (nbr < 0 || fmt->force_sign || fmt->blank_sign)
	{
		if (nbr < 0)
		{
			prefix = "-";
			nbr = -nbr;
		}
		else if (fmt->force_sign)
			prefix = "+";
		else if (fmt->blank_sign)
			prefix = " ";
		else
			prefix = "";
		return (ft_print_int_prefix(nbr, "0123456789", fmt, prefix));
	}
	else
		return (ft_print_unsigned_int(nbr, "0123456789", fmt, NULL));
}
