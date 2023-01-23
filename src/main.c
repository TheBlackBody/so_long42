/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 09:33:17 by sfernand          #+#    #+#             */
/*   Updated: 2023/01/23 17:32:00 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

int	main()
{
	/*void	*mlx_ptr;
	void	*win_ptr;*/
	int		fd;
	char	*line;

	fd = open("map.ber", O_RDONLY);
	/*mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1100, 900, "test");*/
	//put_map(fd/*, mlx_ptr, win_ptr*/);
	line = get_next_line(fd);
	ft_printf("%s", line);
	line = get_next_line(fd);
	ft_printf("%s", line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		ft_printf("%s", line);
	}
	//mlx_loop(mlx_ptr);
	return (0);
}
