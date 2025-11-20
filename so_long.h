/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:48:44 by strieste          #+#    #+#             */
/*   Updated: 2025/11/20 12:41:31 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
// # include <X11/keysym.h>

# define WIDTH 64
# define HEIGHT 64

typedef struct s_pos_map
{
	int	x;
	int	y;
}		t_pos_map;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*p_wall;
	void		*p_ground;
	void		*p_player;
	void		*p_collectible;
	void		*p_exit;
	char		**map;
	int			map_y;
	int			map_x;
	int			pos_y;
	int			pos_x;
	int			count;
	int			collectible;
	t_pos_map	exit;
	t_pos_map	player;
}			t_data;

/*			Check Map / Input		*/

char		**map_to_array(char *av);
int			is_valid_map(char *av);
int			number_line(char *av);
int			valid_size(char **map);
int			wall_check(char **map);
int			check_all_case(char *av);
int			check_exit_player(char **map);
int			valid_extension(char *argument);

/*			Tool_Player				*/

t_pos_map	find_player(char **map);
t_pos_map	find_exit(char **map);
int			find_collectible(char **map);

/*			Tool_Mlx / Move			*/

int			key_handler(int keycode, t_data *env);
int			print_map(t_data *data, char **map);
int			move_up(t_data *data, int y, int x);
int			move_down(t_data *data, int y, int x);
int			move_right(t_data *data, int x, int y);
int			move_left(t_data *data, int x, int y);

/*			Free/Clean				*/

void		ft_free_map(char **map);
void		ft_free_texture(t_data *data);
void		ft_free_struct(t_data *data);
int			close_window(t_data *data);
void		clean_array(char **map);

/*			Print_Image				*/

void		print_screen(char **map);
int			print_wall(t_data *data, int y, int x);
int			print_ground(t_data *data, int y, int x);
int			print_collectible(t_data *data, int y, int x);
int			print_player(t_data *data, int y, int x);
int			print_exit(t_data *data, int y, int x);

/*			Init					*/

int			init_exit(t_data *data);
int			init_collectible(t_data *data);
int			init_player(t_data *data);
int			init_ground(t_data *data);
int			init_wall(t_data *data);
int			init_structure(t_data *data);

#endif