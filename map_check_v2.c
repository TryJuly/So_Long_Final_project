/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_v2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 08:07:25 by strieste          #+#    #+#             */
/*   Updated: 2025/11/20 12:36:48 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_exit_collectible(char **map);
static char	**flood_fill(char **map, int x, int y);

int	check_all_case(char *av)
{
	char		**copy;
	t_pos_map	player;

	copy = map_to_array(av);
	if (!copy)
		return (-1);
	player = find_player(copy);
	copy = flood_fill(copy, player.x, player.y);
	if (!check_exit_collectible(copy))
		return (ft_free_map(copy), 0);
	ft_free_map(copy);
	return (1);
}

static char	**flood_fill(char **map, int x, int y)
{
	t_pos_map	pos;

	pos.x = 0;
	pos.y = 0;
	pos.x = x;
	pos.y = y;
	if (map[pos.y][pos.x] == '1' || map[pos.y][pos.x] == 'V')
		return (map);
	if ((map[pos.y][pos.x] == 'P') || (map[pos.y][pos.x] == 'C')
			|| (map[pos.y][pos.x] == '0') || (map[pos.y][pos.x] == 'E'))
		map[pos.y][pos.x] = 'V';
	map = flood_fill(map, pos.x + 1, pos.y);
	map = flood_fill(map, pos.x, pos.y + 1);
	map = flood_fill(map, pos.x - 1, pos.y);
	map = flood_fill(map, pos.x, pos.y - 1);
	return (map);
}

static int	check_exit_collectible(char **map)
{
	size_t	len;
	size_t	count;

	len = 0;
	while (map[len])
	{
		count = 0;
		while (map[len][count])
		{
			if (map[len][count] == 'E' || map[len][count] == 'C')
			{
				ft_printf("Inaccessible collectible or exit\n");
				return (0);
			}
			count++;
		}
		len++;
	}
	return (1);
}

int	wall_check(char **map)
{
	size_t	count;
	size_t	len;

	count = ft_strlen(map[0]) - 1;
	len = 0;
	while (map[len + 1] != 0)
	{
		if (map[len][0] != '1' || map[len][count] != '1')
			return (0);
		len++;
	}
	count = 0;
	while (map[len][count])
	{
		if (map[0][count] != '1' || map[len][count] != '1')
			return (0);
		count++;
	}
	return (1);
}

int	check_exit_player(char **map)
{
	int		player;
	int		exit;
	size_t	count;
	size_t	len;

	len = 0;
	player = 0;
	exit = 0;
	while (map[len])
	{
		count = 0;
		while (map[len][count])
		{
			if (map[len][count] == 'P')
				player++;
			if (map[len][count] == 'E')
				exit++;
			count++;
		}
		len++;
	}
	if (player != 1 || exit != 1)
		return (0);
	return (1);
}
