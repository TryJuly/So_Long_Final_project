/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 07:50:51 by strieste          #+#    #+#             */
/*   Updated: 2025/10/03 13:51:04 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check(char const s1, char const *set)
{
	size_t	count;

	count = 0;
	while (set[count])
	{
		if (s1 == set[count])
			return (1);
		count++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p_str;
	size_t	start;
	size_t	end;
	size_t	count;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_check(s1[start], set))
		start++;
	while (end > start && ft_check(s1[end - 1], set))
		end--;
	p_str = (char *)malloc(((end - start) + 1) * sizeof(char));
	if (!p_str)
		return ((void *)0);
	count = 0;
	while (start < end)
	{
		p_str[count] = s1[start];
		start++;
		count++;
	}
	p_str[count] = '\0';
	return (p_str);
}
