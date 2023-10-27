/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:05:28 by adedieu           #+#    #+#             */
/*   Updated: 2022/11/24 22:52:40 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"	

static size_t	nb_words(char const *s, char c)
{
	size_t	nb;

	nb = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
			s++;
		if (*(s - 1) != c)
			nb++;
	}
	return (nb);
}

static size_t	word_size(char const *s, char c)
{
	size_t	size;

	size = 0;
	while (s[size] && s[size] != c)
		size++;
	return (size);
}

static char	*cp_word(char const *s, char c, size_t *ptr_index)
{
	char	*string;
	size_t	len;
	size_t	i;

	while (s[*ptr_index] && s[*ptr_index] == c)
		(*ptr_index)++;
	len = word_size((s + *ptr_index), c);
	string = malloc(len + 1);
	if (!string)
		return (NULL);
	string[len] = '\0';
	i = 0;
	while (i < len)
	{
		string[i] = s[*ptr_index];
		i++;
		(*ptr_index)++;
	}
	return (string);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	size_t	len_strings;
	size_t	index;
	size_t	index_bis;

	if (!s)
		return (NULL);
	len_strings = nb_words(s, c);
	strings = malloc(sizeof(char *) * (len_strings + 1));
	if (!strings)
		return (NULL);
	index = 0;
	index_bis = 0;
	strings[len_strings] = NULL;
	while (index < len_strings)
	{
		strings[index] = cp_word(s, c, &index_bis);
		index++;
	}
	return (strings);
}
