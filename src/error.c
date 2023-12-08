/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:22:00 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/08 15:32:57 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(char *message, const char *file)
{
	if (file)
		ft_dprintf(1, "Error\n%s%s\n", file, message);
	else
		ft_dprintf(1, "Error\n%s\n", message);
	return (-1);
}
