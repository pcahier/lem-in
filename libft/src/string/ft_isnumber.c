/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:45:10 by agrossma          #+#    #+#             */
/*   Updated: 2019/02/27 18:02:22 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnumber(const char *str)
{
	int		i;
	int		len;

	i = 0;
	if (!str)
		return (0);
	len = (int)ft_strlen(str);
	str[0] == '-' ? i++ : 0;
	while (i < len)
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}
