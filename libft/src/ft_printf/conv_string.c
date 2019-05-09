/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 09:26:10 by agrossma          #+#    #+#             */
/*   Updated: 2018/08/01 13:34:42 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_conv_string(char **format, va_list *ap, t_format *fmt)
{
	size_t	len;
	char	*str;
	int		i;

	if (fmt->len_mod == l)
		return (ft_conv_wstring(format, ap, fmt));
	else
	{
		if ((str = va_arg(*ap, char *)) == NULL)
			str = "(null)";
		len = fmt->has_precision ? ft_strnlen(str, fmt->precision)
			: ft_strlen(str);
		if (fmt->has_field_width && !fmt->right_padding)
			ft_print_padding(len, fmt->field_width,
				fmt->zero_padding ? '0' : ' ', fmt->fd);
		i = 0;
		while (i < (int)len)
			ft_putchar_fd(str[i++], fmt->fd);
		if (fmt->has_field_width && fmt->right_padding)
			ft_print_padding(len, fmt->field_width, ' ', fmt->fd);
		return (fmt->has_field_width ? FT_MAX(fmt->field_width, len) : len);
	}
}
