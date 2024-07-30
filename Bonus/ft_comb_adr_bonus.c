/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:09:22 by hanebaro          #+#    #+#             */
/*   Updated: 2024/01/19 13:09:25 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	uns_intlen(unsigned long x)
{
	int	count;

	if (x == 0)
		return (1);
	count = 0;
	while (x != 0)
	{
		x /= 16;
		count++;
	}
	return (count);
}

void	ft_comb_adr(unsigned long p, int *tab)
{
	int	i;

	if (*tab)
	{
		ft_putstr("0x");
		ft_adr(p);
		i = uns_intlen(p);
		while ((*(tab + 5) - 2) > i++)
			ft_putchar(' ');
	}
	else
	{
		i = uns_intlen(p);
		while ((*(tab + 5) - 2) > i++)
			ft_putchar(' ');
		ft_putstr("0x");
		ft_adr(p);
	}
}
