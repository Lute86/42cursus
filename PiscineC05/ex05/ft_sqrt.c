/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:25:59 by sluterea          #+#    #+#             */
/*   Updated: 2024/08/28 20:26:02 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	low;
	int	high;
	int	mid;
	int	mid_squared;

	low = 0;
	high = nb;
	if (nb < 0)
		return (0);
	while (low <= high)
	{
		mid = (low + high) / 2;
		mid_squared = mid * mid;
		if (mid_squared == nb)
			return (mid);
		else if (mid_squared < nb)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (0);
}

/*int	main()
{
	int	i;

	i = ft_sqrt(9);
	printf("%d", i);
	return 0;
}*/
