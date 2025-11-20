/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 07:47:18 by strieste          #+#    #+#             */
/*   Updated: 2025/10/02 07:47:22 by strieste         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*p_s;

	count = 0;
	p_s = (unsigned char *)s;
	while (count < n)
	{
		if (p_s[count] == (unsigned char)c)
			return ((void *)&p_s[count]);
		count++;
	}
	return ((void *) 0);
}
