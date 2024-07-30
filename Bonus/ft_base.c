/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:58:45 by hanebaro          #+#    #+#             */
/*   Updated: 2024/01/17 12:58:48 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_base(unsigned int x, char *base)
{
	if (x <= ft_strlen(base) - 1)
		ft_putchar(base[x]);
	else
	{
		ft_base(x / ft_strlen(base), base);
		ft_base(x % ft_strlen(base), base);
	}
}
