/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:15:04 by strieste          #+#    #+#             */
/*   Updated: 2025/11/18 13:10:35 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_data *data, int y, int x)
{
	if (data->map[y][x] == '1')
		return (0);
	else if (data->map[y][x] == 'C')
	{
		data->collectible--;
		data->map[y][x] = '0';
	}
	print_ground(data, data->pos_x, data->pos_y);
	print_player(data, x, y);
	data->pos_x = x;
	data->pos_y = y;
	ft_printf("%d\n", data->count++);
	return (1);
}

int	move_down(t_data *data, int y, int x)
{
	if (data->map[y][x] == '1')
		return (0);
	else if (data->map[y][x] == 'C')
	{
		data->collectible--;
		data->map[y][x] = '0';
	}
	print_ground(data, data->pos_x, data->pos_y);
	print_player(data, x, y);
	data->pos_x = x;
	data->pos_y = y;
	ft_printf("%d\n", data->count++);
	return (1);
}

int	move_right(t_data *data, int y, int x)
{
	if (data->map[y][x] == '1')
		return (0);
	else if (data->map[y][x] == 'C')
	{
		data->collectible--;
		data->map[y][x] = '0';
	}
	print_ground(data, data->pos_x, data->pos_y);
	print_player(data, x, y);
	data->pos_x = x;
	data->pos_y = y;
	ft_printf("%d\n", data->count++);
	return (1);
}

int	move_left(t_data *data, int y, int x)
{
	if (data->map[y][x] == '1')
		return (0);
	else if (data->map[y][x] == 'C')
	{
		data->collectible--;
		data->map[y][x] = '0';
	}
	print_ground(data, data->pos_x, data->pos_y);
	print_player(data, x, y);
	data->pos_x = x;
	data->pos_y = y;
	ft_printf("%d\n", data->count++);
	return (1);
}
