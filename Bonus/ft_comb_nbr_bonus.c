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

static int	intlen(int x)
{
	int	count;

	if (x == 0)
		return (1);
	count = 0;
	while (x != 0)
	{
		x /= 10;
		count++;
	}
	return (count);
}

void	zero(int x, int *tab, int len)
{
	if ((*(tab + 3) || *(tab + 4)))
		add_sign(x, tab);
	else if (x < 0 && !*(tab + 6))
		ft_putchar('-');
	if (*(tab + 5))
		add_zr(x, tab, len);
	if (x < 0 && *(tab + 6))
		ft_putchar('-');
	if (*(tab + 6))
	{
		while (len++ < *(tab + 7))
			ft_putchar('0');
	}
	if (x == 0 && *(tab + 6) && !*(tab + 7))
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

static void	minus(int x, int *tab, int len)
{
	int	i;

	if ((*(tab + 3) || *(tab + 4)))
		add_sign(x, tab);
	else if (x < 0)
		ft_putchar('-');
	i = len;
	if (*(tab + 6))
	{
		while (i++ < *(tab + 7))
			ft_putchar('0');
	}
	add_num(x, tab);
	if (*(tab + 5))
	{
		if (len < *(tab + 7))
			len = *(tab + 7);
		if (((*(tab + 3) || *(tab + 4)) && x >= 0 
				&& !(x == 0 && x == 0 && *(tab + 6) && !*(tab + 7))) || x < 0)
			(*(tab + 5))--;
		while ((*(tab + 5))-- > len)
			ft_putchar(' ');
	}
}

static void	norm(int x, int *tab, int len)
{
	if (*(tab + 5))
	{
		if (len < *(tab + 7) && *(tab + 6))
			len = *(tab + 7);
		if (((*(tab + 3) || *(tab + 4)) && x >= 0 
				&& !(x == 0 && *(tab + 6) && !*(tab + 7))) || x < 0)
			(*(tab + 5))--;
		while ((*(tab + 5))-- > len)
			ft_putchar(' ');
		*(tab + 5) = 1;
	}
	if ((*(tab + 3) || *(tab + 4)))
		add_sign(x, tab);
	else if (x < 0)
		ft_putchar('-');
	if (*(tab + 6))
	{
		if (*(tab + 6))
			len = intlen(x);
		while (len++ < *(tab + 7))
			ft_putchar('0');
	}
	add_num(x, tab);
}

void	ft_comb_nbr(int x, int *tab)
{
	int	len;

	len = intlen(x);
	if (*tab)
		minus(x, tab, len);
	else if (*(tab + 1) && !*(tab + 6))
		zero(x, tab, len);
	else
		norm(x, tab, len);
}
