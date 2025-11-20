/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:59:51 by strieste          #+#    #+#             */
/*   Updated: 2025/11/20 12:27:41 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	**map;

	if (ac != 2)
		return (0);
	ac--;
	if (!valid_extension(av[ac]))
		return (ft_printf("Invalid file extension\n"), 0);
	if (!is_valid_map(av[ac]))
		return (0);
	map = map_to_array(av[ac]);
	print_screen(map);
	return (0);
}
