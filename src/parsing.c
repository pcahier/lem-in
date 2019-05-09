/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 14:31:16 by agrossma          #+#    #+#             */
/*   Updated: 2019/04/01 07:57:10 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_reallocvertices_and_matrix(t_graph *graph, int ft)
{
	int i;

	i = 0;
	if (ft == 0 && graph->nvertices == graph->mvertices)
	{
		graph->mvertices *= 2;
		graph->vertices = ft_memrealloc(graph->vertices,
			sizeof(char *) * graph->mvertices,
			sizeof(char *) * graph->nvertices);
	}
	else if (ft == 1 && graph->matrix == NULL)
	{
		graph->nvertices *= 2;
		graph->matrix = ft_memcalloc(graph->nvertices, sizeof(char *));
		while (i < (int)graph->nvertices)
			graph->matrix[i++] = ft_memcalloc(graph->nvertices, sizeof(char));
	}
}

int				ft_check_vertex(char *str, t_graph *graph, int *special,
					int *where)
{
	char	**split;

	if (ft_strchr(str, '-'))
		*where = 2;
	if (!ft_strchr(str, ' ') || str[0] == 'L' || *where != 1 || str[0] == '#')
		return (1);
	split = ft_strsplit(str, ' ');
	if (ft_getvertex(split[0], graph) != -1 || !ft_isnumber(split[1])
			|| !ft_isnumber(split[2]) || split[3])
	{
		ft_memdel2d((void **)split);
		return (0);
	}
	if (*special)
	{
		if (*special == 1)
			graph->start = graph->nvertices;
		else
			graph->end = graph->nvertices;
		*special = 0;
	}
	ft_reallocvertices_and_matrix(graph, 0);
	graph->vertices[graph->nvertices++] = ft_strdup(split[0]);
	ft_memdel2d((void **)split);
	return (1);
}

static void		ft_matrix_val(t_graph *graph, int one, int two)
{
	graph->matrix[one][one + (graph->nvertices / 2)] = 1;
	graph->matrix[two][two + (graph->nvertices / 2)] = 1;
	graph->matrix[one + (graph->nvertices / 2)][two] = 1;
	graph->matrix[two + (graph->nvertices / 2)][one] = 1;
	graph->nedges++;
}

int				ft_check_edge(char *str, t_graph *graph, int *where)
{
	char	**split;
	int		one;
	int		two;

	if (*where != 2 || str[0] == '#')
		return (1);
	if ((ft_strchr(str, '-') && ft_strchr(str, ' '))
		|| (ft_strchr(str, '-') != ft_strrchr(str, '-')))
		return (0);
	ft_reallocvertices_and_matrix(graph, 1);
	split = ft_strsplit(str, '-');
	if (ft_2darraylen((void **)split) != 2)
	{
		ft_memdel2d((void **)split);
		return (0);
	}
	one = ft_getvertex(split[0], graph);
	two = ft_getvertex(split[1], graph);
	ft_memdel2d((void **)split);
	if (one == -1 || two == -1)
		return (0);
	ft_matrix_val(graph, one, two);
	return (1);
}

int				ft_check_sharp(char *str, int *special)
{
	size_t	len;

	if (str[0] != '#' || str[1] != '#')
		return (1);
	len = ft_strlen(str);
	if (len == 7 && !ft_strcmp(str, START))
		*special = 1;
	else if (len == 5 && !ft_strcmp(str, END))
		*special = 2;
	return (1);
}
