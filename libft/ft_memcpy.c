/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:02:39 by adedieu           #+#    #+#             */
/*   Updated: 2022/11/23 02:37:55 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	while (n > 0)
	{
		*(unsigned char *)(dest + n - 1) = *(unsigned char *)(src + n - 1);
		n--;
	}
	return (dest);
}
