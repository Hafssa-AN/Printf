/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:11:05 by hanebaro          #+#    #+#             */
/*   Updated: 2024/01/22 16:11:08 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	choix(char c, int *tab, va_list fa)
{
	if (c == '%')
		ft_pourcentage(tab);
	else if (c == 'd' || c == 'i')
		ft_comb_nbr(va_arg(fa, int), tab);
	else if (c == 'x')
		ft_comb_base(va_arg(fa, unsigned int), "0123456789abcdef", tab);
	else if (c == 'X')
		ft_comb_base(va_arg(fa, unsigned int), "0123456789ABCDEF", tab);
	else if (c == 'u')
		ft_comb_base(va_arg(fa, unsigned int), "0123456789", tab);
	else if (c == 'c')
		ft_comb_putchar(va_arg(fa, int), tab);
	else if (c == 's')
		ft_comb_putstr(va_arg(fa, char *), tab);
	else if (c == 'p')
		ft_comb_adr(va_arg(fa, unsigned long), tab);
}

static void	init_table(int *exist)
{
	int	i;

	i = 0;
	while (i < 8)
		exist[i++] = 0;
}

int	ft_comb_flags(char *c, va_list fa)
{
	int	i;
	int	exist[8];
	int	nmb;

	nmb = 0;
	init_table(exist);
	i = 0;
	while (ft_strchr("-0# +", *(c + i)))
		exist[ft_strchr("-0# +", *(c + (i++))) - 1] = 1;
	while (ft_strchr("0123456789", *(c + i)))
		nmb = nmb * 10 + (*(c + (i++)) - 48);
	exist[5] = nmb;
	if (*(c + i) == '.')
	{
		exist[6] = 1;
		i++;
	}
	nmb = 0;
	while (ft_strchr("0123456789",*(c + i)))
		nmb = nmb * 10 + (*(c + (i++)) - 48);
	exist[7] = nmb;
	if (ft_strchr("scdiuxXp", *(c + i)) || *(c + i) == '%')
		choix(*(c + i), exist, fa);
	return (i);
}
