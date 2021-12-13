/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:13:12 by mait-aad          #+#    #+#             */
/*   Updated: 2021/12/13 15:22:13 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_getargs(char c, va_list ptr)
{
	int	k;

	if (c == 'x')
		k = ft_x(va_arg(ptr, unsigned int));
	else if (c == 'X')
		k = ft_phex(va_arg(ptr, unsigned int));
	// else if (c == 'd')
	// 	k = ft_d(va_arg(ptr, int));
	else if (c == 'c')
		k = ft_c(va_arg(ptr, int));
	else if (c == '%')
		k = ft_persent();
	else if (c == 'i')
		k = ft_i(va_arg(ptr, int));
	else if (c == 's')
		k = ft_s(va_arg(ptr, char *));
	else if (c == 'u')
		k = ft_u(va_arg(ptr, unsigned int));
	else if (c == 'p')
		k = ft_p(va_arg(ptr, void *));
	// printf("======>%d",k);
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
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			k = ft_getargs(s[i], ptr);
			i++;
		}
		write(1, &s[i], 1);
		j++;
		i++;
	}
	va_end(ptr);
	// printf ("--------------2----------------");
	//printf("%d",i);
	return (j + k);
}

// int main()
// {
// 	int i;

// 	i = ft_printf(" %i %i %i %i %i %i %i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));

// 	ft_printf("\nreturn = %d\n", i);

// }