/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:46:13 by strieste          #+#    #+#             */
/*   Updated: 2025/11/20 11:44:36 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_wall(t_data *data, int x, int y)
{
	void	*mlx;
	void	*win;
	void	*image;

	mlx = data->mlx_ptr;
	win = data->mlx_win;
	image = data->p_wall;
	mlx_put_image_to_window(mlx, win, image, x * WIDTH, y * HEIGHT);
	return (1);
}

int	print_ground(t_data *data, int x, int y)
{
	void	*mlx;
	void	*win;
	void	*image;

	mlx = data->mlx_ptr;
	win = data->mlx_win;
	image = data->p_ground;
	mlx_put_image_to_window(mlx, win, image, x * WIDTH, y * HEIGHT);
	return (1);
}

int	print_collectible(t_data *data, int x, int y)
{
	void	*mlx;
	void	*win;
	void	*image;

	mlx = data->mlx_ptr;
	win = data->mlx_win;
	image = data->p_ground;
	mlx_put_image_to_window(mlx, win, image, x * WIDTH, y * HEIGHT);
	image = data->p_collectible;
	mlx_put_image_to_window(mlx, win, image, x * WIDTH, y * HEIGHT);
	return (1);
}

int	print_player(t_data *data, int x, int y)
{
	void	*mlx;
	void	*win;
	void	*image;

	mlx = data->mlx_ptr;
	win = data->mlx_win;
	image = data->p_ground;
	mlx_put_image_to_window(mlx, win, image, x * WIDTH, y * HEIGHT);
	image = data->p_player;
	mlx_put_image_to_window(mlx, win, image, x * WIDTH, y * HEIGHT);
	return (1);
}

int	print_exit(t_data *data, int x, int y)
{
	void	*mlx;
	void	*win;
	void	*image;

	mlx = data->mlx_ptr;
	win = data->mlx_win;
	image = data->p_exit;
	mlx_put_image_to_window(mlx, win, image, x * WIDTH, y * HEIGHT);
	return (1);
}
