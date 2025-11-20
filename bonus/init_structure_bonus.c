/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:50:32 by strieste          #+#    #+#             */
/*   Updated: 2025/11/20 12:05:14 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	help_function(t_data *data);

int	init_structure(t_data *data)
{
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
	help_function(data);
	return (1);
}

static void	help_function(t_data *data)
{
	t_pos_map	player;
	t_pos_map	exit;

	data->count = 1;
	data->collectible = find_collectible(data->map);
	data->map_y = 0;
	data->map_x = 0;
	while (data->map[data->map_y])
		data->map_y++;
	while (data->map[data->map_y - 1][data->map_x])
		data->map_x++;
	player = find_player(data->map);
	data->pos_x = player.x;
	data->pos_y = player.y;
	exit = find_exit(data->map);
	data->exit.x = exit.x;
	data->exit.y = exit.y;
	return ;
}