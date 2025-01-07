/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:19:21 by sluterea          #+#    #+#             */
/*   Updated: 2024/08/26 19:19:24 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_iterative_factorial(int nb)
{
	int	temp_numb;

	temp_numb = 1;
	while (nb > 0)
	{
		temp_numb *= nb;
		nb--;
	}
	return (temp_numb);
}
/*int	main(void)
{
	printf("%d", ft_iterative_factorial(4));
	return (0);
}*/
