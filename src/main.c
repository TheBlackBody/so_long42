/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 09:33:17 by sfernand          #+#    #+#             */
/*   Updated: 2023/01/31 09:12:15 by sfernand         ###   ########.fr       */
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
	program.sprite = ft_new_sprite(program.mlx, "/Users/sfernand/Desktop/cursus42/so_long/so_long/asset/brick.xpm");
	ft_printf("2\n");
	program.sprite_position.x = 0;
	program.sprite_position.y = 0;
	mlx_put_image_to_window(program.mlx, program.window.reference,
		program.sprite.reference, program.sprite_position.x, program.sprite_position.y);
	mlx_loop(program.mlx);
}


