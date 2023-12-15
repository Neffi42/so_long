/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keypress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:47:19 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/15 10:57:36 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	event_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		end_game(0, data);
	if (keysym == XK_o)
		put_image(data, 13, data->maps[data->i].exit.x, \
		data->maps[data->i].exit.y);
	if (keysym == XK_c)
		put_image(data, 12, data->maps[data->i].exit.x, \
		data->maps[data->i].exit.y);
	return (0);
}
