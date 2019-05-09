/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 14:41:57 by agrossma          #+#    #+#             */
/*   Updated: 2018/08/01 13:41:10 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	ft_parse_format(int fd,
				const char **format, va_list *ap, t_format *fmt)
{
	ssize_t	format_len;
	t_conv	conv;

	(void)fd;
	fmt->fd = 1;
	if ((*(++*format)) == '\0')
		return (0);
	if ((ft_parse_flags((char **)format, fmt)) == NULL)
		return (-1);
	if ((ft_parse_width((char **)format, fmt, ap)) == NULL)
		return (-1);
	if ((ft_parse_precision((char **)format, ap, fmt)) == NULL)
		return (-1);
	if ((ft_parse_length((char **)format, fmt)) == NULL)
		return (-1);
	if (**format == '\0')
		return (0);
	if (ft_conv_tab(**format) == NULL)
		conv = ft_conv_null;
	else
		conv = ft_conv_tab(**format);
	format_len = conv((char **)format, ap, fmt);
	(*format)++;
	return (format_len);
}

static int		ft_printf_rec(int fd,
				const char *format, va_list *ap, size_t nbr_chr)
{
	char		*next_arg;
	t_format	fmt;
	ssize_t		format_len;

	next_arg = ft_strchr(format, '%');
	if (*format == '\0')
		return (nbr_chr);
	if (next_arg == NULL)
	{
		ft_putstr_fd(format, 1);
		return (nbr_chr + ft_strlen(format));
	}
	else if (next_arg > format)
	{
		write(1, format, next_arg - format);
		return (ft_printf_rec(fd, next_arg, ap, nbr_chr + (next_arg - format)));
	}
	else
	{
		ft_bzero(&fmt, sizeof(t_format));
		if ((format_len = ft_parse_format(fd, &format, ap, &fmt)) == -1)
			return (-1);
		else
			return (ft_printf_rec(fd, format, ap, nbr_chr + format_len));
	}
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_printf_rec(1, format, &ap, 0);
	va_end(ap);
	return (ret);
}
