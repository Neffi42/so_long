/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:57:07 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/27 15:33:25 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size1;
	size_t	size2;
	char	*new_s;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	new_s = ft_calloc(size1 + size2 + 1, sizeof(char));
	if (!new_s)
		return (NULL);
	ft_strlcat(new_s, s1, size1 + size2 + 1);
	ft_strlcat(new_s, s2, size1 + size2 + 1);
	return (new_s);
}
