/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 09:10:02 by strieste          #+#    #+#             */
/*   Updated: 2025/11/06 10:15:05 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_putnbr_base(unsigned int nb, char *base);
static size_t	strlen(const char *s);
static size_t	putchar_fd(char c, int fd);

int	ft_printf_hexa(va_list *arg, char c)
{
	size_t			count;
	char			*base;
	unsigned int	nbr;

	count = 0;
	base = NULL;
	nbr = (unsigned int) va_arg(*arg, int);
	if (c == 'x')
	{
		base = "0123456789abcdef\0";
		count = ft_putnbr_base(nbr, base);
	}
	else if (c == 'X')
	{
		base = "0123456789ABCEDF\0";
		count = ft_putnbr_base(nbr, base);
	}
	return (count);
}

static size_t	ft_putnbr_base(unsigned int nb, char *base)
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
