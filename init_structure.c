/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:50:32 by strieste          #+#    #+#             */
/*   Updated: 2025/11/19 16:33:23 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_structure(t_data *data)
{
	t_pos_map	player;

	if (!init_wall(data))
		return (0);
	if (!init_ground(data))
		return (ft_free_texture(data), 0);
	if (!init_player(data))
		return (ft_free_texture(data), 0);
	if (!init_collectible(data))
		return (ft_free_texture(data), 0);
	if (!init_exit(data))
		return (ft_free_texture(data), 0);
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
	return (1);
}
