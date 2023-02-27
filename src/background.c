/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:31:19 by sfernand          #+#    #+#             */
/*   Updated: 2023/01/31 10:24:12 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	verif(void *mlx, void *window, char c, int x, int y)
{
	t_program program;
	
	if (c == '1')
	{
		program.sprite = ft_new_sprite(mlx, "./asset/brick.xpm");
		mlx_put_image_to_window(mlx, window, program.sprite.reference, x, y);
	}
	if (c == '0')
	{
		program.sprite = ft_new_sprite(mlx, "./asset/grass.xpm");
		mlx_put_image_to_window(mlx, window, program.sprite.reference, x, y);
	}
	if (c == 'C')
	{
		program.sprite = ft_new_sprite(mlx, "./asset/item.xpm");
		mlx_put_image_to_window(mlx, window, program.sprite.reference, x, y);
	}
	if (c == 'E')
	{
		program.sprite = ft_new_sprite(mlx, "./asset/exit.xpm");
		mlx_put_image_to_window(mlx, window, program.sprite.reference, x, y);
	}
	if (c == 'P')
	{
		program.sprite = ft_new_sprite(mlx, "./asset/player.xpm");
		mlx_put_image_to_window(mlx, window, program.sprite.reference, x, y);
	}
	
}

char	**background(void *mlx, int fd, int x, int y)
{
	t_program	program;
	char		**tab;
	int		i;
	int		n;
	
	tab = (char**)malloc(sizeof(char*) * x);
	program.window = ft_new_window(mlx, x*32, y*32, "so_long");
	i = 0;
	n = 0;
	program.sprite_position.x = 0;
	program.sprite_position.y = 0;
	tab[i] = get_next_line(fd);
	while(tab[i])
	{
		ft_printf("tab[%d] = %s\n", i, tab[i]);
		while(tab[i][n] && n != x)
		{
			verif(mlx, program.window.reference, tab[i][n], program.sprite_position.x, program.sprite_position.y);
			program.sprite_position.x = program.sprite_position.x + 32;
			n++;
		}
		program.sprite_position.x = 0;
		program.sprite_position.y = program.sprite_position.y + 32;
		n = 0;
		i++;
		tab[i] = get_next_line(fd);
	}
	return (tab);
}
