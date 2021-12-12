/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:53:53 by mait-aad          #+#    #+#             */
/*   Updated: 2021/12/12 17:49:14 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char n)
{
	write(1, &n, 1);
}

int	ft_d(int nb)
{
	static int		i;
	unsigned int	num;

	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
		i++;
	}
	num = (unsigned int) nb;
	if (num > 0)
	{
		ft_d(num / 10);
		i++;
		ft_putchar(num % 10 + 48);
	}
	return (i - 2);
}
