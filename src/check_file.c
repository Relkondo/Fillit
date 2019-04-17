/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:22:28 by jubeal            #+#    #+#             */
/*   Updated: 2018/12/04 21:21:15 by scoron           ###   ########.fr       */
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
		if (nbr_lines > 129 || (!tmp && !(tmp = create_lstlink(head))))
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
	return (tmp == NULL || nbr_lines % 5 ? 0 : 1);
}
