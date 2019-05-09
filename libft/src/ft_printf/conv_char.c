/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 18:14:49 by agrossma          #+#    #+#             */
/*   Updated: 2018/08/01 13:36:05 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_conv_char(char **format, va_list *ap, t_format *fmt)
{
	if (fmt->len_mod == l)
		return (ft_conv_wchar(format, ap, fmt));
	else
	{
		if (fmt->has_field_width && !fmt->right_padding)
			ft_print_padding(1, fmt->field_width,
			fmt->zero_padding ? '0' : ' ', fmt->fd);
		ft_putchar_fd(va_arg(*ap, int), fmt->fd);
		if (fmt->has_field_width && fmt->right_padding)
			ft_print_padding(1, fmt->field_width, ' ', fmt->fd);
		return (fmt->field_width ? FT_MAX(fmt->field_width, 1) : 1);
	}
}
