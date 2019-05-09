/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   augmenting_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:39:48 by agrossma          #+#    #+#             */
/*   Updated: 2019/04/01 12:30:29 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_augmenting_path_ascending(t_graph *graph)
{
	int		ns;
	int		i;

	ns = 0;
	while (ns < (int)graph->nants)
	{
		i = -1;
		while (++i < (int)graph->npath)
		{
			if (graph->ant_per_path[i] <= (graph->turns - graph->paths_size[i]))
			{
				graph->ant_per_path[i]++;
				ns++;
				if (ns == (int)graph->nants)
					return (1);
			}
		}
	}
	return (1);
}

int			ft_augmenting_path(t_graph *graph)
{
	int		i;

	i = -1;
	graph->paths_size = ft_memalloc(graph->npath * sizeof(int));
	while (++i < (int)graph->npath)
		graph->paths_size[i] = ft_get_path_size(graph, i);
	graph->ant_per_path = ft_memalloc(sizeof(int) * graph->npath);
	return (ft_augmenting_path_ascending(graph));
}
