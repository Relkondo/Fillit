/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:36:05 by scoron            #+#    #+#             */
/*   Updated: 2018/12/01 22:10:00 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
# include <stdio.h>

int		ft_solve(t_pieces *bitch, unsigned short **map, int sq_size)
{
	int				t;
	int				i;

	t = 0;
	i = -1;
	while (++i < sq_size && !t)
		if ((*map)[i] & (bitch->piece)[i])
			t++;
	if (t == 0)
	{
		i = -1;
		while (++i < sq_size)
			(*map)[i] = (*map)[i] | (bitch->piece)[i];
		if (!(bitch->next) || ft_solve(bitch->next, map, sq_size))
			return (1);
		while (--i >= 0)
			(*map)[i] = (*map)[i] ^ (bitch->piece)[i];
	}
	if (ft_move_piece(bitch, sq_size))
		return (ft_solve(bitch, map, sq_size));
	return (0);
}

int		ft_solve_init(t_pieces *bitch, unsigned short **map, int sq_size)
{
	int		check;

	check = 0;
	while (sq_size++ < 16 && check == 0)
	{
		check = -1;
		while (++check < sq_size)
			(*map)[check] = 0;
		check = ft_solve(bitch, map, sq_size);
	}
	free(*map);
	return (check > 0 ? sq_size : check);
}
