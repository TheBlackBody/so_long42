/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:24:24 by sfernand          #+#    #+#             */
/*   Updated: 2023/03/03 16:23:05 by sfernand         ###   ########.fr       */
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
	if (key == 13)
                program->sprite_position.x += program->sprite.size.x;
        else if (key == 1)
                program->sprite_position.x -= program->sprite.size.x;
        else if (key == 0)
                program->sprite_position.y += program->sprite.size.y;
        else if (key == 2)
                program->sprite_position.y -= program->sprite.size.y;
        ft_printf("%d\n", key);
        return (0);
}

void move(char **tab/*, void *mlx*/, t_program program, int i)
{
    int x;
    int y;

    x = 0;
    y = 0;
    program.sprite_position.x = 0;
    program.sprite_position.y = 0;
    ft_printf("%d\n", i);
    while (x != i && tab[y][x] != 'P')
    {
        x++;
        if (x == i)
        {
                x = 0;
                y++;
        }
    }
    mlx_key_hook(program.window.reference, ft_input, &program);
}