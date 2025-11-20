/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 08:30:55 by strieste          #+#    #+#             */
/*   Updated: 2025/11/08 10:00:16 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **array);

static size_t	ft_count_word(char const *s, char c)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			res++;
		while (s[i] != c && s[i])
			i++;
	}
	return (res);
}

static size_t	ft_word(char const *s, char const c)
{
	size_t	count;

	count = 0;
	while (s[count] && s[count] != c)
		count++;
	return (count);
}

char	**ft_split(char const *s, char const c)
{
	char	**p_split;
	size_t	count;
	size_t	i;

	if (!s)
		return ((void *)0);
	p_split = malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (!p_split)
		return ((void *)0);
	count = 0;
	i = 0;
	while (s[count])
	{
		while (s[count] == c)
			count++;
		if (s[count])
		{
			p_split[i++] = ft_substr(s, count, ft_word(&s[count], c));
			if (!p_split[i - 1])
				return (ft_free(p_split));
			count += ft_word(&s[count], c);
		}
	}
	p_split[i] = ((void *)0);
	return (p_split);
}

static char	**ft_free(char **array)
{
	size_t	count;

	count = 0;
	while (array[count])
	{
		free(array[count]);
		count++;
	}
	return (NULL);
}
