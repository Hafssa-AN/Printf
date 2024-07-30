/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:52:02 by hanebaro          #+#    #+#             */
/*   Updated: 2024/01/17 12:52:05 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nn)
{
	if (nn == -2147483648)
		ft_putstr("-2147483648");
	else if (nn >= 0 && nn <= 9)
		ft_putchar(48 + nn);
	else if (nn < 0)
	{
		ft_putchar('-');
		ft_putnbr(nn * -1);
	}
	else
	{
		ft_putnbr(nn / 10);
		ft_putnbr(nn % 10);
	}
}
