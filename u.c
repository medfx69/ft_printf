/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:18:46 by mait-aad          #+#    #+#             */
/*   Updated: 2021/12/11 17:49:30 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char n)
{
	write(1, &n, 1);
}

int	ft_u(int nb)
{
	unsigned int	i;
	unsigned int	snum;
	unsigned int	j;
	unsigned int	num;

	j = 1;
	num = (unsigned int)nb;
	snum = num;
	i = 0;
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
