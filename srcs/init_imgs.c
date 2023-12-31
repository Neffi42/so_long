/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:57:43 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/19 14:47:54 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static void	init_counter(t_data *data)
{
	init_img(data, MOVE, "./textures/move.xpm");
	init_img(data, SEMI_COL, "./textures/:.xpm");
	init_img(data, DIGIT_0, "./textures/0.xpm");
	init_img(data, DIGIT_1, "./textures/1.xpm");
	init_img(data, DIGIT_2, "./textures/2.xpm");
	init_img(data, DIGIT_3, "./textures/3.xpm");
	init_img(data, DIGIT_4, "./textures/4.xpm");
	init_img(data, DIGIT_5, "./textures/5.xpm");
	init_img(data, DIGIT_6, "./textures/6.xpm");
	init_img(data, DIGIT_7, "./textures/7.xpm");
	init_img(data, DIGIT_8, "./textures/8.xpm");
	init_img(data, DIGIT_9, "./textures/9.xpm");
}

static void	init_character(t_data *data)
{
	init_img(data, LOST_ITEM, "./textures/TheLostItem.xpm");
	init_img(data, LOST_FD, "./textures/TheLostFloorD.xpm");
	init_img(data, LOST_FL, "./textures/TheLostFloorL.xpm");
	init_img(data, LOST_FU, "./textures/TheLostFloorU.xpm");
	init_img(data, LOST_FR, "./textures/TheLostFloorR.xpm");
	init_img(data, LOST_TD, "./textures/TheLostTrapD.xpm");
	init_img(data, LOST_TL, "./textures/TheLostTrapL.xpm");
	init_img(data, LOST_TU, "./textures/TheLostTrapU.xpm");
	init_img(data, LOST_TR, "./textures/TheLostTrapR.xpm");
}

static void	init_bonus(t_data *data)
{
	init_img(data, GOBLIN_L, "./textures/GoblinL.xpm");
	init_img(data, GOBLIN_R, "./textures/GoblinR.xpm");
	init_img(data, GOBLIN_DL, "./textures/GoblinDL.xpm");
	init_img(data, GOBLIN_DR, "./textures/GoblinDR.xpm");
	init_img(data, GOBLIN_B1, "./textures/GoblinB1.xpm");
	init_img(data, GOBLIN_B2, "./textures/GoblinB2.xpm");
	init_img(data, GOBLIN_B3, "./textures/GoblinB3.xpm");
	init_img(data, GOBLIN_B4, "./textures/GoblinB4.xpm");
	init_img(data, GOBLIN_B5, "./textures/GoblinB5.xpm");
	init_img(data, GOBLIN_B6, "./textures/GoblinB6.xpm");
	init_img(data, GOBLIN_B7, "./textures/GoblinB7.xpm");
	init_img(data, LOST_JUMP, "./textures/TheLostJump.xpm");
	init_img(data, LOST_D, "./textures/TheLostDeath.xpm");
}

void	init_imgs(t_data *data)
{
	if (data->bonus)
		data->imgs = ft_calloc(NBR_IMGS + BONUS_IMGS, sizeof(t_img));
	else
		data->imgs = ft_calloc(NBR_IMGS, sizeof(t_img));
	if (!data->imgs)
		end_game(error(-1, ERROR_MALLOC, NULL), data);
	init_level(data);
	init_counter(data);
	init_character(data);
	if (data->bonus)
		init_bonus(data);
}
