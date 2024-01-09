/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:41:39 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/27 15:33:25 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;

	if (!dest && !src)
		return (NULL);
	i = -1;
	while (++i < n)
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
	return (dest);
}
