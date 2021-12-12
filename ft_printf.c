/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:13:12 by mait-aad          #+#    #+#             */
/*   Updated: 2021/12/12 17:50:48 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ofints(int i, char c)
{
	int	k;

	if (c == 'x')
		k = ft_x(i);
	else if (c == 'X')
		k = ft_phex(i);
	else if (c == 'd')
		k = ft_d(i);
	else if (c == 'c')
		k = ft_c(i);
	else if (c == '%')
		k = ft_persent();
	else if (c == 'i')
		k = ft_i(i);
	return (k);
}

int	get_ret(const char *s)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == '%')
			i += 2;
		n++;
		i++;
	}
	return (n);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		k;
	va_list	ptr;

	va_start(ptr, s);
	i = 0;
	while (s[i] && s[i - 1])
	{
		if (s[i] == '%')
		{
			if (s[++i] == 'p')
				k = ft_p(va_arg(ptr, void *));
			else if (s[i] == 'x' || s[i] == 'X' || s[i] == 'd' || s[i] == 'c'
				|| s[i] == '%' || s[i] == 'i')
				k = ft_ofints(va_arg(ptr, int), s[i]);
			else if (s[i] == 's')
				k = ft_s(va_arg(ptr, char *));
			else if (s[i] == 'u')
				k = ft_u(va_arg(ptr, unsigned int));
				i++;
		}
		write(1, &s[i++], 1);
	}
	va_end(ptr);
	return (get_ret(s) + k);
}

int main()
{
	int i;
	
	i = ft_printf("\n%c\n", 'c');
	ft_printf("\nreturn = %d\n", i);
}