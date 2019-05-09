/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:23:36 by agrossma          #+#    #+#             */
/*   Updated: 2019/04/01 16:23:05 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_parse_flags(char **format, t_format *fmt)
{
	if (**format == '#' || **format == '0'
		|| **format == '-' || **format == ' ' || **format == '+')
	{
		if (**format == '#')
			fmt->alt_form = 1;
		else if (**format == '0')
			fmt->zero_padding = 1;
		else if (**format == '-')
			fmt->right_padding = 1;
		else if (**format == ' ')
			fmt->blank_sign = 1;
		else if (**format == '+')
			fmt->force_sign = 1;
		(*format)++;
		if (fmt->right_padding == 1)
			fmt->zero_padding = 0;
		return (ft_parse_flags(format, fmt));
	}
	return (*format);
}

char	*ft_parse_width(char **format, t_format *fmt, va_list *ap)
{
	int	i;

	fmt->field_width = 0;
	while (**format == '*' || ft_isdigit(**format))
	{
		if (**format == '*')
		{
			(*format)++;
			i = va_arg(*ap, int);
			if (i < 0)
				fmt->right_padding = 1;
			fmt->field_width = i < 0 ? -i : i;
			fmt->has_field_width = 1;
		}
		if (ft_isdigit(**format))
		{
			fmt->has_field_width = 1;
			fmt->field_width = 0;
			while (ft_isdigit(**format))
				fmt->field_width = fmt->field_width * 10 + (*(*format)++ - '0');
		}
	}
	return (*format);
}

char	*ft_parse_precision(char **format, va_list *ap, t_format *fmt)
{
	int	precision;

	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			(*format)++;
			if ((precision = va_arg(*ap, int)) >= 0)
			{
				fmt->has_precision = 1;
				fmt->precision = precision;
			}
			return (*format);
		}
		else
		{
			while (ft_isdigit(**format))
				fmt->precision = fmt->precision * 10 + (*(*format)++ - '0');
			fmt->has_precision = 1;
			return (*format);
		}
	}
	else
		return (*format);
}

char	*ft_parse_length(char **format, t_format *fmt)
{
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		fmt->len_mod = hh;
		return (*format += 2);
	}
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		fmt->len_mod = ll;
		return (*format += 2);
	}
	else if (**format == 'h' || **format == 'l' || **format == 'j'
			|| **format == 'z')
	{
		if (**format == 'h')
			fmt->len_mod = h;
		else if (**format == 'l')
			fmt->len_mod = l;
		else if (**format == 'j')
			fmt->len_mod = j;
		else if (**format == 'z')
			fmt->len_mod = z;
		(*format)++;
	}
	return (*format);
}
