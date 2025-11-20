/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:20:08 by strieste          #+#    #+#             */
/*   Updated: 2025/10/08 08:03:35 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p_new;
	t_list	*p_add;
	void	*content;

	if (!lst || !f)
		return ((void *)0);
	p_new = ((void *)0);
	while (lst)
	{
		content = f(lst->content);
		if (!content)
		{
			ft_lstclear(&p_new, del);
			return ((void *)0);
		}
		p_add = ft_lstnew(content);
		if (!p_add)
		{
			ft_lstclear(&p_new, del);
			return ((void *)0);
		}
		ft_lstadd_back(&p_new, p_add);
		lst = lst->next;
	}
	return (p_new);
}
