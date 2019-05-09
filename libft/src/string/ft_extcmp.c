/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:57:16 by agrossma          #+#    #+#             */
/*   Updated: 2017/11/25 12:59:11 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_extcmp(const char *path, const char *ext)
{
	size_t	nl;
	size_t	el;
	char	*p;
	char	*e;

	p = (char *)path;
	e = (char *)ext;
	nl = ft_strlen(p);
	el = ft_strlen(e);
	return (!ft_strcmp(p + nl - el, e));
}
