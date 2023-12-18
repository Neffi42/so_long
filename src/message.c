/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:24:08 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/18 10:24:11 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	message(char *message)
{
	ft_dprintf(1, "%s\n", message);
	return (0);
}

int	error(int status, char *message, const char *file)
{
	if (file)
		ft_dprintf(2, "Error\n%s %s\n", file, message);
	else
		ft_dprintf(2, "Error\n%s\n", message);
	return (status);
}
