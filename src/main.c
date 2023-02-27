/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 09:33:17 by sfernand          #+#    #+#             */
/*   Updated: 2023/01/31 10:19:04 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main()
{
	t_program	program;
	int			fd;
	int			x;
	int			y;
	char			*line;
	char			**tab;

	fd = open("map.ber", O_RDONLY);
	
	line = get_next_line(fd);
	x = strlen(line) - 1;
	y = 0;
	tab = (char**)malloc(sizeof(char*) * x);
	while (line != NULL)
	{
		y++;
		line = get_next_line(fd);
	}
	close(fd);
	program.mlx = mlx_init();
	fd = open("map.ber", O_RDONLY);
	tab = background(program.mlx, fd, x, y);
	close(fd);
	mlx_loop(program.mlx);
	return (0);
}


