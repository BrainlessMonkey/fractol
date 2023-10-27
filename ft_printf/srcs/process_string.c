/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 01:39:31 by adedieu           #+#    #+#             */
/*   Updated: 2022/12/01 03:43:26 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	process_string(const char *string)
{
	int	size;

	size = 0;
	if (!string)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (*string)
	{
		ft_putchar_fd(*string, 1);
		size++;
		string++;
	}
	return (size);
}
