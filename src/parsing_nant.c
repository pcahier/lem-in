/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_nant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <pcahier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 19:51:05 by pcahier           #+#    #+#             */
/*   Updated: 2019/02/27 19:52:58 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_check_nants(char *str, t_graph *graph, int *where)
{
	int		i;

	if (ft_isnumber(str) && graph->nants == 0 && *where == 0)
	{
		i = ft_atoi(str);
		if (i <= 0)
			return (0);
		graph->nants = ft_atoi(str);
		*where = 1;
		return (1);
	}
	else if (ft_isnumber(str) && graph->nants && *where)
		return (0);
	return (1);
}
