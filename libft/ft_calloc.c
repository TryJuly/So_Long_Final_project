/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 08:33:35 by strieste          #+#    #+#             */
/*   Updated: 2025/10/07 18:49:50 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p_calloc;	
	size_t	length;

	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	length = (nmemb * size);
	p_calloc = malloc(length);
	if (!p_calloc)
		return (NULL);
	ft_bzero(p_calloc, length);
	return (p_calloc);
}
