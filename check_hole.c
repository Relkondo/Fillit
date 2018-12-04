/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkhole.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 21:38:54 by scoron            #+#    #+#             */
/*   Updated: 2018/12/04 22:49:14 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_checkhole_init(t_fibox *toolbox,
		unsigned short **map, int line, int pos)
{
	(toolbox->sz_hole)++;
	if (!(ft_send_left(toolbox, map, line, pos)))
		return (0);
	if (!(ft_send_up(toolbox, map, line, pos)))
		return (0);
	if (!(ft_send_down(toolbox, map, line, pos)))
		return (0);
	if (!(ft_send_right(toolbox, map, line, pos)))
		return (0);
	return (1);
}

int		ft_checkhole_right(t_fibox *toolbox,
		unsigned short **map, int line, int pos)
{
	(toolbox->sz_hole)++;
	if (line == toolbox->lmin && pos > (toolbox->pos))
		toolbox->pos = pos;
	if (!(ft_send_up(toolbox, map, line, pos)))
		return (0);
	if (!(ft_send_down(toolbox, map, line, pos)))
		return (0);
	if (!(ft_send_right(toolbox, map, line, pos)))
		return (0);
	return (1);
}

int		ft_checkhole_left(t_fibox *toolbox,
		unsigned short **map, int line, int pos)
{
	(toolbox->sz_hole)++;
	if (line == toolbox->lmin && pos > (toolbox->pos))
		toolbox->pos = pos;
	if (!(ft_send_up(toolbox, map, line, pos)))
		return (0);
	if (!(ft_send_down(toolbox, map, line, pos)))
		return (0);
	if (!(ft_send_left(toolbox, map, line, pos)))
		return (0);
	return (1);
}

int		ft_checkhole_up(t_fibox *toolbox,
		unsigned short **map, int line, int pos)
{
	(toolbox->sz_hole)++;
	if (line == toolbox->lmin && pos > (toolbox->pos))
		toolbox->pos = pos;
	if (!(ft_send_up(toolbox, map, line, pos)))
		return (0);
	if (!(ft_send_right(toolbox, map, line, pos)))
		return (0);
	if (!(ft_send_left(toolbox, map, line, pos)))
		return (0);
	return (1);
}

int		ft_checkhole_down(t_fibox *toolbox,
		unsigned short **map, int line, int pos)
{
	(toolbox->sz_hole)++;
	if (line == toolbox->lmin && pos > (toolbox->pos))
		toolbox->pos = pos;
	if (toolbox->sz_hole > toolbox->sq_size * toolbox->lmax)
		return (0);
	if (!(ft_send_down(toolbox, map, line, pos)))
		return (0);
	if (!(ft_send_right(toolbox, map, line, pos)))
		return (0);
	if (!(ft_send_left(toolbox, map, line, pos)))
		return (0);
	return (1);
}
