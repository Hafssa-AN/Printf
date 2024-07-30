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
void	ft_comb_nbr(int x, int *tab);
int		ft_comb_flags(char *c, va_list fa);
int		ft_strchr(const char *s, int c);
void	ft_comb_putchar(int x, int *tab);
void	choix(char c, int *tab, va_list fa);
void	ft_comb_putstr(char *str, int *tab);
void	ft_comb_base(unsigned int x, char *base, int *tab);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_comb_adr(unsigned long p, int *tab);
void	ft_pourcentage(int *tab);
int		un_intlen(unsigned long x, char *base);
void	add_pref(unsigned int x, char *base, int *tab);
void	print_nmbr(unsigned int x, char *base, int *tab);
void	add_sign(int x, int *tab);
void	add_num(int x, int *tab);
void	add_zr(int x, int *tab, int len);

#endif