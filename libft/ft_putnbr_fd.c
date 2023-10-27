/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:04:50 by adedieu           #+#    #+#             */
/*   Updated: 2022/11/24 23:49:31 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_putposnbr_fd(int n, int fd)
{
	if (n > 9)
		ft_putposnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
	{
		return ;
	}
	if (n >= 0)
		ft_putposnbr_fd(n, fd);
	else if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		n *= -1;
		ft_putchar_fd('-', fd);
		ft_putposnbr_fd(n, fd);
	}
}
