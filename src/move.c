/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:24:24 by sfernand          #+#    #+#             */
/*   Updated: 2023/02/28 16:45:32 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    update_sprite_player(t_program program, void *window, void *mlx)
{
    mlx_destroy_image(mlx, "./asset/snail.xpm");
    mlx_put_image_to_window(mlx, window, program.sprite.reference,
		program.sprite_position.x, program.sprite_position.y);
}

int ft_input(int key, void *param)
{
    t_program *program = (t_program *)param;
}

void move(char **tab, void *mlx, void *window, t_program program)
{
    int x;
    int y;
    int i;

    x = 0;
    y = 0;
    i = 0;
    program.sprite_position.x = 0;
    program.sprite_position.y = 0;
    mlx_key_hook(window, ft_input, &program);
}
