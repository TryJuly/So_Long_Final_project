/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:32:47 by strieste          #+#    #+#             */
/*   Updated: 2025/11/20 12:59:29 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free_map(char **map)
{
	size_t	count;

	count = 0;
	while (map[count])
		free(map[count++]);
	free(map);
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
	ft_free_map(data->map);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	ft_free_struct(data);
	// mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(1);
	return (0);
}

void	clean_array(char **map)
{
	size_t	len;
	size_t	count;

	len = 0;
	while (map[len])
	{
		count = 0;
		while (map[len][count] != '\n' && map[len][count])
			count++;
		if (map[len][count] == '\n')
			map[len][count] = 0;
		len++;
	}
}
