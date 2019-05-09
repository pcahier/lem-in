/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:02:40 by agrossma          #+#    #+#             */
/*   Updated: 2019/03/09 19:57:56 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

/*
** Includes for authorized functions
** stdlib.h for malloc(3) and free(3)
** unistd.h for read(2) and write(2)
** stdio.h for perror(3)
** string.h for strerror(3)
** libft.h for the libft functions
*/
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "libft.h"

# define START		"##start"
# define END		"##end"
# define ERROR		"ERROR\n"
# define MVERTICES	1000

typedef struct	s_graph
{
	size_t	nants;
	size_t	nvertices;
	size_t	nedges;
	size_t	mvertices;
	int		start;
	int		end;
	char	**vertices;
	char	**matrix;
	int		**path;
	size_t	npath;
	int		*paths_size;
	int		*nest;
	size_t	ant_number;
	char	**residual;
	char	**residual_cpy;
	int		flow;
	int		ant_max;
	int		*ant_per_path;
	int		turns;
	int		npath_old;
	int		**path_old;
}				t_graph;

typedef struct	s_queue
{
	int		front;
	int		rear;
	int		size;
	size_t	capacity;
	int		*array;
}				t_queue;

int				ft_getvertex(char *str, t_graph *graph);
int				ft_check_vertex(char *str, t_graph *graph,
				int *special, int *where);
int				ft_check_edge(char *str, t_graph *graph, int *where);
int				ft_check_sharp(char *str, int *special);
int				ft_check_nants(char *str, t_graph *graph, int *where);

void			ft_resolve(t_graph *graph);

int				ft_dequeue(t_queue *queue);
void			ft_enqueue(t_queue *queue, int item);

int				ft_edmonds_karp(t_graph *graph);

int				ft_augmenting_path(t_graph *graph);

int				ft_get_turns(t_graph *graph);

int				ft_get_path_size(t_graph *graph, int i);

int				ft_realloc_path(t_graph *graph, int *new);

void			ft_assign_realpath(t_graph *graph);

#endif
