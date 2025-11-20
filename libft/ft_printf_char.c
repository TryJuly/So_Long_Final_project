/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 09:15:38 by strieste          #+#    #+#             */
/*   Updated: 2025/11/06 10:11:45 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	putstr_fd(char *s, int fd);
static size_t	putchar_fd(char c, int fd);

int	ft_printf_char(va_list *arg, char c)
{
	char	*str;
	int		character;
	size_t	count;

	count = 0;
	if (c == 's')
	{
		str = (char *) va_arg(*arg, const char *);
		if (!str)
		{
			write(1, "(null)", 6);
			return (6);
		}
		count = putstr_fd(str, 1);
	}
	else if (c == 'c')
	{
		character = (unsigned char) va_arg(*arg, int);
		count = putchar_fd(character, 1);
	}
	return (count);
}

static size_t	putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

static size_t	putstr_fd(char *s, int fd)
{
	size_t	count;

	count = 0;
	while (s[count])
	{
		write(fd, &s[count], 1);
		count++;
	}
	return (count);
}
