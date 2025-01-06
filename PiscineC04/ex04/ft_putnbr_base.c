/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:34:09 by sluterea          #+#    #+#             */
/*   Updated: 2024/08/21 11:34:28 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	conditions(int count, int i, int j, char *base)
{
	if (count <= 1)
		return (1);
	while (i < count)
	{
		while (j < count)
		{
			if (i != j && base[i] == base[j])
				return (1);
			j++;
		}
		j = i + 1;
		i++;
	}
	return (0);
}

void	show_nbr(int nbr, char *base, int count)
{
	unsigned int	num;

	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		num = (unsigned int)(-1 * (nbr + 1)) + 1;
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		num = -nbr;
	}
	else
		num = nbr;
	if (num >= (unsigned int)count)
		show_nbr(num / count, base, count);
	write(1, &base[num % count], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				count;
	int				repeated;
	int				i;
	int				j;

	count = 0;
	repeated = 0;
	i = 0;
	j = 1;
	while (base[count] != '\0')
	{
		if (base[count] == '+' || base[count] == '-')
			return ;
		count++;
	}
	repeated = conditions(count, i, j, base);
	if (repeated)
		return ;
	show_nbr(nbr, base, count);
}
/*
int	main(void)
{
	ft_putnbr_base(-2147483648, "0123456789ABCDEF");
	write(1, "\n", 1);
	ft_putnbr_base(-2147483648, "0123456789");
	write(1, "\n", 1);
	ft_putnbr_base(5, "01");
	write(1, "\n", 1);
	return (0);
}*/
