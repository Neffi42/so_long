/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:57:43 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/15 11:25:12 by abasdere         ###   ########.fr       */
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
	init_img(data, 0, "./textures/floor1.xpm");
	init_img(data, 1, "./textures/floor2.xpm");
	init_img(data, 2, "./textures/floor3.xpm");
	init_img(data, 3, "./textures/floor4.xpm");
	init_img(data, 4, "./textures/corner_LU.xpm");
	init_img(data, 5, "./textures/corner_LD.xpm");
	init_img(data, 6, "./textures/corner_RU.xpm");
	init_img(data, 7, "./textures/corner_RD.xpm");
	init_img(data, 8, "./textures/wall_U.xpm");
	init_img(data, 9, "./textures/wall_L.xpm");
	init_img(data, 10, "./textures/wall_D.xpm");
	init_img(data, 11, "./textures/wall_R.xpm");
	init_img(data, 12, "./textures/trapdoor_closed.xpm");
	init_img(data, 13, "./textures/trapdoor_open.xpm");
	init_img(data, 14, "./textures/rock1_1.xpm");
	init_img(data, 15, "./textures/rock1_2.xpm");
	init_img(data, 16, "./textures/rock1_3.xpm");
	init_img(data, 17, "./textures/rock1_4.xpm");
	init_img(data, 18, "./textures/rock2_1.xpm");
	init_img(data, 19, "./textures/rock2_2.xpm");
	init_img(data, 20, "./textures/rock2_3.xpm");
	init_img(data, 21, "./textures/rock2_4.xpm");
	init_img(data, 22, "./textures/penny.xpm");
}

static void	init_character(t_data *data)
{
	init_img(data, 23, "./textures/TheLostTest2.xpm");
}

void	init_imgs(t_data *data)
{
	data->imgs = ft_calloc(NBR_IMGS, sizeof(t_img));
	if (!data->imgs)
		end_game(error(-1, ERROR_MALLOC, NULL), data);
	init_level(data);
	init_character(data);
}
