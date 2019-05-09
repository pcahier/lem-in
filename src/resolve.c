/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 22:15:05 by agrossma          #+#    #+#             */
/*   Updated: 2019/03/04 04:43:15 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_algorithm_internal(t_graph *graph, int *u, int i, int *out)
{
	int		v;

	v = graph->path[i][*u];
	if (graph->nest[v])
	{
		if (v == graph->start && graph->ant_per_path[i] == 0)
		{
			*u = v;
			return ;
		}
		else if (v == graph->start && graph->ant_per_path[i] > 0)
		{
			graph->ant_per_path[i]--;
			graph->nest[graph->start] = graph->ant_number++;
		}
		graph->nest[*u] += graph->nest[v];
		if (*out)
			(void)write(1, " ", 1);
		*out = ft_printf("L%d-%s", graph->nest[v], graph->vertices[*u]);
		graph->nest[v] = 0;
	}
	*u = v;
}

static void		ft_algorithm(t_graph *graph)
{
	int		i;
	int		u;
	int		out;

	graph->ant_number = 1;
	graph->nest[graph->start] = graph->ant_number;
	while (graph->nest[graph->end] != graph->ant_max)
	{
		i = -1;
		out = 0;
		while (++i < (int)graph->npath)
		{
			u = graph->end;
			while (u != graph->start)
				ft_algorithm_internal(graph, &u, i, &out);
			graph->nest[graph->start] = graph->ant_number;
		}
		(void)write(1, "\n", 1);
	}
}

static void		ft_sanitize_path(t_graph *graph, int *path)
{
	int		u;
	int		v;
	int		temp;

	v = graph->end;
	while (v != graph->start)
	{
		u = path[v];
		if (u >= (int)(graph->nvertices / 2))
		{
			temp = path[u];
			path[v] = temp;
			v = temp;
		}
		else
			v = u;
	}
}

void			ft_resolve(t_graph *graph)
{
	int		i;

	if (!(graph->nest = ft_memalloc(sizeof(int) * graph->nvertices)))
	{
		(void)write(2, ERROR, 7);
		return ;
	}
	if (!graph->npath || graph->flow == 0)
	{
		(void)write(2, "No Solution\n", 12);
		free(graph->nest);
		return ;
	}
	i = -1;
	while (++i < (int)graph->npath)
		ft_sanitize_path(graph, graph->path[i]);
	graph->ant_max = (graph->nants * (graph->nants + 1)) / 2;
	ft_algorithm(graph);
	free(graph->nest);
}
