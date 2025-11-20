/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:40:52 by strieste          #+#    #+#             */
/*   Updated: 2025/11/20 11:21:42 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_pos_map	find_player(char **map)
{
	t_pos_map	player;
	int			x;
	int			y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				player.y = y;
				player.x = x;
				return (player);
			}
			x++;
		}
		y++;
	}
	player.y = -1;
	player.x = -1;
	return (player);
}

t_pos_map	find_exit(char **map)
{
	t_pos_map	exit;
	int			x;
	int			y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
			{
				exit.y = y;
				exit.x = x;
				return (exit);
			}
			x++;
		}
		y++;
	}
	exit.y = -1;
	exit.x = -1;
	return (exit);
}

int	find_collectible(char **map)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

t_pos_map	find_enemy(char **map)
{
	t_pos_map	enemy;
	int			x;
	int			y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'e')
			{
				enemy.y = y;
				enemy.x = x;
				return (enemy);
			}
			x++;
		}
		y++;
	}
	enemy.y = -1;
	enemy.x = -1;
	return (enemy);
}
