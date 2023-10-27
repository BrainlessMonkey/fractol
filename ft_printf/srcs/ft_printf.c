/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:32:03 by adedieu           #+#    #+#             */
/*   Updated: 2022/12/01 04:57:30 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

static int	manage_arg(const char *string, va_list *args)
{
	if (*string == 'c')
	{
		ft_putchar_fd ((char)va_arg(*args, int), 1);
		return (1);
	}
	if (*string == 's')
		return (process_string(va_arg(*args, char *)));
	if (*string == 'p')
		return (process_pointer(va_arg(*args, void *)));
	if (*string == 'd' || *string == 'i')
		return (process_number(va_arg(*args, int)));
	if (*string == 'u')
		return (process_unsigned(va_arg(*args, unsigned int)));
	if (*string == 'x')
		return (process_lower_hexa(va_arg(*args, unsigned int)));
	if (*string == 'X')
		return (process_upper_hexa(va_arg(*args, unsigned int)));
	if ((*string == '%'))
	{
		ft_putchar_fd ('%', 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		size;

	va_start(args, string);
	if (!string)
		return (-1);
	size = 0;
	while (*string)
	{
		if (*string == '%')
			size += manage_arg((++string), &args);
		else
		{
			ft_putchar_fd (*string, 1);
			size++;
		}
		string++;
	}
	va_end(args);
	return (size);
}
