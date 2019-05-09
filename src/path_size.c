/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:09:39 by agrossma          #+#    #+#             */
/*   Updated: 2019/03/09 19:11:53 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_get_path_size(t_graph *graph, int i)
{
	int		size;
	int		u;
	int		v;

	size = 0;
	u = graph->end;
	while (u != graph->start)
	{
		size++;
		v = graph->path[i][u];
		u = v;
	}
	if (size % 2 == 0)
		return (size / 2);
	else
		return ((size + 1) / 2);
}
