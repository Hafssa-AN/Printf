/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:26:04 by hanebaro          #+#    #+#             */
/*   Updated: 2024/01/16 22:26:33 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

extern int	g_count;

int		ft_printf(const char *str, ...);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_base(unsigned int x, char *base);
void	ft_putstr(char *s);
size_t	ft_strlen(const char *s);
void	ft_adr(unsigned long p);

#endif