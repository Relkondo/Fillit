/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:41:01 by jubeal            #+#    #+#             */
/*   Updated: 2018/12/04 22:22:15 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "fillit.h"

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
	return (j);
}

int		ft_countpieces(t_pieces *head)
{
	t_pieces	*tmp;
	int			n;

	tmp = head;
	n = 1;
	while (tmp->next)
	{
		n++;
		tmp = tmp->next;
	}
	return (n);
}

int		main(int ac, char **av)
{
	int				fd;
	t_pieces		*head;
	t_fibox			*toolbox;
	unsigned short	*map;

	if (ac != 2)
		return (errors(1));
	head = create_lstlink(&head);
	if ((fd = open(av[1], O_RDONLY)) == -1 || !check_file(fd, &head)
			|| !check_pieces(head))
		return (errors(2));
	if (!(map = (unsigned short *)malloc(sizeof(unsigned short) * 16)))
		return (errors(2));
	initialize_pieces(&head);
	if (!(toolbox = (t_fibox *)malloc(sizeof(t_fibox))))
		return (errors(2));
	toolbox->n = ft_countpieces(head);
	toolbox->sq_size = ft_sqsize(head);
	if ((toolbox->sq_size = ft_solve_init(head, &map, toolbox)))
		affichage(head, (toolbox->sq_size) - 1);
	return (0);
}
