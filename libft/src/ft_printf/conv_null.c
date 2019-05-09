/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_null.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:18:40 by agrossma          #+#    #+#             */
/*   Updated: 2018/08/01 13:35:25 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_conv_null(char **format, va_list *ap, t_format *fmt)
{
	(void)ap;
	if (fmt->has_field_width && !fmt->right_padding)
		ft_print_padding(1, fmt->field_width,
						fmt->zero_padding ? '0' : ' ', fmt->fd);
	ft_putchar_fd(**format, fmt->fd);
	if (fmt->has_field_width && fmt->right_padding)
		ft_print_padding(1, fmt->field_width, ' ', fmt->fd);
	return (fmt->has_field_width ? FT_MAX(fmt->field_width, 1) : 1);
}
