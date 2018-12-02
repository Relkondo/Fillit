/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanholes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:21:15 by scoron            #+#    #+#             */
/*   Updated: 2018/12/02 23:30:18 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


void	ft_initbox(t_fibox *toolbox, t_pieces *bitch)
{
	toolbox->lmax = 0;
	while ((bitch->piece)[toolbox->lmax] != 0)
		toolbox->lmax++;
	toolbox->lmin = 0;
	toolbox->pos = -1;
	toolbox->nb_holes = 0;
}

void	scan_holes(t_fibox *toolbox, t_pieces *bitch, unsigned short **map)
{
	int 	tmp;

	if (bitch->piece[0] != 0)
		return ;
	ft_initbox(toolbox, bitch);
	while (++(toolbox->lmin) < toolbox->lmax)
		if ((*map)[toolbox->lmin] != 0xFF00)
		{
			while (++(toolbox->pos) < (toolbox->sq_size))
			{
				while ((((*map)[toolbox->lmin] << toolbox->pos) & 0x8000)
						&& toolbox->pos < (toolbox->sq_size))
					(toolbox->pos)++;
				tmp = toolbox->nb_holes;
				if (!(ft_checkhole_right(toolbox, map, toolbox->lmin, toolbox->pos)))
					toolbox->nb_holes = tmp;
				else 
					toolbox->nb_holes = tmp + (((toolbox->nb_holes) - tmp) % 4);
			}
		}
	return ;
}
