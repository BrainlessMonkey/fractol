/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:08:52 by adedieu           #+#    #+#             */
/*   Updated: 2022/11/25 06:39:09 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 && !len)
		return (NULL);
	if (!s2[0])
		return ((char *)s1);
	while (s1[i] && i < len)
	{
		j = 0;
		while (i + j < len && s1[i + j] && s2[j] && s1[i + j] == s2[j])
			j++;
		if (s2[j] == '\0')
			return ((char *) s1 + i);
		i++;
	}
	return (NULL);
}
