/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:17:47 by hanebaro          #+#    #+#             */
/*   Updated: 2024/01/19 11:17:51 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s)
{
	int		i;

	i = 0;
	if (!s)
	{
		s = "(null)";
		while (s[i])
			ft_putchar(s[i++]);
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}
