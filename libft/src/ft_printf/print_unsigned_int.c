/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 16:41:31 by agrossma          #+#    #+#             */
/*   Updated: 2018/08/01 13:33:09 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base_rec(uintmax_t nbr, char *base, size_t base_len)
{
	if (nbr >= base_len)
	{
		ft_putnbr_base_rec(nbr / base_len, base, base_len);
		ft_putnbr_base_rec(nbr % base_len, base, base_len);
	}
	else
		ft_putchar(base[nbr]);
}

static void	ft_putnbr_base(uintmax_t nbr, char *base)
{
	ft_putnbr_base_rec(nbr, base, ft_strlen(base));
}

static void	ft_putnbr_base_prefix(uintmax_t nbr, char *base,
			t_format *fmt, size_t nbr_len)
{
	if (fmt->has_precision)
		ft_print_padding(nbr_len, fmt->precision, base[0], fmt->fd);
	if (nbr == 0 && fmt->has_precision && fmt->precision == 0)
		return ;
	else
		ft_putnbr_base(nbr, base);
}

ssize_t		ft_print_unsigned_int(uintmax_t nbr, char *base,
		t_format *fmt, char *prefix)
{
	size_t	nbr_len;
	size_t	str_len;

	if (fmt->has_precision)
		fmt->zero_padding = 0;
	nbr_len = ft_nbrlen(nbr, base);
	if (fmt->has_field_width && !fmt->right_padding && fmt->zero_padding)
	{
		if (fmt->has_precision)
			fmt->precision = FT_MAX(fmt->field_width, fmt->precision);
		else
			fmt->precision = FT_MAX(fmt->field_width, nbr_len);
		fmt->has_precision = 1;
		fmt->has_field_width = 0;
	}
	str_len = ft_strnbrlen(nbr, base, fmt, prefix);
	if (fmt->has_field_width && !fmt->right_padding)
		ft_print_padding(str_len, fmt->field_width, ' ', fmt->fd);
	if (fmt->alt_form && prefix != NULL && nbr != 0)
		ft_putstr(prefix);
	ft_putnbr_base_prefix(nbr, base, fmt, nbr_len);
	if (fmt->has_field_width && fmt->right_padding)
		ft_print_padding(str_len, fmt->field_width, ' ', fmt->fd);
	return (fmt->has_field_width ? FT_MAX(str_len, fmt->field_width) : str_len);
}
