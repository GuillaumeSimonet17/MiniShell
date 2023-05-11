/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:38:04 by gusimone          #+#    #+#             */
/*   Updated: 2022/11/13 14:57:05 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*new;

	new = NULL;
	if (!f)
		return (NULL);
	while (lst)
	{
		nlst = ft_lstnew(f(lst->content));
		if (!nlst)
		{
			ft_lstclear(&nlst, (del));
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&new, nlst);
	}
	return (new);
}
