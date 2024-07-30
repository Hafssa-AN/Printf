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

void	rev(unsigned int x, char *base, int *tab, int len)
{
	int	i;

	i = len;
	if (*(tab + 2) && x != 0)
	{
		add_pref(x, base, tab);
		len += 2;
	}
	if (*(tab + 6))
	{
		while (i++ < *(tab + 7))
			ft_putchar('0');
	}
	print_nmbr(x, base, tab);
	if (*(tab + 5))
	{
		if (un_intlen(x, base) < *(tab + 7))
		{
			len = *(tab + 7);
			if (*(tab + 2) && x != 0)
				len += 2;
		}
		while ((*(tab + 5))-- > len)
			ft_putchar(' ');
	}
}

void	add_0(unsigned int x, char *base, int *tab, int len)
{
	if (*(tab + 2) && x != 0 && !*(tab + 6))
		add_pref(x, base, tab);
	if (*(tab + 5))
	{
		if (len < *(tab + 7))
			len = *(tab + 7);
		if (*(tab + 2) && x != 0)
			len += 2;
		while ((*(tab + 5)) > len++)
		{
			if (*(tab + 6))
				ft_putchar(' ');
			else
				ft_putchar('0');
		}
	}
	if (*(tab + 2) && x != 0 && *(tab + 6))
		add_pref(x, base, tab);
	if (*(tab + 6))
	{
		len = un_intlen(x, base);
		while (len++ < *(tab + 7))
			ft_putchar('0');
	}
	print_nmbr(x, base, tab);
}

void	all(unsigned int x, char *base, int *tab, int len)
{
	if (*(tab + 5))
	{
		if (len < *(tab + 7) && *(tab + 6))
			len = *(tab + 7);
		if (*(tab + 2) && x != 0)
			len += 2;
		while ((*(tab + 5)) > len++)
			ft_putchar(' ');
	}
	if (*(tab + 2) && x != 0)
		add_pref(x, base, tab);
	if (*(tab + 6))
	{
		if (*(tab + 6))
			len = un_intlen(x, base);
		while (len++ < *(tab + 7))
			ft_putchar('0');
	}
	print_nmbr(x, base, tab);
}

void	ft_comb_base(unsigned int x, char *base, int *tab)
{
	int	len;

	len = un_intlen(x, base);
	if (*tab)
		rev(x, base, tab, len);
	else if (*(tab + 1))
		add_0(x, base, tab, len);
	else
		all(x, base, tab, len);
}
