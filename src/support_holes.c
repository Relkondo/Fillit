/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supportholes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 22:38:28 by scoron            #+#    #+#             */
/*   Updated: 2018/12/03 22:26:01 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_send_up(t_fibox *toolbox, unsigned short **map, int line, int pos)
{
	if (line != 0 && !(((*map)[line - 1] << pos) & 0x8000))
	{
		if (line == toolbox->lmin)
			return (0);
		else if (!(ft_checkhole_up(toolbox, map, line - 1, pos)))
			return (0);
	}
	return (1);
}

int		ft_send_down(t_fibox *toolbox, unsigned short **map, int line, int pos)
{
	if (line != toolbox->sq_size - 1 && !(((*map)[line + 1] << pos) & 0x8000))
	{
		if (line + 1 == toolbox->lmax)
			return (0);
		else if (!(ft_checkhole_down(toolbox, map, line + 1, pos)))
			return (0);
	}
	return (1);
}

int		ft_send_right(t_fibox *toolbox, unsigned short **map, int line, int pos)
{
	if (pos != toolbox->sq_size - 1 && !(((*map)[line] << (pos + 1)) & 0x8000))
		if (!(ft_checkhole_right(toolbox, map, line, pos + 1)))
			return (0);
	return (1);
}

int		ft_send_left(t_fibox *toolbox, unsigned short **map, int line, int pos)
{
	if (pos != 0 && !(((*map)[line] << (pos - 1)) & 0x8000))
		if (!(ft_checkhole_left(toolbox, map, line, pos - 1)))
			return (0);
	return (1);
}
