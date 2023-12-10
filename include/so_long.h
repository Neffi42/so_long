/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:31:15 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/10 19:33:47 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/include/libft.h"
# include "../lib/minilibx/mlx.h"

# define ERROR_NBR_ARG "Usage: ./so_long <map_file.ber> ..."
# define ERROR_INVALID_MAP "is invalid, please try again with another one"
# define ERROR_INVALID_SUFFIX "is invalid, please provide a <map_file.ber>"
# define ERROR_INVALID_SHAPE "is invalid, it must be a rectangle"
# define ERROR_NBR_PLAYER "is invalid, it must contain one starting position"
# define ERROR_NBR_EXIT "is invalid, it must contain one exit"
# define ERROR_NBR_COINS "is invalid, it must contain at least one collectible"
# define ERROR_INVALID_WALLS "is invalid, it must be surrounded by walls"
# define ERROR_INVALID_PATH "is invalid, there is no valid path in the map"
# define ERROR_MALLOC "Malloc failed"

typedef struct s_pos
{
	float	x;
	float	y;
}	t_pos;

typedef struct s_map
{
	size_t	nbr_coins;
	t_pos	*coins;
	size_t	nbr_exit;
	t_pos	exit;
	size_t	nbr_player;
	t_pos	player;
	size_t	height;
	size_t	width;
	int		is_rectangle;
	char	**map;
}	t_map;

typedef struct s_fmap{
	size_t	nbr_coins;
	size_t	nbr_exit;
	size_t	nbr_player;
	char	**map;
}	t_fmap;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

int		error(char *message, const char *file);
void	end_game(int status, t_map *maps, t_mlx *mlx);
void	free_maps(t_map *maps);
t_map	*check_maps(size_t ac, const char **av);
void	check_map(t_map *maps, size_t i, const char *map_file);
int		flood_map(t_map *map);
int		init_pos(t_pos *pos, float x, float y);
void	init_map(t_map *map);
int		init_mlx(t_mlx *mlx, t_map *maps);

#endif
