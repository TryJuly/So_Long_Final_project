/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 07:48:44 by strieste          #+#    #+#             */
/*   Updated: 2025/10/02 07:48:49 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*p_dest;
	unsigned const char	*p_src;
	size_t				count;

	if (!dest && !src)
		return ((void *) 0);
	p_dest = dest;
	p_src = src;
	count = 0;
	while (count < n)
	{
		p_dest[count] = p_src[count];
		count++;
	}
	return (dest);
}
