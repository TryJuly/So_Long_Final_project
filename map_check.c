/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 08:49:05 by strieste          #+#    #+#             */
/*   Updated: 2025/11/20 12:58:28 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_case(char **map);

int	is_valid_map(char *av)
{
	char	**map;

	map = map_to_array(av);
	if (!map)
		return (-1);
	if (map[0] == 0)
		return (ft_printf("Empty file\n"), 0);
	if (!number_line(av) || !valid_size(map))
		return (ft_free_map(map), ft_printf("Incorrect map size\n"), 0);
	if (!wall_check(map))
		return (ft_free_map(map), ft_printf("Missing Walls\n"), 0);
	if (!check_exit_player(map))
		return (ft_free_map(map), ft_printf("Missing player or exit\n"), 0);
	if (!valid_case(map))
		return (ft_free_map(map), ft_printf("Incorrect characters\n"), 0);
	if (!check_all_case(av))
		return (ft_free_map(map), 0);
	ft_free_map(map);
	return (1);
}

static int	valid_case(char **map)
{
	size_t	count;
	size_t	len;

	len = 0;
	while (map[len])
	{
		count = 0;
		while (map[len][count])
		{
			if (map[len][count] != '0' && map[len][count] != '1'
				&& map[len][count] != 'C' && map[len][count] != 'E' 
				&& map[len][count] != 'P')
				return (0);
			count++;
		}
		len++;
	}
	return (1);
}

int	number_line(char *av)
{
	size_t	count;
	int		fd;
	char	*str;

	count = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (0);
	str = get_next_line(fd);
	if (!str)
		return (close(fd), -1);
	while (str)
	{
		count++;
		free(str);
		str = get_next_line(fd);
	}
	close (fd);
	return (count);
}

char	**map_to_array(char *av)
{
	int		fd;
	char	*str;
	char	**map;
	ssize_t	count;

	count = number_line(av);
	map = malloc((count + 1) * sizeof(char **));
	if (!map)
		return (NULL);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (0);
	str = get_next_line(fd);
	count = 0;
	while (str)
	{
		map[count] = str;
		count++;
		str = get_next_line(fd);
	}
	close(fd);
	map[count] = 0;
	clean_array(map);
	return (map);
}

int	valid_size(char **map)
{
	size_t	count;
	size_t	check_x;
	size_t	len;

	len = 0;
	check_x = ft_strlen(map[len]);
	while (map[len])
	{
		count = 0;
		while (map[len][count])
			count++;
		if (count != check_x)
			return (0);
		len++;
	}
	if (len == check_x)
		return (0);
	return (1);
}
