/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:39:07 by sluterea          #+#    #+#             */
/*   Updated: 2024/08/15 13:39:09 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*#include <string.h>
#include <stdio.h>*/

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	larger;

	i = 0;
	larger = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
		larger++;
		i++;
	}
	if (s2[larger] != '\0')
		return (-1);
	else
		return (0);
	return (1);
}

/*int main(void)
{
	int comp;
    
    	comp = ft_strcmp("hola", "hola");
	printf("Result of strcmp(\"hola\", \"hola\"): %d\n", comp);

	write(1, "\n", 1);
	comp = ft_strcmp("hol", "hola");
	printf("Result of strcmp(\"hol\", \"hola\"): %d\n", comp);

	write(1, "\n", 1);
	comp = ft_strcmp("i", "holb");
	printf("Result of strcmp(\"i\", \"holb\"): %d\n", comp);
	
	write(1, "\n", 1);
	comp = ft_strcmp("a", "holb");
	printf("Result of strcmp(\"a\", \"holb\"): %d\n", comp);
	
	comp = strcmp("hola", "hola");
	printf("Result of strcmp(\"hola\", \"hola\"): %d\n", comp);

	write(1, "\n", 1);
	comp = strcmp("hol", "hola");
	printf("Result of strcmp(\"hol\", \"hola\"): %d\n", comp);

	write(1, "\n", 1);
	comp = strcmp("i", "holb");
	printf("Result of strcmp(\"i\", \"holb\"): %d\n", comp);
	
	write(1, "\n", 1);
	comp = strcmp("a", "holb");
	printf("Result of strcmp(\"a\", \"holb\"): %d\n", comp);
	
    return 0;
}*/
