/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:21:58 by agrossma          #+#    #+#             */
/*   Updated: 2019/04/01 16:25:08 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_get_turns_bfs(t_graph *graph, int *lst_vertices, t_queue *queue,
			int i)
{
	int		u;
	int		j;

	while (queue->size)
	{
		u = ft_dequeue(queue);
		j = -1;
		while (++j < (int)graph->nvertices)
		{
			if ((u < (int)(graph->nvertices / 2)
				&& j == (int)(u + (graph->nvertices / 2))
				&& lst_vertices[j] == -1 && graph->residual_cpy[u][j] == 0)
				|| (lst_vertices[j] == -1 && graph->residual_cpy[u][j] == 1
				&& u >= (int)(graph->nvertices / 2)
				&& j != (int)(u - (graph->nvertices / 2))))
			{
				lst_vertices[j] = 0;
				graph->path[i][j] = u;
				if (j == graph->end)
					return (1);
				ft_enqueue(queue, j);
			}
		}
	}
	return (0);
}

static void	ft_residualcpy_change(t_graph *graph, int i)
{
	int		v;
	int		u;

	v = graph->end;
	while (v != graph->start)
	{
		u = graph->path[i][v];
		if (u >= (int)(graph->nvertices / 2)
			&& v != (int)(u - (graph->nvertices / 2)))
		{
			graph->residual_cpy[u][v] = 0;
			graph->residual_cpy[v + (graph->nvertices / 2)]
				[u - (graph->nvertices / 2)] = 0;
		}
		else
		{
			graph->residual_cpy[u][v] = 1;
			graph->residual_cpy[v][u] = 1;
		}
		v = u;
	}
	graph->residual_cpy[graph->start]
		[graph->start + (graph->nvertices / 2)] = 0;
}

static int	*ft_calculate_turns(t_graph *graph, int i)
{
	static int	turns[2];
	int			j;
	int			ns;

	ft_memset(turns, 0, sizeof(int) * 2);
	graph->paths_size = ft_memalloc(sizeof(int) * i);
	j = -1;
	while (++j < i)
		graph->paths_size[j] = ft_get_path_size(graph, j);
	ns = 0;
	while (ns < (int)graph->nants)
	{
		turns[0]++;
		j = -1;
		while (++j < i)
		{
			if (graph->paths_size[j] <= turns[0])
				ns++;
		}
	}
	free(graph->paths_size);
	turns[1] = i;
	return (turns);
}

static int	*ft_get_turns_internal(t_graph *graph)
{
	int		lst_vertices[graph->nvertices];
	t_queue	queue;
	int		i;

	i = 0;
	while (42)
	{
		ft_memset(lst_vertices, -1, sizeof(int) * graph->nvertices);
		ft_memset(&queue, 0, sizeof(t_queue));
		lst_vertices[graph->start] = -2;
		queue.array = ft_memalloc(sizeof(int) * graph->nvertices);
		queue.capacity = graph->nvertices;
		queue.rear = queue.capacity - 1;
		ft_enqueue(&queue, graph->start);
		if ((ft_get_turns_bfs(graph, lst_vertices, &queue, i)) == 0)
			break ;
		ft_residualcpy_change(graph, i++);
		if (i > (int)graph->npath)
			break ;
		free(queue.array);
	}
	if (queue.array)
		free(queue.array);
	return (ft_calculate_turns(graph, i));
}

int			ft_get_turns(t_graph *graph)
{
	int		*new;
	int		i;

	i = -1;
	if (graph->npath == 0)
		graph->path[graph->npath + 1] = ft_memalloc(sizeof(int)
			* graph->nvertices);
	while (++i < (int)graph->nvertices)
		ft_memcpy(graph->residual_cpy[i], graph->residual[i],
			sizeof(char) * graph->nvertices);
	new = ft_get_turns_internal(graph);
	return (ft_realloc_path(graph, new));
}
