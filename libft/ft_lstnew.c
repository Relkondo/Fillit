/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:06:34 by scoron            #+#    #+#             */
/*   Updated: 2018/11/15 19:29:54 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*nw;

	if (!(nw = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (content == NULL)
	{
		nw->content = NULL;
		nw->content_size = 0;
	}
	else
	{
		if (!(nw->content = (void *)ft_memalloc(sizeof(void)
						* (content_size + 1))))
			return (0);
		ft_memcpy(nw->content, content, content_size);
		nw->content_size = content_size;
	}
	nw->next = NULL;
	return (nw);
}
