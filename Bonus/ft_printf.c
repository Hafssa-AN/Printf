/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 23:20:05 by hanebaro          #+#    #+#             */
/*   Updated: 2024/01/17 12:51:35 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	g_count;

static void	app(char *c, va_list fa, int *i)
{
	if (ft_strchr("-0.# +123456789",*c))
		*i += ft_comb_flags(c, fa);
	else if (*c == '%')
		ft_putchar('%');
	else if (*c == 'd' || *c == 'i')
		ft_putnbr(va_arg(fa, int));
	else if (*c == 'x')
		ft_base(va_arg(fa, unsigned int), "0123456789abcdef");
	else if (*c == 'X')
		ft_base(va_arg(fa, unsigned int), "0123456789ABCDEF");
	else if (*c == 'u')
		ft_base(va_arg(fa, unsigned int), "0123456789");
	else if (*c == 'c')
		ft_putchar(va_arg(fa, int));
	else if (*c == 's')
		ft_putstr(va_arg(fa, char *));
	else if (*c == 'p')
	{
		ft_putstr("0x");
		ft_adr(va_arg(fa, unsigned long));
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	fa;

	g_count = 0;
	i = 0;
	va_start(fa, str);
	while (str[i])
	{
		if (str[i] == '%')
			app((char *)(str + (++i)), fa, &i);
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(fa);
	return (g_count);
}
