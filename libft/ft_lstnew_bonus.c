/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:27:21 by strieste          #+#    #+#             */
/*   Updated: 2025/10/08 08:03:41 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list			*p_list;

	p_list = malloc(sizeof(*p_list));
	if (!p_list)
		return ((void *)0);
	p_list->content = content;
	p_list->next = ((void *)0);
	return (p_list);
}
