/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort_int_tab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:48:50 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/06 12:45:27 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap(int *tab, int a, int b)
{
	int	temp;

	temp = tab[a];
	tab[a] = tab[b];
	tab[b] = temp;
}

static size_t	partition(int *tab, size_t pivot, size_t high)
{
	size_t	i;
	size_t	j;

	i = pivot;
	j = high;
	while (i < j)
	{
		while (i < high && tab[i] <= tab[pivot])
			i++;
		while (j > pivot && tab[j] > tab[pivot])
			j--;
		if (i < j)
			swap(tab, i, j);
	}
	swap(tab, pivot, j);
	return (j);
}

void	ft_quicksort_int_tab(int *tab, size_t low, size_t high)
{
	size_t	j;

	if (low < high)
	{
		j = partition(tab, low, high);
		ft_quicksort_int_tab(tab, low, j);
		ft_quicksort_int_tab(tab, j + 1, high);
	}
}
