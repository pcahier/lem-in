/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:51:00 by agrossma          #+#    #+#             */
/*   Updated: 2018/03/25 13:19:17 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Take the adress of a pointer which the memory is freed (with free) and
** puts the pointer to NULL
** \param ap The adress of the pointer
*/

void	ft_memdel(void **ap)
{
	VOID_NULL_CHECK(ap);
	free(*ap);
	*ap = NULL;
}
