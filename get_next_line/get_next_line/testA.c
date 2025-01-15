/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testA.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <sluterea@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:49:42 by sluterea          #+#    #+#             */
/*   Updated: 2025/01/09 18:49:42 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;
	char	*str;

	if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else if (argc < 2)
		ft_putstr("File name missing.\n");
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("Cannot read file.\n");
			return (1);
		}
		str = get_next_line(fd);
		if (!str)
			printf("Nula");
		while (str != NULL)
		{	
			printf("%s", str);
			str = get_next_line(fd);
		}
		if (close(fd) == -1)
		{
			ft_putstr("Cannot close file.\n");
			return (1);
		}
	}
	return (0);
}
