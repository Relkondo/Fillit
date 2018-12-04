/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:36:05 by scoron            #+#    #+#             */
/*   Updated: 2018/12/04 22:52:44 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_solve(t_pieces *bitch, unsigned short **map, t_fibox *toolbox)
{
	int				t;
	int				i;

	t = 0;
	i = -1;
	while (++i < toolbox->sq_size && !t)
		if ((*map)[i] & (bitch->piece)[i])
			t++;
	if (t == 0)
	{
		i = -1;
		while (++i < toolbox->sq_size)
			(*map)[i] = (*map)[i] | (bitch->piece)[i];
		if (toolbox->h_max < 5)
			scan_holes(toolbox, bitch, map);
		if (toolbox->nb_holes > toolbox->h_max)
			t++;
		if (t == 0 && (!(bitch->next) || ft_solve(bitch->next, map, toolbox)))
			return (1);
		while (--i >= 0)
			(*map)[i] = (*map)[i] ^ (bitch->piece)[i];
	}
	return ((ft_move_piece(bitch, toolbox->sq_size))
			? ft_solve(bitch, map, toolbox) : 0);
}

int		ft_solve_init(t_pieces *bitch, unsigned short **map, t_fibox *toolbox)
{
	int			check;

	check = 0;
	(toolbox->sq_size)--;
	while (++(toolbox->sq_size) <= 16 && check == 0)
	{
		check = -1;
		toolbox->h_max = toolbox->sq_size * toolbox->sq_size - (toolbox->n) * 4;
		toolbox->full_line = ft_power(2, (toolbox->sq_size)) - 1;
		toolbox->nb_holes = 0;
		while (++check < (toolbox->sq_size))
			(*map)[check] = 0;
		check = ft_solve(bitch, map, toolbox);
	}
	free(*map);
	return (check > 0 ? toolbox->sq_size : check);
}
