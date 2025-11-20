/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 07:47:30 by strieste          #+#    #+#             */
/*   Updated: 2025/10/02 07:47:34 by strieste         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				count;
	unsigned const char	*p_s1;
	unsigned const char	*p_s2;

	if (n == 0)
		return (0);
	count = 0;
	p_s1 = s1;
	p_s2 = s2;
	while (count < (n - 1) && (p_s1[count] == p_s2[count]) && p_s1 && p_s2)
		count++;
	return (p_s1[count] - p_s2[count]);
}
