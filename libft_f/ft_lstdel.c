/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:20:33 by scoron            #+#    #+#             */
/*   Updated: 2018/11/15 12:44:00 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;
	t_list	**alst2;

	if (!alst || !del)
		return ;
	tmp = *alst;
	alst2 = alst;
	while (tmp)
	{
		tmp = (*alst2)->next;
		ft_lstdelone(alst2, del);
		*alst2 = tmp;
	}
	*alst = NULL;
}
