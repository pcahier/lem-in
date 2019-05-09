/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:50:59 by agrossma          #+#    #+#             */
/*   Updated: 2017/11/10 19:14:17 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				result;
	unsigned int	digit;
	int				sign;
	int				i;

	result = 0;
	while (ft_isspace(*str) || *str == '0')
		str++;
	if (*str == '-')
		sign = -1;
	else
		sign = 1;
	if (*str == '+' || *str == '-')
		str++;
	i = 0;
	while (ft_isdigit(*str))
	{
		digit = *str++ - '0';
		result = (10 * result) + digit;
		if (i > 10 && sign == -1)
			return (0);
		else if (i++ > 10)
			return (-1);
	}
	return (result * sign);
}
