/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:09:04 by sluterea          #+#    #+#             */
/*   Updated: 2024/08/08 19:40:50 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 

void	ft_print_numbers(void)
{
	char	digitos;

	digitos = '0';
	while (digitos <= '9')
	{
		write(1, &digitos, 1);
		digitos++;
	}
}
