/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:21:58 by scoron            #+#    #+#             */
/*   Updated: 2018/12/04 22:32:38 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	check_sides(t_pieces *bitch, int ln, int pos, int *sides)
{
	if (pos < 15 && ((bitch->piece)[ln] << (pos + 1)) & 0x8000)
		(*sides)++;
	if (pos > 0 && ((bitch->piece)[ln] << (pos - 1)) & 0x8000)
		(*sides)++;
	if (ln > 0 && ((bitch->piece)[ln - 1] << pos) & 0x8000)
		(*sides)++;
	if (ln < 15 && ((bitch->piece)[ln + 1] << pos) & 0x8000)
		(*sides)++;
}

int		check_pieces(t_pieces *bitch)
{
	int		ln;
	int		pos;
	int		nb;
	int		sides;

	ln = -1;
	nb = 0;
	sides = 0;
	while (++ln < 16)
	{
		pos = -1;
		while (++pos < 16)
		{
			if (((bitch->piece)[ln] << pos) & 0x8000)
			{
				nb++;
				check_sides(bitch, ln, pos, &sides);
			}
		}
	}
	if (nb != 4 || sides > 8 || sides < 6)
		return (0);
	return (bitch->next ? check_pieces(bitch->next) : 1);
}
