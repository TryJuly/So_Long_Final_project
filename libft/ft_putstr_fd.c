/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:43:14 by strieste          #+#    #+#             */
/*   Updated: 2025/10/01 20:51:04 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	count;
	int		check;

	count = 0;
	check = 0;
	while (s[count])
	{
		check = write(fd, &s[count], 1);
		if (check == -1)
			return ;
		count++;
	}
}
