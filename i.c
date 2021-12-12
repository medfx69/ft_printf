/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:24:00 by mait-aad          #+#    #+#             */
/*   Updated: 2021/12/12 15:27:19 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char n)
{
	write(1, &n, 1);
}

int	ft_i(int nb)
{
	static int				i;

	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
		i++;
	}
	if (nb > 0)
	{
		i++;
		ft_d(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
	if (nb < 10)
		ft_putchar(nb);
	return (i);
}
