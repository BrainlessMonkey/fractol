/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:09:31 by adedieu           #+#    #+#             */
/*   Updated: 2022/11/25 03:41:35 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *) s1);
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && start < end)
		start++;
	while (ft_strchr(set, s1[end]) && end > start)
		end--;
	s = malloc((end - start) + 2);
	if (!s)
		return (NULL);
	i = 0;
	while (start <= end)
		s[i++] = s1[start++];
	s[i] = '\0';
	return (s);
}
