/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:20:20 by strieste          #+#    #+#             */
/*   Updated: 2025/10/06 17:32:49 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*s_p;

	while (*lst)
	{
		s_p = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		(*lst) = s_p;
	}
	(*lst) = ((void *)0);
}
