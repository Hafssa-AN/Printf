/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb_nbr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:24:45 by hanebaro          #+#    #+#             */
/*   Updated: 2024/01/22 18:26:50 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_sign(int x, int *tab)
{
	if (*(tab + 4))
	{
		if (x >= 0)
			ft_putchar('+');
		else
			ft_putchar('-');
	}
	else if (x >= 0)
		ft_putchar(' ');
	else
		ft_putchar('-');
}

void	add_num(int x, int *tab)
{
	if (x == 0 && *(tab + 6) && !*(tab + 7) 
		&& *(tab + 5) && !(*(tab + 3) || *(tab + 4)))
		ft_putchar(' ');
	else if (x == 0 && *(tab + 6) && !*(tab + 7))
		ft_putstr("");
	else if (x == -2147483648)
		ft_putstr("2147483648");
	else
	{
		if (x < 0)
			ft_putnbr(-x);
		else
			ft_putnbr(x);
	}
}

void	add_zr(int x, int *tab, int len)
{
	if (len < *(tab + 7))
		len = *(tab + 7);
	if (((*(tab + 3) || *(tab + 4)) && x >= 0) || x < 0)
		(*(tab + 5))--;
	while ((*(tab + 5))-- > len)
		ft_putchar('0');
}
