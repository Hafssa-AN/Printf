/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb_putstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:27:26 by hanebaro          #+#    #+#             */
/*   Updated: 2024/01/25 00:27:29 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	point(char *str, int *tab, int len)
{
	int	i;

	i = 0;
	if (*tab)
	{
		while (i < len)
			ft_putchar(str[i++]);
		if (*(tab + 5))
		{
			while (i++ < *(tab + 5))
				ft_putchar(' ');
		}
	}
	else
	{
		if (*(tab + 5))
		{
			while (i++ < *(tab + 5) - len)
				ft_putchar(' ');
		}
		i = 0;
		while (i < len)
			ft_putchar(str[i++]);
	}
}

static void	fnct(char *str, int *tab, int i, int len)
{
	if (*tab)
	{
		while (i < len)
			ft_putchar(str[i++]);
		if (*(tab + 5))
		{
			while (i++ < *(tab + 5))
				ft_putchar(' ');
		}
	}
	else
	{
		if (*(tab + 5))
		{
			while (i++ < *(tab + 5) - len)
				ft_putchar(' ');
		}
		i = 0;
		while (i < len)
			ft_putchar(str[i++]);
	}
}

void	ft_comb_putstr(char *str, int *tab)
{
	int	len;
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (*(tab + 6))
	{
		if (*(tab + 7) <= (int)ft_strlen(str))
			len = *(tab + 7);
		point(str, tab, len);
	}
	else
		fnct(str, tab, i, len);
}
