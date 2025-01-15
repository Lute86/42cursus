/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <sluterea@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:49:33 by sluterea          #+#    #+#             */
/*   Updated: 2025/01/09 18:49:33 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv) //una linea
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
		printf("%s", str);
		if (close(fd) == -1)
		{
			ft_putstr("Cannot close file.\n");
			return (1);
		}
	}
	return (0);
}
