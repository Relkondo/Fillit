/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:20:33 by scoron            #+#    #+#             */
/*   Updated: 2018/11/15 21:29:44 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp1;
	t_list	*tmp2;

	if (!lst || !(f))
		return (0);
	tmp1 = lst->next;
	if (!(new = ft_lstnew(lst->content, lst->content_size)))
		return (0);
	new = f(new);
	tmp2 = new;
	while (tmp1)
	{
		if (!(tmp2->next = ft_lstnew(tmp1->content, tmp1->content_size)))
			return (0);
		tmp2->next = f(tmp2->next);
		tmp2 = tmp2->next;
		tmp1 = tmp1->next;
	}
	return (new);
}
