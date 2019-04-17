/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:07:44 by scoron            #+#    #+#             */
/*   Updated: 2018/12/04 21:40:22 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_carriage_return(t_pieces *bitch, int sq_size)
{
	int		check;
	int		i;

	i = -1;
	check = 0;
	while (++i < sq_size)
		if ((bitch->piece)[i] & 0x8000)
			check++;
	while (check == 0)
	{
		while (--i >= 0)
			(bitch->piece)[i] = (bitch->piece)[i] << 1;
		while (++i < sq_size)
			if ((bitch->piece)[i] & 0x8000)
				check++;
	}
}

void	ft_reset_piece(t_pieces *bitch, int sq_size)
{
	int i;

	while ((bitch->piece)[0] == 0)
	{
		i = -1;
		while (++i < (sq_size - 1))
			bitch->piece[i] = bitch->piece[i + 1];
		bitch->piece[i] = 0;
	}
	ft_carriage_return(bitch, sq_size);
}

int		ft_move_piece(t_pieces *bitch, int sq_size)
{
	int i;
	int check;

	check = 0;
	i = -1;
	while (++i < sq_size)
		if ((bitch->piece)[i] & (0x8000 >> (sq_size - 1)))
			check++;
	if (!check)
	{
		i = -1;
		while (++i < sq_size)
			(bitch->piece)[i] = (bitch->piece)[i] >> 1;
		return (1);
	}
	if (!(bitch->piece)[sq_size - 1])
	{
		ft_carriage_return(bitch, sq_size);
		while (--i > 0)
			(bitch->piece)[i] = (bitch->piece)[i - 1];
		(bitch->piece)[0] = 0;
		return (1);
	}
	ft_reset_piece(bitch, sq_size);
	return (0);
}
