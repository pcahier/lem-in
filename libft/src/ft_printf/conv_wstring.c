/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_wstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:09:11 by agrossma          #+#    #+#             */
/*   Updated: 2018/08/01 13:33:55 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_putnwstr(const wchar_t *str, size_t len, int fd)
{
	size_t	i;

	i = 0;
	while (*str && i < len)
	{
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x10FFFF)
			i += 4;
		if (i <= len)
			ft_putwchar_fd(*str++, fd);
	}
}

static size_t	ft_wstrlen_precision(wchar_t *wstr,
				size_t precision, size_t len)
{
	if (*wstr == '\0' || precision == 0)
		return (len);
	else if (*wstr <= 0x7F)
		return (ft_wstrlen_precision(wstr + 1, precision - 1, len + 1));
	else if (*wstr <= 0x7FF && precision >= 2)
		return (ft_wstrlen_precision(wstr + 1, precision - 2, len + 2));
	else if (*wstr <= 0xFFFF && precision >= 3)
		return (ft_wstrlen_precision(wstr + 1, precision - 3, len + 3));
	else if (*wstr <= 0x10FFFF && precision >= 4)
		return (ft_wstrlen_precision(wstr + 1, precision - 4, len + 4));
	else
		return (len);
}

static size_t	ft_wstrlen(wchar_t *wstr)
{
	size_t	len;

	len = 0;
	while (*wstr)
	{
		if (*wstr <= 0x7F)
			len += 1;
		else if (*wstr <= 0x7FF)
			len += 2;
		else if (*wstr <= 0xFFFF)
			len += 3;
		else if (*wstr <= 0x10FFFF)
			len += 4;
		wstr++;
	}
	return (len);
}

ssize_t			ft_conv_wstring(char **format, va_list *ap, t_format *fmt)
{
	wchar_t	*str;
	size_t	len;

	(void)format;
	if ((str = va_arg(*ap, wchar_t *)) == NULL)
		str = L"(null)";
	len = fmt->has_precision ? ft_wstrlen_precision(str, fmt->precision, 0)
		: ft_wstrlen(str);
	if (fmt->has_field_width && !fmt->right_padding)
		ft_print_padding(len, fmt->field_width,
			fmt->zero_padding ? '0' : ' ', fmt->fd);
	ft_putnwstr(str, len, fmt->fd);
	if (fmt->has_field_width && fmt->right_padding)
		ft_print_padding(len, fmt->field_width, ' ', fmt->fd);
	return (fmt->has_field_width ? FT_MAX(fmt->field_width, len) : len);
}
