/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:50:19 by sluterea          #+#    #+#             */
/*   Updated: 2024/08/20 16:50:22 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	menys;
	int	resultat;

	i = 0;
	menys = 0;
	resultat = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			menys++;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat = resultat * 10 + str[i] - '0';
		i++;
	}
	if (menys % 2 == 1)
		resultat = -resultat;
	return (resultat);
}
/*#include <stdio.h>
int main() {
    char c[] = " --+--+er1234";
    int num = ft_atoi(c);
    printf("El numero es : %d\n", num);
    return 0;
}*/
