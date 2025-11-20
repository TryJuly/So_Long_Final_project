/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:10:03 by strieste          #+#    #+#             */
/*   Updated: 2025/10/03 17:01:49 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	count;

	count = ft_strlen(s);
	if ((unsigned char) c == '\0')
		return ((char *)&s[count]);
	while (count > 0)
	{
		if (s[count] == (unsigned char) c)
			return ((char *)&s[count]);
		count--;
	}
	if (s[0] == (unsigned char) c)
		return ((char *)&s[0]);
	return ((void *) 0);
}
