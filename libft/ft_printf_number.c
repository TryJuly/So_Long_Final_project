/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 09:01:14 by strieste          #+#    #+#             */
/*   Updated: 2025/11/10 09:37:22 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	putnbr_fd(int n, int fd);
static size_t	ft_putnbr_unsigned_fd(unsigned int n, int fd);
static size_t	putchar_fd(char c, int fd);

int	ft_printf_number(va_list(*arg), char c)
{
	size_t			count;
	int				nb;
	unsigned int	nbr;

	count = 0;
	if (c == 'i' || c == 'd')
	{
		nb = 0;
		nb = (int) va_arg(*arg, int);
		count = putnbr_fd(nb, 1);
	}
	else if (c == 'u')
	{
		nbr = 0;
		nbr = (unsigned int) va_arg(*arg, unsigned int);
		count = ft_putnbr_unsigned_fd(nbr, 1);
	}
	return (count);
}

static size_t	putnbr_fd(int n, int fd)
{
	size_t	count;

	count = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		count++;
	}
	if (n >= 0 && n <= 9)
		count += putchar_fd(n + '0', fd);
	else
	{
		count += putnbr_fd(n / 10, fd);
		count += putnbr_fd(n % 10, fd);
	}
	return (count);
}

static size_t	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	size_t	count;

	count = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else if (n >= 1 && n <= 9)
		count += putchar_fd(n + '0', fd);
	else
	{
		count += putnbr_fd(n / 10, fd);
		count += putnbr_fd(n % 10, fd);
	}
	return (count);
}

static size_t	putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
