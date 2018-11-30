/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:19:37 by jubeal            #+#    #+#             */
/*   Updated: 2018/11/29 18:41:23 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "fillit.h"

void	map_innit(char **map, int taille_map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < taille_map)
	{
		j = -1;
		while (++j < taille_map)
			map[i][j] = '.';
	}
}

void	lst_free(t_pieces *tmp)
{
	free(tmp->piece);
	free(tmp);
}

void	piece_in_map(char **map, int taille_map, unsigned short *piece,
		char car)
{
	int		i;
	int		j;
	char	*line;

	i = -1;
	while (++i < taille_map)
	{
		line = ft_itoa(piece[i]);
		printf("line : %s\n", line);
		line = ft_convert_base(line, "0123456789", "01");
		printf("line post : %s\n", line);
		j = -1;
		while (++j < taille_map)
			if (line[j] == '1')
				map[i][j] = car;
	}
}

void	affichage(t_pieces *head, int taille_map)
{
	t_pieces		*tmp;
	char			**map;
	int				i;
	char			aff;

	i = -1;
	aff = 'A';
	if (!(map = (char **)malloc(sizeof(char	*) * taille_map + 1)))
		return ;
	map[taille_map] = NULL;
	while (++i < taille_map)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * taille_map + 1)))
			return ;
		map[i][taille_map] = '\0';
	}
	map_innit(map, taille_map);
	while (head)
	{
		piece_in_map(map, taille_map,  head->piece, aff);
		aff++;
		ft_putstr("pas encore\n");
		tmp = head;
		head = head->next;
		lst_free(tmp);
	}
	ft_putstab(map);
}
