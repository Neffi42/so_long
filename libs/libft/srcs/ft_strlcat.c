/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 21:08:08 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/29 19:27:19 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_src;
	size_t	size_dst;
	size_t	i;

	i = 0;
	if (!dst && !size)
		return (FALSE);
	size_src = ft_strlen(src);
	size_dst = ft_strlen(dst);
	if (size < size_dst)
		return (size_src + size);
	while (i + size_dst + 1 < size && src[i])
	{
		dst[size_dst + i] = src[i];
		i++;
	}
	if (size)
		dst[size_dst + i] = '\0';
	return (size_dst + size_src);
}
