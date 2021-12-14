/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:13:12 by mait-aad          #+#    #+#             */
/*   Updated: 2021/12/14 21:24:12 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_getargs(char c, va_list ptr)
{
	int	k;

	k = 0;
	if (c == 'x')
		k = ft_x(va_arg(ptr, unsigned int));
	else if (c == 'X')
		k = ft_phex(va_arg(ptr, unsigned int));
	else if (c == 'c')
		k = ft_c(va_arg(ptr, int));
	else if (c == '%')
		k = ft_persent();
	else if (c == 'i' || c == 'd')
		k = ft_i(va_arg(ptr, int));
	else if (c == 's')
		k = ft_s(va_arg(ptr, char *));
	else if (c == 'u')
		k = ft_u(va_arg(ptr, unsigned int));
	else if (c == 'p')
		k = ft_p(va_arg(ptr, void *));
	return (k);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		k;
	int		j;
	va_list	ptr;

	va_start(ptr, s);
	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == '%')
		{
			i++;
			k += ft_getargs(s[i], ptr);
			i++;
			if (s[i] == '\0')
				return (j + k);
		}
		write(1, &s[i], 1);
		j++;
		i++;
	}
	va_end(ptr);
	return (j + k);
}
