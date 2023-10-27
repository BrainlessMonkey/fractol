/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:06:44 by adedieu           #+#    #+#             */
/*   Updated: 2022/11/22 23:15:31 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	len;
	char	*s3;
	char	*s1_save;

	s1_save = (char *)s1;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = malloc(len);
	if (s3 == NULL)
		return (NULL);
	i = 0;
	while (i < len - 1)
	{
		if (*s1)
			s3[i] = *(s1++);
		else
			s3[i] = *(s2++);
		i++;
	}
	s3[i] = '\0';
	free(s1_save);
	return (s3);
}
