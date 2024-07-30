/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:08:05 by hanebaro          #+#    #+#             */
/*   Updated: 2024/01/26 13:08:10 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	un_intlen(unsigned long x, char *base)
{
	int	count;

	if (x == 0)
		return (1);
	count = 0;
	while (x != 0)
	{
		x /= (int)ft_strlen(base);
		count++;
	}
	return (count);
}

void	add_pref(unsigned int x, char *base, int *tab)
{
	if (*(tab + 2) && !ft_strncmp(base, "0123456789abcdef", 16) && x != 0)
		ft_putstr("0x");
	else if (*(tab + 2) && !ft_strncmp(base, "0123456789ABCDEF", 16) && x != 0)
		ft_putstr("0X");
}

void	print_nmbr(unsigned int x, char *base, int *tab)
{
	if (x == 0 && *(tab + 6) && !*(tab + 7) && *(tab + 5))
		ft_putchar(' ');
	else if (x == 0 && *(tab + 6) && !*(tab + 7))
		ft_putstr("");
	else
		ft_base(x, base);
}
