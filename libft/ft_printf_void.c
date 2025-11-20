/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_void.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 09:18:25 by strieste          #+#    #+#             */
/*   Updated: 2025/11/06 10:14:00 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strlen(const char *s);
static size_t	putchar_fd(char c, int fd);
static size_t	ft_putnbr_base(uintptr_t nb, char *base);

int	ft_printf_void(va_list(*arg))
{
	uintptr_t	adress;
	size_t		count;
	char		*base;

	count = 0;
	base = "0123456789abcdef";
	adress = va_arg(*arg, uintptr_t);
	if (!adress)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	count += 2;
	count += ft_putnbr_base(adress, base);
	return (count);
}

static size_t	ft_putnbr_base(uintptr_t nb, char *base)
{
	size_t	length_base;
	size_t	count;

	count = 0;
	length_base = strlen(base);
	if (nb >= (unsigned char)length_base)
	{
		count += ft_putnbr_base((nb / length_base), base);
	}
	count += putchar_fd(base[nb % length_base], 1);
	return (count);
}

static size_t	strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static size_t	putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
