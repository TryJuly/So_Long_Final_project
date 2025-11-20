/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 09:22:08 by strieste          #+#    #+#             */
/*   Updated: 2025/10/07 18:42:34 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*p_dest;
	unsigned char	*p_src;
	size_t			count;

	if (!src && !dest)
		return ((void *) 0);
	if ((dest == src) || n == 0)
		return (dest);
	count = 0;
	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	if (dest > src)
		while (n--)
			p_dest[n] = p_src[n];
	else
	{
		while (n--)
		{
			p_dest[count] = p_src[count];
			count++;
		}
	}
	return (dest);
}
