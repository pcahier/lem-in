/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:50:59 by agrossma          #+#    #+#             */
/*   Updated: 2018/01/29 16:41:26 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Free the content and the memory of a link from a list and puts the pointer
** to NULL.
** \param alst Adress of the link to free
** \param del Pointer a function to free the content of the link
*/

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	VOID_NULL_CHECK(alst);
	VOID_NULL_CHECK(*alst);
	(*del)((*alst)->content, (*alst)->content_size);
	ft_memdel((void **)alst);
}
