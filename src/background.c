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

void background(void *mlx/*, int fd*/)
{
    t_program program;
    
    program.sprite = ft_new_sprite(mlx, "/Users/sfernand/Desktop/cursus42/so_long/so_long/asset/brick.xpm");
	ft_printf("3\n");
	program.sprite_position.x = 0;
	program.sprite_position.y = 0;
    ft_printf("4\n");
	mlx_put_image_to_window(program.mlx, program.window.reference,
		program.sprite.reference, program.sprite_position.x, program.sprite_position.y);
    ft_printf("5\n");
}