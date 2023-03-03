/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 09:33:17 by sfernand          #+#    #+#             */
/*   Updated: 2023/03/03 16:11:13 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error(void)
{
	ft_printf("vous n'avez pas mis de map\n");
}

int	size_y(char *line, int fd)
{
	int	y;

	y = 0;
	while (line != NULL)
	{
		y++;
		line = get_next_line(fd);
	}
	return (y);
}

int	main(int argc, char **argv)
{
	t_program	program;
	int			fd;
	char		*line;
	char		**tab;

	if (argc == 1)
	{
		error();
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	program.window.size.x = strlen(line) - 1;
	program.window.size.y = size_y(line, fd);
	tab = (char **)malloc(sizeof (char *) * program.window.size.x);
	close(fd);
	program.mlx = mlx_init();
	program.window = ft_new_window(program.mlx, program.window.size.x * 32, program.window.size.y * 32, "so_long");
	tab = background(program.mlx, 
			program.window.size.x, program);
	close(fd);
	move(tab,/* program.mlx,*/ program, strlen(tab[0]) - 1);
	mlx_loop(program.mlx);
	return (0);
}
