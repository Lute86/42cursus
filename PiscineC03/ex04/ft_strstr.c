/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:38:14 by sluterea          #+#    #+#             */
/*   Updated: 2024/08/15 16:38:17 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	start;
	int	count;
	int	j;

	j = 0;
	start = 0;
	count = 0;
	while (to_find[count] != '\0')
		count++;
	while (str[start] != '\0')
	{
		while (str[start] == to_find[j])
		{
			j++;
			start++;
		}
		if (j == count)
			return (str + start - j);
		else
			j = 0;
		start++;
	}
	return (NULL);
}

/*int main()
{
    char str[] = "Hello, worlde!";
    char to_find[] = "worlde";

    char *result = ft_strstr(str, to_find);
    if (result)
        printf("Found substring: %s\n", result);
    else
        printf("Substring not found.\n");

    return 0;
}*/
