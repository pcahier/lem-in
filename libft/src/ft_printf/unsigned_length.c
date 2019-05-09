/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:25:32 by agrossma          #+#    #+#             */
/*   Updated: 2017/12/18 14:11:21 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	ft_ulen(va_list *ap, t_format *fmt)
{
	uintmax_t	nbr;

	nbr = va_arg(*ap, uintmax_t);
	if (fmt->len_mod == hh)
		nbr = (unsigned char)nbr;
	else if (fmt->len_mod == h)
		nbr = (unsigned short)nbr;
	else if (fmt->len_mod == l)
		nbr = (unsigned long)nbr;
	else if (fmt->len_mod == ll)
		nbr = (unsigned long long)nbr;
	else if (fmt->len_mod == j)
		nbr = (uintmax_t)nbr;
	else if (fmt->len_mod == z)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}
