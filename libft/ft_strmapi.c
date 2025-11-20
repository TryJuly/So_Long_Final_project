/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:17:03 by strieste          #+#    #+#             */
/*   Updated: 2025/10/08 08:07:44 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p_str;
	size_t	count;

	if (!s || !*f)
		return ((void *)0);
	count = ft_strlen(s);
	p_str = malloc((count + 1) * sizeof(char));
	if (!p_str)
		return ((void *)0);
	count = 0;
	while (s[count])
	{
		p_str[count] = f(count, s[count]);
		count++;
	}
	p_str[count] = '\0';
	return (p_str);
}
