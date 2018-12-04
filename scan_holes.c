/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanholes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:21:15 by scoron            #+#    #+#             */
/*   Updated: 2018/12/04 22:50:48 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_initbox(t_fibox *toolbox, t_pieces *bitch)
{
	toolbox->lmax = 0;
	while ((bitch->piece)[toolbox->lmax] == 0)
		(toolbox->lmax)++;
	if ((toolbox->lmax) != 15)
		(toolbox->lmax)++;
	toolbox->lmin = -1;
	toolbox->nb_holes = 0;
}

void	scan_holes(t_fibox *toolbox, t_pieces *bitch, unsigned short **map)
{
	int test;

	test = 0;
	ft_initbox(toolbox, bitch);
	while (++(toolbox->lmin) < toolbox->lmax)
	{
		if ((*map)[toolbox->lmin] != toolbox->full_line)
		{
			toolbox->pos = -1;
			while (++(toolbox->pos) < (toolbox->sq_size))
			{
				while ((((*map)[toolbox->lmin] << toolbox->pos) & 0x8000)
						&& toolbox->pos < toolbox->sq_size)
					(toolbox->pos)++;
				toolbox->sz_hole = 0;
				if ((test = ft_checkhole_init(toolbox, map,
								toolbox->lmin, toolbox->pos)))
					toolbox->nb_holes += (toolbox->sz_hole) % 4;
			}
		}
	}
	return ;
}
