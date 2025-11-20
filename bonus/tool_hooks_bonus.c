/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_hooks_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:15:04 by strieste          #+#    #+#             */
/*   Updated: 2025/11/20 12:21:28 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	print_count_screen(t_data *data);

int	move_up(t_data *data, int y, int x)
{
	if (data->map[y][x] == '1')
		return (0);
	if (data->map[y][x] == 'e')
	{
		ft_printf("Game over, Enemy hit you\n");
		close_window(data);
		exit(0);
	}
	else if (data->map[y][x] == 'C')
	{
		data->collectible--;
		data->map[y][x] = '0';
	}
	print_ground(data, data->pos_x, data->pos_y);
	print_player_enemy(data, x, y, 'P');
	data->pos_x = x;
	data->pos_y = y;
	print_count_screen(data);
	ft_printf("%d\n", data->count++);
	return (1);
}

int	move_down(t_data *data, int y, int x)
{
	if (data->map[y][x] == '1')
		return (0);
	if (data->map[y][x] == 'e')
	{
		ft_printf("Game over, Enemy hit you\n");
		close_window(data);
		exit(0);
	}
	else if (data->map[y][x] == 'C')
	{
		data->collectible--;
		data->map[y][x] = '0';
	}
	print_ground(data, data->pos_x, data->pos_y);
	print_player_enemy(data, x, y, 'P');
	data->pos_x = x;
	data->pos_y = y;
	print_count_screen(data);
	ft_printf("%d\n", data->count++);
	return (1);
}

int	move_right(t_data *data, int y, int x)
{
	if (data->map[y][x] == '1')
		return (0);
	if (data->map[y][x] == 'e')
	{
		ft_printf("Game over, Enemy hit you\n");
		close_window(data);
		exit(0);
	}
	else if (data->map[y][x] == 'C')
	{
		data->collectible--;
		data->map[y][x] = '0';
	}
	print_ground(data, data->pos_x, data->pos_y);
	print_player_enemy(data, x, y, 'P');
	data->pos_x = x;
	data->pos_y = y;
	print_count_screen(data);
	ft_printf("%d\n", data->count++);
	return (1);
}

int	move_left(t_data *data, int y, int x)
{
	if (data->map[y][x] == '1')
		return (0);
	if (data->map[y][x] == 'e')
	{
		ft_printf("Game over, Enemy hit you\n");
		close_window(data);
		exit(0);
	}
	else if (data->map[y][x] == 'C')
	{
		data->collectible--;
		data->map[y][x] = '0';
	}
	print_ground(data, data->pos_x, data->pos_y);
	print_player_enemy(data, x, y, 'P');
	data->pos_x = x;
	data->pos_y = y;
	print_count_screen(data);
	ft_printf("%d\n", data->count++);
	return (1);
}

static void	print_count_screen(t_data *data)
{
	char	*count_m;

	count_m = ft_itoa(data->count);
	print_wall(data, 0, 0);
	mlx_string_put(data->mlx_ptr, data->mlx_win, 32, 32, 0x00FF00, count_m);
	free(count_m);
}
