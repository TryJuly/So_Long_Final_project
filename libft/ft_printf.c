/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 09:39:27 by strieste          #+#    #+#             */
/*   Updated: 2025/11/06 10:09:50 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_sort_argument(va_list *argument, char c);

int	ft_printf(const char *str, ...)
{
	size_t	count;
	int		length;
	va_list	argument;

	count = 0;
	length = 0;
	va_start(argument, str);
	while (str[count])
	{
		if (str[count] == '%')
		{
			count++;
			length += ft_sort_argument(&argument, str[count]);
		}
		else
			length += write(1, &str[count], 1);
		count++;
	}
	va_end(argument);
	return (length);
}

static int	ft_sort_argument(va_list(*argument), char c)
{
	int	length;

	length = 0;
	if (c == 's' || c == 'c')
		length += ft_printf_char(argument, c);
	else if (c == 'p')
		length += ft_printf_void(argument);
	else if (c == 'd' || c == 'i' || c == 'u')
		length += ft_printf_number(argument, c);
	else if (c == 'x' || c == 'X')
		length += ft_printf_hexa(argument, c);
	else if (c == '%')
		length += write(1, "%", 1);
	return (length);
}
