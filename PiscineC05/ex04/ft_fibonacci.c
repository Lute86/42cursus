/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:06:18 by sluterea          #+#    #+#             */
/*   Updated: 2024/08/27 18:06:20 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

/*
int	ft_fibonacci(int index)
{
	int	i;
	int	temp;
	int	temp2;
	int	swap;

	temp2 = 2;
	temp = 1;
	i = 2;
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1 || index == 2)
		return (1);
	if (index > 3)
	{
		while (++i < index)
		{
			swap = temp2;
			temp2 += temp;
			temp = swap;
		}
	}
	return (temp2);
}

int	main(int argc, char **argv)
{
	int	result;

	if (argc == 2)
	{
		result = ft_fibonacci(atoi(argv[1]));
		printf("%d", result);
		return (1);
	}
	return (0);
}*/
