/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:06:58 by adedieu           #+#    #+#             */
/*   Updated: 2022/11/25 06:31:21 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size == 0 && !dst)
		return (0);
	while (dst[j] != '\0')
		j++;
	while (src[i] && i + j < size - 1 && size)
	{
		dst[i + j] = src [i];
		i++;
	}
	dst[i + j] = '\0';
	while (src[i] != '\0')
		i++;
	if (j >= size)
		j = size;
	return (j + i);
}
