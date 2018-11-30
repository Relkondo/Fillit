/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 23:38:49 by scoron            #+#    #+#             */
/*   Updated: 2018/11/14 12:41:54 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_nbr_fd(int nbp, int fd)
{
	if (nbp > 9)
	{
		ft_print_nbr_fd(nbp / 10, fd);
		ft_putchar_fd(nbp % 10 + '0', fd);
	}
	else
	{
		ft_putchar_fd(nbp + '0', fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	int check;

	check = 0;
	if (n == -2147483648)
	{
		n = -214748364;
		check = 1;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	ft_print_nbr_fd(n, fd);
	if (check == 1)
	{
		ft_putchar_fd('8', fd);
	}
}
