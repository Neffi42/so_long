/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:12:34 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/16 12:15:32 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(ssize_t	nbr)
{
	size_t	count;

	count = 1;
	while (nbr / 10)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}
