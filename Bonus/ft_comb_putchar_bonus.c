/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb_putchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:02:23 by hanebaro          #+#    #+#             */
/*   Updated: 2024/01/24 18:02:27 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_comb_putchar(int x, int *tab)
{
	int	i;

	i = 0;
	if (*tab && *(tab + 5))
	{
		ft_putchar(x);
		while (++i < *(tab + 5))
			ft_putchar(' ');
	}
	else if (*(tab + 5))
	{
		while (++i < *(tab + 5))
			ft_putchar(' ');
		ft_putchar(x);
	}
	else
		ft_putchar(x);
}
