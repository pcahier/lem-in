/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 18:23:45 by agrossma          #+#    #+#             */
/*   Updated: 2018/08/01 13:34:24 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_conv_wchar(char **format, va_list *ap, t_format *fmt)
{
	wchar_t	wchar;
	size_t	len;

	(void)format;
	wchar = (wchar_t)va_arg(*ap, wint_t);
	if (wchar <= 0x7F)
		len = 1;
	else if (wchar <= 0x7FF)
		len = 2;
	else if (wchar <= 0xFFFF)
		len = 3;
	else if (wchar <= 0x10FFFF)
		len = 4;
	else
		len = 0;
	if (fmt->has_field_width && !fmt->right_padding)
		ft_print_padding(len, fmt->field_width,
						fmt->zero_padding ? '0' : ' ', fmt->fd);
	ft_putwchar_fd(wchar, fmt->fd);
	if (fmt->has_field_width && fmt->right_padding)
		ft_print_padding(len, fmt->field_width, ' ', fmt->fd);
	return (fmt->field_width ? FT_MAX(fmt->field_width, len) : len);
}
