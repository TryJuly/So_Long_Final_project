/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:18:46 by strieste          #+#    #+#             */
/*   Updated: 2025/11/20 12:01:42 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int			render(t_data *data);
static void	help_function(t_data *data);
static void	help_render_exit(t_data *data, int x, int y);

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
	help_function(&data);
}

static void	help_function(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 1L << 0, key_handler, data);
	mlx_loop_hook(data->mlx_ptr, render, data);
	mlx_hook(data->mlx_win, 17, 1L << 0, close_window, data);
	mlx_loop(data->mlx_ptr);
}

int	render(t_data *data)
{
	if (!data->collectible)
		help_render_exit(data, data->exit.x, data->exit.y);
	return (0);
}

static void	help_render_exit(t_data *data, int x, int y)
{
	void	*mlx;
	void	*win;
	void	*ptr;
	int		size;

	size = 64;
	mlx = data->mlx_ptr;
	win = data->mlx_win;
	ptr = mlx_xpm_file_to_image(mlx, "./textures/portal.xpm", &size, &size);
	mlx_put_image_to_window(mlx, win, ptr, x * WIDTH, y * HEIGHT);
	mlx_destroy_image(data->mlx_ptr, ptr);
	ptr = mlx_xpm_file_to_image(mlx, "./textures/portal_1.xpm", &size, &size);
	mlx_put_image_to_window(mlx, win, ptr, x * WIDTH, y * HEIGHT);
	mlx_destroy_image(data->mlx_ptr, ptr);
	ptr = mlx_xpm_file_to_image(mlx, "./textures/portal_2.xpm", &size, &size);
	mlx_put_image_to_window(mlx, win, ptr, x * WIDTH, y * HEIGHT);
	mlx_destroy_image(data->mlx_ptr, ptr);
	ptr = mlx_xpm_file_to_image(mlx, "./textures/portal_3.xpm", &size, &size);
	mlx_put_image_to_window(mlx, win, ptr, x * WIDTH, y * HEIGHT);
	mlx_destroy_image(data->mlx_ptr, ptr);
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
			if (map[pos.y][pos.x] == 'P' || map[pos.y][pos.x] == 'e')
				print_player_enemy(data, pos.x, pos.y, map[pos.y][pos.x]);
			if (map[pos.y][pos.x] == 'E' && data->collectible)
				print_ground(data, pos.x, pos.y);
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}
