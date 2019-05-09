/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 14:38:56 by agrossma          #+#    #+#             */
/*   Updated: 2018/08/08 01:29:44 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdint.h>

# define FT_MAX(x, y) (x > y) ? x : y
# define FT_MIN(x, y) (x < y) ? x : y

enum
{
	none,
	hh,
	h,
	l,
	ll,
	j,
	z
}				e_len_mod;

typedef struct	s_format
{
	int		alt_form;
	int		zero_padding;
	int		right_padding;
	int		blank_sign;
	int		force_sign;
	int		has_field_width;
	int		has_precision;
	size_t	field_width;
	size_t	precision;
	int		len_mod;
	int		fd;
}				t_format;

typedef ssize_t	(*t_conv)(char **, va_list *, t_format *);

char			*ft_parse_flags(char **format, t_format *fmt);
char			*ft_parse_width(char **format, t_format *fmt, va_list *ap);
char			*ft_parse_precision(char **format, va_list *ap, t_format *fmt);
char			*ft_parse_length(char **format, t_format *fmt);

void			ft_putwchar(wchar_t wchar);
void			ft_putwchar_fd(wchar_t wchar, int fd);

void			ft_print_padding(size_t strlen,
				size_t padding_width, char padding, int fd);
size_t			ft_nbrlen(uintmax_t nbr, char *base);
size_t			ft_strnbrlen(uintmax_t nbr, char *base,
				t_format *fmt, char *prefix);

ssize_t			ft_print_int_prefix(uintmax_t nbr, char *base,
				t_format *fmt, char *prefix);
ssize_t			ft_print_unsigned_int(uintmax_t nbr, char *base,
				t_format *fmt, char *prefix);
uintmax_t		ft_ulen(va_list *ap, t_format *fmt);

ssize_t			ft_conv_hex(char **format, va_list *ap, t_format *fmt);
ssize_t			ft_conv_unsigned(char **format, va_list *ap, t_format *fmt);
ssize_t			ft_conv_octal(char **format, va_list *ap, t_format *fmt);
ssize_t			ft_conv_long(char **format, va_list *ap, t_format *fmt);
ssize_t			ft_conv_int(char **format, va_list *ap, t_format *fmt);
ssize_t			ft_conv_null(char **format, va_list *ap, t_format *fmt);
ssize_t			ft_conv_pointer(char **format, va_list *ap, t_format *fmt);
ssize_t			ft_conv_wstring(char **format, va_list *ap, t_format *fmt);
ssize_t			ft_conv_string(char **format, va_list *ap, t_format *fmt);
ssize_t			ft_conv_escape(char **format, va_list *ap, t_format *fmt);
ssize_t			ft_conv_char(char **format, va_list *ap, t_format *fmt);
ssize_t			ft_conv_wchar(char **format, va_list *ap, t_format *fmt);

t_conv			ft_conv_tab(char c);

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);

#endif
