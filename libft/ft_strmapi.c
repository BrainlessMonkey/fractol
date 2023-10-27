/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:07:50 by adedieu           #+#    #+#             */
/*   Updated: 2022/11/23 02:16:30 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*string;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	string = malloc(len + 1);
	if (!string)
		return (NULL);
	string[len] = '\0';
	while (len > 0)
	{
		len--;
		string[len] = (*f)(len, s[len]);
	}
	return (string);
}
