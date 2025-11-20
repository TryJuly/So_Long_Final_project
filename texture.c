/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:30:21 by strieste          #+#    #+#             */
/*   Updated: 2025/11/18 13:33:25 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_wall(t_data *data)
{
	void	*ptr;
	void	*mlx;
	int		width;
	int		height;

	mlx = data->mlx_ptr;
	width = 64;
	height = 64;
	ptr = mlx_xpm_file_to_image(mlx, "./textures/stone.xpm", &width, &height);
	data->p_wall = ptr;
	if (!data->p_wall)
		return (0);
	return (1);
}

int	init_ground(t_data *data)
{
	void	*ptr;
	void	*mlx;
	int		width;
	int		height;

	mlx = data->mlx_ptr;
	width = 64;
	height = 64;
	ptr = mlx_xpm_file_to_image(mlx, "./textures/w_sol.xpm", &width, &height);
	data->p_ground = ptr;
	if (!data->p_ground)
		return (0);
	return (1);
}

int	init_player(t_data *data)
{
	void	*ptr;
	void	*mlx;
	int		width;
	int		height;

	mlx = data->mlx_ptr;
	width = 64;
	height = 64;
	ptr = mlx_xpm_file_to_image(mlx, "./textures/Rick.xpm", &width, &height);
	data->p_player = ptr;
	if (!data->p_player)
		return (0);
	return (1);
}

int	init_collectible(t_data *data)
{
	void	*ptr;
	void	*mlx;
	int		width;
	int		height;

	mlx = data->mlx_ptr;
	width = 64;
	height = 64;
	ptr = mlx_xpm_file_to_image(mlx, "./textures/Morty.xpm", &width, &height);
	data->p_collectible = ptr;
	if (!data->p_collectible)
		return (0);
	return (1);
}

int	init_exit(t_data *data)
{
	void	*ptr;
	void	*mlx;
	int		width;
	int		height;

	mlx = data->mlx_ptr;
	width = 64;
	height = 64;
	ptr = mlx_xpm_file_to_image(mlx, "./textures/portal.xpm", &width, &height);
	data->p_exit = ptr;
	if (!data->p_exit)
		return (0);
	return (1);
}
