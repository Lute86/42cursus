/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:29:23 by sluterea          #+#    #+#             */
/*   Updated: 2024/12/18 11:29:24 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE 1

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_display_file(char *argv[])
{
	int		fd;
	char	buf[BUF_SIZE];

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot read file.\n");
		return (0);
	}
	while (read(fd, buf, BUF_SIZE) > 0)
		write(1, &buf, 1);
	if (close(fd) == -1)
	{
		ft_putstr("Cannot close file.\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else if (argc < 2)
		ft_putstr("File name missing.\n");
	else if (argc == 2)
		ft_display_file(argv);
	return (0);
}
