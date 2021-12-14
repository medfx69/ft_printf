/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:44:03 by mait-aad          #+#    #+#             */
/*   Updated: 2021/12/13 15:19:06 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int	ft_c(int c);
// int	ft_d(int nb);
int	ft_x(unsigned int p);
int	ft_p(void	*p);
int	ft_persent(void);
int	ft_s(char *s);
int	ft_u(int nb);
int	ft_phex(unsigned int p);
int	ft_i(int i);
int	ft_printf(const char *s, ...);

#endif