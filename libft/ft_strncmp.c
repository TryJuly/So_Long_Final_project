/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:21:50 by strieste          #+#    #+#             */
/*   Updated: 2025/10/01 18:37:36 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	if (n == 0)
		return (0);
	n--;
	count = 0;
	while ((s1[count] || s2[count]) && (s1[count] == s2[count]) && count < n)
		count++;
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
