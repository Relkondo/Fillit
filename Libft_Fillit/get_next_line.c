/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:54:28 by scoron            #+#    #+#             */
/*   Updated: 2018/11/29 15:32:06 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_chain	*ft_newfd(int fd)
{
	t_chain	*nw;

	if (!(nw = (t_chain*)malloc(sizeof(t_chain))))
		return (NULL);
	nw->next = NULL;
	nw->previous = NULL;
	nw->res = NULL;
	nw->fd = fd;
	return (nw);
}

static t_chain	*ft_getfd(t_chain *fd_chain, int fd)
{
	if (!fd_chain)
		if (!(fd_chain = ft_newfd(fd)))
			return (NULL);
	while (fd_chain->fd != fd && fd_chain->previous)
		fd_chain = fd_chain->previous;
	while (fd_chain->fd != fd && fd_chain->next)
		fd_chain = fd_chain->next;
	if (fd_chain->fd == fd)
		return (fd_chain);
	if (!(fd_chain->next = ft_newfd(fd)))
		return (NULL);
	fd_chain->next->previous = fd_chain;
	fd_chain = fd_chain->next;
	return (fd_chain);
}

static int		ft_joinfree(t_chain *fd_chain)
{
	char	*buf;
	char	*tmp;
	int		checkread;

	checkread = 1;
	tmp = 0;
	if (!(buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	*buf = 0;
	while (!(ft_strchr(buf, '\n')) && checkread > 0)
	{
		if ((checkread = read(fd_chain->fd, buf, BUFF_SIZE)) >= 0)
		{
			buf[checkread] = '\0';
			if (!(fd_chain->res))
				tmp = ft_strdup(buf);
			else
				tmp = ft_strjoin(fd_chain->res, buf);
			free(fd_chain->res);
			fd_chain->res = tmp;
		}
	}
	free(buf);
	return ((fd_chain->res && *(fd_chain->res)
				&& checkread >= 0) ? 1 : checkread);
}

int				get_next_line(const int fd, char **line)
{
	static t_chain	*fd_chain;
	int				checkread;

	checkread = 1;
	if (!(fd_chain))
		fd_chain = NULL;
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!(fd_chain = ft_getfd(fd_chain, fd)))
		return (-1);
	if (!(fd_chain->res))
		checkread = ft_joinfree(fd_chain);
	else if (!(ft_strchr(fd_chain->res, '\n')))
		checkread = ft_joinfree(fd_chain);
	if (checkread < 0)
		return (-1);
	*line = ft_strcutuntil(&(fd_chain->res), '\n');
	return (checkread > 0 ? 1 : checkread);
}
