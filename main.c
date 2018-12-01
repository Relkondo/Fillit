/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:41:01 by jubeal            #+#    #+#             */
/*   Updated: 2018/12/01 22:10:44 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "fillit.h"

int		check_line(char *str, int type)
{
	int		i;

	i = -1;
	if (type == 0)
	{
		if (ft_strlen(str) != 4)
			return (0);
		while (str[++i])
			if (str[i] != '.' && str[i] != '#')
				return (0);
	}
	else if (ft_strlen(str) != 0)
		return (0);
	return (1);
}

int		check_file(int fd, t_pieces **head)
{
	char		*line;
	int			nbr_lines;
	t_pieces	*tmp;

	nbr_lines = 1;
	tmp = *head;
	while (get_next_line(fd, &line) > 0)
	{
		if (!tmp && !(tmp = create_lstlink(head)))
			return (0);
		if ((nbr_lines % 5))
		{
			if (!(check_line(line, 0)))
				return (0);
			line_convert(&tmp, line, (nbr_lines % 5) - 1);
		}
		else
		{
			if (!(check_line(line, 1)))
				return (0);
			tmp = tmp->next;
		}
		nbr_lines++;
	}
	return (1);
}

int		errors(int type)
{
	if (type == 1)
		ft_putstr("usage: ./fillit pieces_file\n");
	if (type == 2)
		ft_putstr("error\n");
	return (1);
}

int		ft_sqsize(t_pieces *head)
{
	int i;
	int j;

	if (!head)
		return (0);
	i = 4;
	while (head->next)
	{
		head = head->next;
		i += 4;
	}
	j = 2;
	while (j * j < i)
		j++;
	return (j - 1);
}

int		main(int ac, char **av)
{
	int				fd;
	t_pieces		*head;
	int				sq_size;
	unsigned short	*map;

	if (ac != 2)
		return (errors(1));
	head = create_lstlink(&head);
	if ((fd = open(av[1], O_RDONLY)) == -1 || !check_file(fd, &head)
			|| !(map = (unsigned short *)malloc(sizeof(unsigned short) * 16)))
		return (errors(2));
	initialize_pieces(&head);
	sq_size = ft_sqsize(head);
	if ((sq_size = ft_solve_init(head, &map, sq_size)))
		affichage(head, sq_size - 1);
	return (0);
}
