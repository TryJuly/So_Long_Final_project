/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:50:32 by strieste          #+#    #+#             */
/*   Updated: 2025/11/20 12:04:02 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free_texture(t_data *data);

int	init_texture(t_data *data)
{
	data->count = 1;
	if (!init_wall(data))
		return (0);
	if (!init_ground(data))
		return (ft_free_texture(data), 0);
	if (!init_player_enemy(data))
		return (ft_free_texture(data), 0);
	if (!init_collectible(data))
		return (ft_free_texture(data), 0);
	if (!init_exit(data))
		return (ft_free_texture(data), 0);
	return (1);
}

void	ft_free_texture(t_data *data)
{
	if (data->p_wall)
		free(data->p_wall);
	if (data->p_ground)
		free(data->p_ground);
	if (data->p_collectible)
		free(data->p_collectible);
	if (data->p_player)
		free(data->p_player);
	if (data->p_exit)
		free(data->p_exit);
	if (data->p_enemy)
		free(data->p_enemy);
}

void	ft_free_struct(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->p_wall);
	mlx_destroy_image(data->mlx_ptr, data->p_ground);
	mlx_destroy_image(data->mlx_ptr, data->p_player);
	mlx_destroy_image(data->mlx_ptr, data->p_collectible);
	mlx_destroy_image(data->mlx_ptr, data->p_exit);
	mlx_destroy_image(data->mlx_ptr, data->p_enemy);
	// ft_free_texture(data);
	// free(data->mlx_ptr);
	// free(data->mlx_win);
	ft_free_map(data->map);
}
