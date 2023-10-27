/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:01:25 by adedieu           #+#    #+#             */
/*   Updated: 2022/11/24 23:56:33 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	len_number(int n)
{
	size_t	len;

	len = 1;
	if (n < 0)
		len++;
	while (n > 9 || n < -9)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*string;
	size_t	len;

	len = len_number(n);
	string = malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	string[len] = '\0';
	if (n <= 0)
	{
		string[0] = '-';
		string[--len] = -(n % 10) + '0';
		n = -(n / 10);
	}
	while (n != 0)
	{
		string[--len] = (n % 10) + '0';
		n = n / 10;
	}
	return (string);
}
