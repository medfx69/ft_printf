/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:24:00 by mait-aad          #+#    #+#             */
/*   Updated: 2021/12/13 14:55:28 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char n)
{
	write(1, &n, 1);
}

static int	ft_sign(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		return ((unsigned int)(nb * -1));
	}
	return (nb);
}

int	ft_i(int nb)
{
	int				i;
	unsigned int	snum;
	unsigned int	num;
	int				j;

	i = 0;
	if (nb < 0)
		i = 1;
	num = ft_sign(nb);
	j = 1;
	snum = num;
	while (num > 9)
	{
		j = j * 10;
		num = num / 10;
		i++;
	}
	while (j > 0)
	{
		ft_putchar(snum / j + 48);
		snum = snum - (snum / j) * j;
		j = j / 10;
	}
	return (i + 1);
}
