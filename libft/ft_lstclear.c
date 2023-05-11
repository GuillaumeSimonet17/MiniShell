/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:36:43 by gusimone          #+#    #+#             */
/*   Updated: 2022/11/12 15:11:53 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;

	if (!lst)
		return ;
	ptr = *lst;
	if (*lst)
	{
		while (ptr)
		{
			ptr = ptr->next;
			ft_lstdelone(*lst, del);
			*lst = ptr;
		}
	}
}
