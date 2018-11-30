/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:36:05 by scoron            #+#    #+#             */
/*   Updated: 2018/11/29 18:31:07 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"
# include <stdio.h>

void	ft_reset_piece(t_pieces *bitch, int sq_size)
{
	int		check;
	int		i;

	check = 0;
	while ((bitch->piece)[0] == 0)
	{
		i = -1;
		while (++i < (sq_size - 1))
			bitch->piece[i] = bitch->piece[i + 1];
		bitch->piece[i] = 0;
	}
	i = -1;
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
		while (--i > 0)
			(bitch->piece)[i] = (bitch->piece)[i - 1];
		(bitch->piece)[0] = 0;
		return (1);
	}
	ft_reset_piece(bitch, sq_size);
	return (0);
}

unsigned short	*ft_solve(t_pieces *bitch, unsigned short *map, int sq_size)
{	
	int				t;
	int				i;
	unsigned short	*try;

	t = 0;
	i = -1;
	if (!(try = (unsigned short *)malloc(sizeof(unsigned short) * sq_size)))
		return (0);
	while (++i < sq_size && !t)
		if (map[i] & (bitch->piece)[i])
			t++;
	if (t == 0)
	{
		i = -1;
		while (++i < sq_size)
			try[i] = map[i] | (bitch->piece)[i];
		if (bitch->next)
			try = ft_solve(bitch->next, try, sq_size);
		if (try)
			return (try);
	}
	free(try);
	if (ft_move_piece(bitch, sq_size))		
		return(ft_solve(bitch, map, sq_size));
	free(map);
	return (NULL);
}

