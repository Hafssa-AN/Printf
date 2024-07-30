/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pourcentage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:31:00 by hanebaro          #+#    #+#             */
/*   Updated: 2024/02/04 19:31:54 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pourcentage(int *tab)
{
	if (*tab)
	{
		ft_putchar('%');
		if (*(tab + 5))
			(*(tab + 5))--;
		while ((*(tab + 5))--)
			ft_putchar(' ');
	}
	else
	{
		if (*(tab + 5))
			(*(tab + 5))--;
		while ((*(tab + 5))--)
			ft_putchar(' ');
		ft_putchar('%');
	}
}
