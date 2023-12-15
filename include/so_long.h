/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:31:15 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/15 16:46:07 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

# define ERROR_NBR_ARG "Usage: ./so_long <map_file.ber> ..."
# define ERROR_WRONG_CHAR "is invalid, it contains unauthorized characters"
# define ERROR_INVALID_MAP "is invalid, please try again with another one"
# define ERROR_INVALID_SUFFIX "is invalid, please provide a <map_file.ber>"
# define ERROR_INVALID_SHAPE "is invalid, it must be a rectangle"
# define ERROR_NBR_PLAYER "is invalid, it must contain one starting position"
# define ERROR_NBR_EXIT "is invalid, it must contain one exit"
# define ERROR_NBR_COINS "is invalid, it must contain at least one collectible"
# define ERROR_INVALID_WALLS "is invalid, it must be surrounded by walls"
# define ERROR_INVALID_PATH "is invalid, there is no valid path in the map"
# define ERROR_MAP_TOO_BIG "is invalid, the map is to big"
# define ERROR_MALLOC "Malloc failed"

# define MAX_WIDTH 1920
# define MAX_HEIGHT 1080
# define NBR_IMGS 29
# define TILE_LEN 40

# define FLOOR1 0
# define FLOOR2 1
# define FLOOR3 2
# define FLOOR4 3
# define CORNER_LU 4
# define CORNER_LD 5
# define CORNER_RU 6
# define CORNER_RD 7
# define WALL_U 8
# define WALL_L 9
# define WALL_D 10
# define WALL_R 11
# define TRAP_C 12
# define TRAP_O 13
# define ROCK1_1 14
# define ROCK1_2 15
# define ROCK1_3 16
# define ROCK1_4 17
# define ROCK2_1 18
# define ROCK2_2 19
# define ROCK2_3 20
# define ROCK2_4 21
# define PENNY 22
# define LOST_ITEM 23
# define LOST_TRAP 24
# define LOST_JUMP1_1 25
# define LOST_JUMP1_2 26
# define LOST_JUMP2_1 27
# define LOST_D 28


typedef struct s_pos
{
	size_t	x;
	size_t	y;
}	t_pos;

typedef struct s_map
{
	size_t		nbr_coins;
	size_t		nbr_exit;
	t_pos		exit;
	size_t		nbr_player;
	t_pos		player;
	size_t		height;
	size_t		width;
	int			is_rectangle;
	char		**map;
	const char	*map_file;
}	t_map;

typedef struct s_fmap
{
	size_t	nbr_coins;
	size_t	nbr_exit;
	size_t	nbr_player;
	char	**map;
}	t_fmap;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_map	*maps;
	t_img	*imgs;
	size_t	i;
	size_t	len;
}	t_data;

typedef struct s_vec
{
	int	x;
	int	y;
}	t_vec;

int		error(int status, char *message, const char *file);
void	end_game(int status, t_data *data);
void	free_maps(t_map *maps);
void	destroy_mlx(t_data *data);
void	check_maps(size_t ac, const char **av, t_data *data);
void	check_map(t_data *data, size_t i, const char *map_file);
void	find_all_chars(t_data *data, t_map *map, char *l, size_t len);
int		flood_map(t_map *map);
int		init_pos(t_pos *pos, size_t x, size_t y);
void	init_map(t_map *map, const char *map_file);
void	init_mlx(t_data *data);
void	init_imgs(t_data *data);
void	init_data(t_data *data, size_t len);
int		event_keypress(int keysym, t_data *data);
int		event_destroy(t_data *data);
t_vec	translation(int x, int y, int dest_x, int dest_y);
void	put_image(t_data *data, size_t i, size_t x, size_t y);
void	render_level(t_data *data);
void	render_tile(t_data *data, size_t x, size_t y);
void	render_character(t_data *data);
void	move_character(t_data *data, t_pos pos, size_t x, size_t y);
void	start_game(t_data *data);
void	next_map(t_data *data);

#endif
