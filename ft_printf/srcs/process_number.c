/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 01:39:12 by adedieu           #+#    #+#             */
/*   Updated: 2022/12/01 04:00:33 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	process_number(int number)
{
	int	size;
	int	sign;

	size = 1;
	sign = 1;
	if (number < 0)
	{
		ft_putchar_fd('-', 1);
		sign = -sign;
		size ++;
	}
	if (number > 9 || number < -9)
		size += process_number((number / 10) * sign);
	ft_putchar_fd((number % 10) * sign + '0', 1);
	return (size);
}

int	process_unsigned(unsigned int number)
{
	int	size;
	int	sign;

	size = 1;
	sign = 1;
	if (number > 9)
		size += process_unsigned((number / 10) * sign);
	ft_putchar_fd((number % 10) * sign + '0', 1);
	return (size);
}
