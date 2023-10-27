/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:11:27 by adedieu           #+#    #+#             */
/*   Updated: 2022/11/25 02:56:59 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s_return;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		len = 0;
	else if (len >= s_len)
		len = s_len - start;
	s_return = malloc(len + 1);
	if (!len)
	{
		s_return[0] = '\0';
		return (s_return);
	}
	if (!s_return)
		return (NULL);
	s_return[len] = '\0';
	while (--len > 0)
		s_return[len] = s[start + len];
	s_return[len] = s[start + len];
	return (s_return);
}
