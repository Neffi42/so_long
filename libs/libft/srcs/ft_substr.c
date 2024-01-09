/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:38:44 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/27 15:33:25 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size_s;
	char	*sub;

	if (!s)
		return (NULL);
	i = 0;
	size_s = ft_strlen(s);
	if (size_s < start)
	{
		sub = ft_calloc(1, sizeof(char));
		return (sub);
	}
	if (len > size_s - start)
		len = size_s - start;
	sub = ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len && i < size_s)
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}
