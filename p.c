/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:28:58 by mait-aad          #+#    #+#             */
/*   Updated: 2021/12/12 14:32:40 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printinhex(unsigned long int p)
{
	static int	i;

	if (p > 16)
	{
		i++;
		printinhex(p / 16);
	}
	if (p < 16)
		i++;
	p = p % 16;
	if (p > 9)
		p = p + 87;
	else
		p = p + 48;
	write(1, &p, 1);
	return (i);
}

int	ft_p(void	*p)
{
	int	i;

	write(1, "0x", 2);
	i = printinhex((unsigned long int )p);
	return (i + 2);
}
