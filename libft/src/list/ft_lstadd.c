/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:50:59 by agrossma          #+#    #+#             */
/*   Updated: 2018/03/26 17:11:40 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Add a new element at the head of the list
** @param alst Adress of the first link of the list
** @param new The link to add at the head of the list
*/

void	ft_lstadd(t_list **alst, t_list *new)
{
	VOID_NULL_CHECK(alst);
	VOID_NULL_CHECK(new);
	new->next = *alst;
	*alst = new;
}
