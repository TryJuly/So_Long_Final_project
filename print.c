/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:27:46 by strieste          #+#    #+#             */
/*   Updated: 2025/11/19 17:02:08 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_screen(char **map)
{
	t_data		data;
	int			width;
	int			height;

	data.map = map;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
	{
		ft_printf("Error mlx init\n");
		return ;
	}
	init_structure(&data);
	width = data.map_x * WIDTH;
	height = data.map_y * HEIGHT;
	data.mlx_win = mlx_new_window(data.mlx_ptr, width, height, "So_Long");
	if (!data.mlx_win)
	{
		free(data.mlx_ptr);
		ft_printf("Error new window\n");
		return ;
	}
	print_map(&data, map);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_handler, &data);
	mlx_hook(data.mlx_win, 17, 1L << 0, close_window, &data);
	mlx_loop(data.mlx_ptr);
}

int	print_map(t_data *data, char **map)
{
	t_pos_map	pos;

	pos.y = 0;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (map[pos.y][pos.x] == '1')
				print_wall(data, pos.x, pos.y);
			if (map[pos.y][pos.x] == 'C')
				print_collectible(data, pos.x, pos.y);
			if (map[pos.y][pos.x] == '0')
				print_ground(data, pos.x, pos.y);
			if (map[pos.y][pos.x] == 'P')
				print_player(data, pos.x, pos.y);
			if (map[pos.y][pos.x] == 'E' && data->collectible == 0)
				print_exit(data, pos.x, pos.y);
			if (map[pos.y][pos.x] == 'E' && data->collectible)
				print_ground(data, pos.x, pos.y);
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}
