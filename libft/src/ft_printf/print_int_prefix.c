/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_prefix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:40:05 by agrossma          #+#    #+#             */
/*   Updated: 2018/08/01 13:33:26 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_print_int_prefix(uintmax_t nbr, char *base,
		t_format *fmt, char *prefix)
{
	size_t	nbr_len;
	size_t	cut;
	size_t	p_len;

	p_len = ft_strlen(prefix);
	nbr_len = ft_strnbrlen(nbr, base, fmt, NULL) + p_len;
	cut = p_len;
	if (fmt->has_field_width && !fmt->right_padding && !fmt->zero_padding)
	{
		ft_print_padding(nbr_len, fmt->field_width, ' ', fmt->fd);
		cut += FT_MAX((int)(fmt->field_width - nbr_len), 0);
		fmt->has_field_width = 0;
	}
	else if (fmt->has_field_width)
		fmt->field_width -= p_len;
	ft_putstr_fd(prefix, fmt->fd);
	return (ft_print_unsigned_int(nbr, base, fmt, NULL) + cut);
}
