/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:46:54 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/11 21:18:14 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	event_destroy(t_data *data)
{
	end_game(0, data);
	return (0);
}
