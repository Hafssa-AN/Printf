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

void	ft_adr(unsigned long p)
{
	char	*base;

	base = "0123456789abcdef";
	if (p <= 15)
		ft_putchar(base[p]);
	else
	{
		ft_adr(p / 16);
		ft_adr(p % 16);
	}
}
