/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:57:43 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/15 15:08:25 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_img(t_data *data, size_t i, char *path)
{
	data->imgs[i].img = mlx_xpm_file_to_image(data->mlx, path, \
	&data->imgs[i].width, &data->imgs[i].height);
	if (!data->imgs[i].img)
		end_game(error(-1, ERROR_MALLOC, NULL), data);
}

static void	init_level(t_data *data)
{
	init_img(data, FLOOR1, "./textures/floor1.xpm");
	init_img(data, FLOOR2, "./textures/floor2.xpm");
	init_img(data, FLOOR3, "./textures/floor3.xpm");
	init_img(data, FLOOR4, "./textures/floor4.xpm");
	init_img(data, CORNER_LU, "./textures/corner_LU.xpm");
	init_img(data, CORNER_LD, "./textures/corner_LD.xpm");
	init_img(data, CORNER_RU, "./textures/corner_RU.xpm");
	init_img(data, CORNER_RD, "./textures/corner_RD.xpm");
	init_img(data, WALL_U, "./textures/wall_U.xpm");
	init_img(data, WALL_L, "./textures/wall_L.xpm");
	init_img(data, WALL_D, "./textures/wall_D.xpm");
	init_img(data, WALL_R, "./textures/wall_R.xpm");
	init_img(data, TRAP_C, "./textures/trapdoor_closed.xpm");
	init_img(data, TRAP_O, "./textures/trapdoor_open.xpm");
	init_img(data, ROCK1_1, "./textures/rock1_1.xpm");
	init_img(data, ROCK1_2, "./textures/rock1_2.xpm");
	init_img(data, ROCK1_3, "./textures/rock1_3.xpm");
	init_img(data, ROCK1_4, "./textures/rock1_4.xpm");
	init_img(data, ROCK2_1, "./textures/rock2_1.xpm");
	init_img(data, ROCK2_2, "./textures/rock2_2.xpm");
	init_img(data, ROCK2_3, "./textures/rock2_3.xpm");
	init_img(data, ROCK2_4, "./textures/rock2_4.xpm");
	init_img(data, PENNY, "./textures/penny.xpm");
}

static void	init_character(t_data *data)
{
	init_img(data, LOST_TRAP, "./textures/trapdoor_closed_Lost.xpm");
	init_img(data, LOST_D, "./textures/TheLostTest2.xpm");
}

void	init_imgs(t_data *data)
{
	data->imgs = ft_calloc(NBR_IMGS, sizeof(t_img));
	if (!data->imgs)
		end_game(error(-1, ERROR_MALLOC, NULL), data);
	init_level(data);
	init_character(data);
}
