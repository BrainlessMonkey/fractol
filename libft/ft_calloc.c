/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:59:20 by adedieu           #+#    #+#             */
/*   Updated: 2022/11/25 04:15:10 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stdlib.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	while (i < nmemb * size)
		*(mem + i++) = 0;
	return (mem);
}
