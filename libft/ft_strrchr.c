/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:09:02 by adedieu           #+#    #+#             */
/*   Updated: 2022/11/25 05:33:58 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	int		i;

	last = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			last = (char *)(s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (last);
}
