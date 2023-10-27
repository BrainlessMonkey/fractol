/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:05:18 by adedieu           #+#    #+#             */
/*   Updated: 2022/11/24 20:11:04 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;
	t_list	*next;

	if (!lst || !*lst)
		return ;
	elem = *lst;
	while (elem)
	{
		next = elem->next;
		ft_lstdelone(elem, *del);
		elem = next;
	}
	*lst = NULL;
}
