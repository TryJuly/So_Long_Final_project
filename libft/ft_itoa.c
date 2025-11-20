/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 08:30:36 by strieste          #+#    #+#             */
/*   Updated: 2025/10/08 08:01:57 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_int_len(long n)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*ft_positive(char *p_itoa, size_t count, int n)
{
	p_itoa[count] = '\0';
	if (n == 0)
		p_itoa[0] = '0';
	else
	{
		count--;
		while (n > 0)
		{
			p_itoa[count] = (n % 10) + 48;
			n /= 10;
			count--;
		}
	}
	return (p_itoa);
}

static char	*ft_negative(char *p_itoa, size_t count, int n)
{
	p_itoa[count + 1] = '\0';
	while (n > 0)
	{
		p_itoa[count] = (n % 10) + 48;
		n /= 10;
		count--;
	}
	p_itoa[count] = '-';
	return (p_itoa);
}

char	*ft_itoa(int n)
{
	char	*p_itoa;
	size_t	count;
	size_t	sign;

	count = 0;
	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign++;
		n = -n;
	}
	count = ft_int_len(n);
	p_itoa = malloc(((count + sign) + 1) * sizeof(char));
	if (!p_itoa)
		return ((void *)0);
	if (sign)
		p_itoa = ft_negative(p_itoa, count, n);
	else
		p_itoa = ft_positive(p_itoa, count, n);
	return (p_itoa);
}
