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
	char		*line;

	fd = open("map.ber", O_RDONLY);
	
	line = get_next_line(fd);
	ft_printf("%s", line);
	x = strlen(line);
	y = 0;
	while (line != NULL)
	{
		y++;
		line = get_next_line(fd);
	}
	close(fd);
	program.mlx = mlx_init();
	program.window = ft_new_window(program.mlx, 1000, 1000, "so_long");
	ft_printf("1\n");
	fd = open("map.ber", O_RDONLY);
	background(program.mlx/*, fd*/);
	close(fd);
	mlx_loop(program.mlx);
	return (0);
}


