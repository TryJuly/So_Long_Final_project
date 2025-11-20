/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:37:54 by strieste          #+#    #+#             */
/*   Updated: 2025/10/03 11:30:30 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	count;

	if ((unsigned char)c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	count = 0;
	while (s[count])
	{
		if (s[count] == (unsigned char)c)
			return ((char *)&s[count]);
		count++;
	}
	return ((void *) 0);
}
