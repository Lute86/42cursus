/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:19:21 by sluterea          #+#    #+#             */
/*   Updated: 2024/08/26 19:27:35 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_recursive_factorial(int nb)
{
	if (nb == 0 || nb == 1)
	{
		return (1);
	}
	else
		return (nb * ft_recursive_factorial(nb - 1));
}

/*int	main(void)
{
	printf("%d", ft_recursive_factorial(4));
	return (0);
}*/
