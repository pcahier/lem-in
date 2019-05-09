/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_octal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:13:25 by agrossma          #+#    #+#             */
/*   Updated: 2018/08/01 13:35:00 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_conv_octal(char **format, va_list *ap, t_format *fmt)
{
	uintmax_t	nbr;

	(void)format;
	nbr = ft_ulen(ap, fmt);
	if (fmt->alt_form && nbr == 0 && fmt->has_precision && fmt->precision == 0)
	{
		if (fmt->has_field_width && !fmt->right_padding)
			ft_print_padding(1,
			fmt->field_width, fmt->zero_padding ? '0' : ' ', fmt->fd);
		ft_putstr_fd("0", fmt->fd);
		if (fmt->has_field_width && fmt->right_padding)
			ft_print_padding(1, fmt->field_width, ' ', fmt->fd);
		return (fmt->has_field_width ? FT_MAX(fmt->field_width, 1) : 1);
	}
	else if (fmt->alt_form && nbr != 0)
	{
		fmt->has_precision = 1;
		fmt->precision = FT_MAX(fmt->precision, ft_nbrlen(nbr, "01234567") + 1);
	}
	return (ft_print_unsigned_int(nbr, "01234567", fmt, NULL));
}
