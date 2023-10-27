/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:06:58 by adedieu           #+#    #+#             */
/*   Updated: 2022/11/24 20:07:10 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_second;
	t_list	*start;

	if (!lst || !f)
		return (NULL);
	lst_second = ft_lstnew((*f)(lst->content));
	if (!lst_second)
		return (NULL);
	start = lst_second;
	while (lst->next)
	{
		lst = lst->next;
		lst_second->next = ft_lstnew((*f)(lst->content));
		if (!lst_second)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		lst_second = lst_second->next;
	}
	return (start);
}
