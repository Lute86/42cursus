/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <sluterea@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:29:11 by sluterea          #+#    #+#             */
/*   Updated: 2025/01/07 14:29:11 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	ft_numlen_unsigned(unsigned int num, int len)
{
	if (num == 0)
		return (1);
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static int	ft_putnbr_unsigned(unsigned int n)
{
	int				i;
	unsigned int	num;

	i = 0;
	num = n;
	i = ft_numlen_unsigned(num, i);
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
	return (i);
}

int	print_uint(unsigned int arg)
{
	return (ft_putnbr_unsigned(arg));
}
