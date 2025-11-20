/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 07:48:27 by strieste          #+#    #+#             */
/*   Updated: 2025/11/12 14:33:49 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_extension(char *argument)
{
	size_t	count;

	count = ft_strlen(argument);
	count--;
	if (argument[count--] != 'r')
		return (0);
	if (argument[count--] != 'e')
		return (0);
	if (argument[count--] != 'b')
		return (0);
	if (argument[count] != '.')
		return (0);
	return (1);
}
