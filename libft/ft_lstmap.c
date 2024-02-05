/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:28:58 by kmatsuka          #+#    #+#             */
/*   Updated: 2023/09/29 14:46:30 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new_lst;
	t_list	*node;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_lst = ft_lstnew(f((*lst).content));
	if (new_lst == NULL)
		return (NULL);
	lst = (*lst).next;
	while (lst)
	{
		node = ft_lstnew(f((*lst).content));
		if (node == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, node);
		lst = (*lst).next;
	}
	return (new_lst);
}
