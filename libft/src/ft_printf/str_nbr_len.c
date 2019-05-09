/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_nbr_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 16:12:04 by agrossma          #+#    #+#             */
/*   Updated: 2017/12/18 15:15:44 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strnbrlen(uintmax_t nbr, char *base,
		t_format *fmt, char *prefix)
{
	size_t	nbr_len;
	size_t	str_len;

	nbr_len = ft_nbrlen(nbr, base);
	if (nbr == 0 && fmt->has_precision && fmt->precision == 0)
		str_len = 0;
	else if (fmt->has_precision)
		str_len = FT_MAX(nbr_len, fmt->precision);
	else
		str_len = nbr_len;
	if (fmt->alt_form && prefix != NULL && nbr != 0)
		str_len += ft_strlen(prefix);
	return (str_len);
}
