/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 01:32:56 by adedieu           #+#    #+#             */
/*   Updated: 2022/12/01 05:11:35 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	process_pointer(void *p)
{
	if (!p)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	ft_putstr_fd("0x", 1);
	return (process_lower_hexa((unsigned long)p) + 2);
}

int	process_lower_hexa(unsigned long n)
{
	int		size;
	char	*base;

	size = 1;
	base = "0123456789abcdef";
	if (n > 15)
		size += process_lower_hexa(n / 16);
	ft_putchar_fd(base[n % 16], 1);
	return (size);
}

int	process_upper_hexa(unsigned int n)
{
	int		size;
	char	*base;

	size = 1;
	base = "0123456789ABCDEF";
	if (n > 15)
		size += process_upper_hexa(n / 16);
	ft_putchar_fd(base[n % 16], 1);
	return (size);
}
