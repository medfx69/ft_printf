/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   X.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:42:02 by mait-aad          #+#    #+#             */
/*   Updated: 2021/12/14 20:34:01 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_phex(unsigned int p)
{
	int		i;
	int		j;
	char	save[30];

	i = 0;
	if (p == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (p != 0)
	{
		j = p % 16;
		if (j <= 9)
			save[i++] = j + 48;
		else
			save[i++] = j + 55;
		p = p / 16;
	}
	j = i;
	while (--i >= 0)
		write(1, &save[i], 1);
	return (j);
}
