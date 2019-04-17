/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:19:37 by jubeal            #+#    #+#             */
/*   Updated: 2018/12/05 20:27:44 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	map_init(char **map, int size_map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size_map)
	{
		j = -1;
		while (++j < size_map)
			map[i][j] = '.';
	}
}

void	lst_free(t_pieces *tmp)
{
	free(tmp->piece);
	free(tmp);
}

void	convert_to_16bits(char **line)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * 16)))
		return ;
	while ((*line)[i])
		i++;
	j = -1;
	while (++j + i < 16)
		tmp[j] = '0';
	i = -1;
	while (++i + j < 16)
		tmp[i + j] = (*line)[i];
	free(*line);
	*line = tmp;
}

void	piece_in_map(char **map, int size_map, unsigned short *piece,
		char car)
{
	int		i;
	int		j;
	char	*line;

	i = -1;
	while (++i < size_map)
	{
		line = ft_itoa(piece[i]);
		line = ft_convert_base(line, "0123456789", "01");
		convert_to_16bits(&line);
		j = -1;
		while (++j < size_map)
			if (line[j] == '1')
				map[i][j] = car;
		free(line);
	}
}

void	display(t_pieces *head, int size_map)
{
	t_pieces		*tmp;
	char			**map;
	int				i;
	char			aff;

	i = -1;
	aff = 'A' - 1;
	if (!(map = (char **)malloc(sizeof(char	*) * (size_map + 1))))
		return ;
	map[size_map] = NULL;
	while (++i < size_map)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * (size_map + 1))))
			return ;
		map[i][size_map] = '\0';
	}
	map_init(map, size_map);
	while (head)
	{
		piece_in_map(map, size_map, head->piece, ++aff);
		tmp = head;
		head = head->next;
		lst_free(tmp);
	}
	if (COLOR)
		ft_putstab_visual(map, size_map);
	else
		ft_putstab(map);
}
