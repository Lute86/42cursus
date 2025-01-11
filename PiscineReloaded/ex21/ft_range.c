/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:45:16 by sluterea          #+#    #+#             */
/*   Updated: 2024/12/17 15:45:25 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	len;
	int	i;

	if (min >= max)
		return (NULL);
	len = max - min;
	arr = (int *)malloc(len * sizeof(int));
	i = -1;
	while (++i < len)
		arr[i] = min + i;
	return (arr);
}
/*
int	main()
{
	ft_range(1, 4);
	ft_range(1, 0);
	ft_range(1, 1);
	return (0);
}*/
