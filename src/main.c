/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:02:06 by agrossma          #+#    #+#             */
/*   Updated: 2019/04/01 16:24:27 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_checkline(t_graph *graph)
{
	char	*str;
	int		special;
	int		where;

	str = NULL;
	special = 0;
	where = 0;
	while (get_next_line(0, &str) > 0)
	{
		ft_putendl_fd(str, 1);
		if (str[0] == '#' && !ft_check_sharp(str, &special))
			return (0);
		else if (str[0] == 'L' || !ft_check_nants(str, graph, &where)
				|| !ft_check_vertex(str, graph, &special, &where)
				|| !ft_check_edge(str, graph, &where))
		{
			ft_strdel(&str);
			return (0);
		}
		ft_strdel(&str);
	}
	if (str)
		ft_strdel(&str);
	(void)write(1, "\n", 1);
	return (1);
}

int				ft_getvertex(char *str, t_graph *graph)
{
	int		i;

	i = 0;
	while (i < (int)(graph->nvertices / 2))
	{
		if (ft_strlen(graph->vertices[i]) == ft_strlen(str)
				&& !ft_strcmp(str, graph->vertices[i]))
			return (i);
		i++;
	}
	return (-1);
}

static void		ft_free_graph(t_graph *graph)
{
	if (graph->vertices[0])
		ft_memdel2d((void **)graph->vertices);
	else
		free(graph->vertices);
	while (graph->nvertices--)
	{
		if (graph->matrix)
			ft_memdel((void **)&graph->matrix[graph->nvertices]);
		if (graph->residual)
			ft_memdel((void **)&graph->residual[graph->nvertices]);
		if (graph->residual_cpy)
			ft_memdel((void **)&graph->residual_cpy[graph->nvertices]);
	}
	ft_memdel((void **)&graph->matrix);
	ft_memdel((void **)&graph->residual);
	ft_memdel((void **)&graph->residual_cpy);
	while (graph->npath--)
		ft_memdel((void **)&graph->path[graph->npath]);
	ft_memdel((void **)&graph->path[0]);
	free(graph->path);
	ft_memdel((void **)&graph->paths_size);
	ft_memdel((void **)&graph->ant_per_path);
}

int				main(void)
{
	t_graph	graph;

	(void)ft_bzero(&graph, sizeof(t_graph));
	graph.mvertices = MVERTICES;
	graph.start = -1;
	graph.end = -1;
	if ((graph.vertices = ft_memcalloc(graph.mvertices, sizeof(char *)))
		== NULL)
	{
		(void)write(2, ERROR, 7);
		return (1);
	}
	if (!ft_checkline(&graph) || graph.nants <= 0 || !graph.nvertices
			|| !graph.nedges || graph.start == -1 || graph.end == -1)
		(void)write(2, ERROR, 7);
	if (graph.nants <= 0 || !graph.nvertices || !graph.nedges
			|| graph.start == -1 || graph.end == -1)
	{
		ft_free_graph(&graph);
		exit(1);
	}
	graph.flow = ft_edmonds_karp(&graph);
	ft_resolve(&graph);
	ft_free_graph(&graph);
	return (0);
}
