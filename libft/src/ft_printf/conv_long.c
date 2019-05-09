/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 18:39:57 by agrossma          #+#    #+#             */
/*   Updated: 2017/12/16 18:42:37 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_conv_long(char **format, va_list *ap, t_format *fmt)
{
	fmt->len_mod = l;
	return (ft_conv_tab(ft_tolower(**format))(format, ap, fmt));
}
