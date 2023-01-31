/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:12:30 by sfernand          #+#    #+#             */
/*   Updated: 2023/01/31 10:23:53 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_image ft_new_sprite(void *mlx, char *path)
{
    t_image img;

    img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
    img.pixels  = mlx_get_data_addr(img.reference, &img.bits_per_pixel,
     &img.line_size, &img.endian);
    ft_printf("2\n");
    return  (img);
}