/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:35:39 by agrossma          #+#    #+#             */
/*   Updated: 2019/04/01 08:03:24 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_path_alloc(t_graph *graph)
{
	int		i;

	graph->residual = ft_memalloc(sizeof(char *) * graph->nvertices);
	graph->path = ft_memalloc(sizeof(int *) * 2);
	graph->path[0] = ft_memalloc(sizeof(int) * graph->nvertices);
	i = -1;
	while (++i < (int)graph->nvertices)
		graph->residual[i] = ft_memalloc(sizeof(char) * graph->nvertices);
	graph->residual_cpy = ft_memalloc(sizeof(char *) * graph->nvertices);
	i = -1;
	while (++i < (int)graph->nvertices)
		graph->residual_cpy[i] = ft_memalloc(sizeof(char) * graph->nvertices);
}

static int	ft_bfs_edmonds_internal(t_graph *graph, t_queue *queue,
			int lst_vertices[])
{
	int		u;
	int		i;

	while (queue->size)
	{
		u = ft_dequeue(queue);
		i = -1;
		while (++i < (int)graph->nvertices)
		{
			if (graph->matrix[u][i] == 1 && lst_vertices[i] == -1
				&& (1 - graph->residual[u][i]) > 0)
			{
				lst_vertices[i] = 0;
				graph->path[0][i] = u;
				if (i == graph->end)
					return (1);
				ft_enqueue(queue, i);
			}
		}
	}
	return (0);
}

static int	ft_bfs_edmonds(t_graph *graph)
{
	int		lst_vertices[graph->nvertices];
	t_queue	queue;
	int		flow;

	ft_memset(lst_vertices, -1, sizeof(int) * graph->nvertices);
	ft_memset(&queue, 0, sizeof(t_queue));
	lst_vertices[graph->start] = -2;
	queue.array = ft_memalloc(sizeof(int) * graph->nvertices);
	queue.capacity = graph->nvertices;
	queue.rear = queue.capacity - 1;
	ft_enqueue(&queue, graph->start);
	flow = ft_bfs_edmonds_internal(graph, &queue, &lst_vertices[0]);
	free(queue.array);
	if (flow)
		return (flow);
	return (0);
}

static void	ft_edmonds_internal(t_graph *graph, int *v)
{
	int		u;

	u = graph->path[0][*v];
	if (u < (int)(graph->nvertices / 2)
		&& *v == (int)(u + (graph->nvertices / 2)))
		*v = u;
	else
	{
		graph->residual[u][*v] += 1;
		graph->residual[*v + (graph->nvertices / 2)]
			[u - (graph->nvertices / 2)] -= 1;
		*v = u;
	}
}

int			ft_edmonds_karp(t_graph *graph)
{
	int		flow;
	int		v;

	ft_path_alloc(graph);
	flow = 0;
	while (42)
	{
		if ((ft_bfs_edmonds(graph)) == 0)
			break ;
		flow += 1;
		v = graph->end;
		while (v != graph->start)
			ft_edmonds_internal(graph, &v);
		if (ft_get_turns(graph) == 0)
			break ;
		if (graph->nants == 1)
			break ;
	}
	if (flow == 0)
		return (0);
	ft_assign_realpath(graph);
	ft_augmenting_path(graph);
	return (flow);
}
