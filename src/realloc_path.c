/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:11:04 by agrossma          #+#    #+#             */
/*   Updated: 2019/04/01 08:09:03 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_save_path(t_graph *graph, int new)
{
	int		i;

	if (graph->path_old)
	{
		i = -1;
		while (++i < (int)graph->npath_old)
			free(graph->path_old[i]);
		free(graph->path_old);
	}
	graph->path_old = new < (int)graph->npath
		? ft_memalloc(sizeof(int *) * (graph->npath + 1))
		: ft_memalloc(sizeof(int *) * (new));
	i = -1;
	while (++i < (new < (int)graph->npath ? (int)graph->npath : new))
	{
		graph->path_old[i] = ft_memalloc(sizeof(int) * graph->nvertices);
		ft_memcpy(graph->path_old[i], graph->path[i],
			sizeof(int) * graph->nvertices);
	}
}

static void	ft_free_path(t_graph *graph, int new)
{
	int		i;

	i = -1;
	if (graph->npath == 0)
		free(graph->path[1]);
	if (new <= (int)graph->npath)
		while (++i <= (int)graph->npath)
			free(graph->path[i]);
	else
		while (++i < new)
			free(graph->path[i]);
	free(graph->path);
	graph->path = new < (int)graph->npath
		? ft_memalloc(sizeof(int *) * (graph->npath + 2))
		: ft_memalloc(sizeof(int *) * (new + 1));
	i = -1;
	if (new <= (int)graph->npath)
		while (++i <= (int)graph->npath)
			graph->path[i] = ft_memalloc(sizeof(int) * graph->nvertices);
	else
		while (++i <= new)
			graph->path[i] = ft_memalloc(sizeof(int) * graph->nvertices);
}

void		ft_assign_realpath(t_graph *graph)
{
	int		i;

	i = -1;
	if (graph->npath == 0)
		free(graph->path[1]);
	while (++i <= (int)graph->npath)
		free(graph->path[i]);
	free(graph->path);
	graph->path = graph->path_old;
	graph->npath = graph->npath_old;
}

int			ft_realloc_path(t_graph *graph, int *new)
{
	if (graph->turns == 0 || graph->turns >= new[0])
	{
		graph->turns = new[0];
		ft_save_path(graph, new[1]);
		ft_free_path(graph, new[1]);
		graph->npath_old = new[1] < (int)graph->npath
			? (int)graph->npath : new[1];
		graph->npath = new[1] < (int)graph->npath
			? (int)graph->npath : new[1];
		return (1);
	}
	return (0);
}
