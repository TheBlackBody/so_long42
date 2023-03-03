/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:09:39 by sfernand          #+#    #+#             */
/*   Updated: 2023/03/03 16:11:28 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include <fcntl.h>
# include "./get_next_line/get_next_line.h"
# include "./printf/printf.h"
# include "./Libft1/libft.h"

typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct	s_window {
	void		*reference;
	t_vector	size;
}				t_window;

typedef struct	s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct	s_program {
	void		*mlx;
	t_window	window;
	t_image		sprite;
	t_vector	sprite_position;
}				t_program;
t_window	ft_new_window(void *mlx, int widht, int height, char *name);
char		**background(void *mlx, int x, t_program program);
t_image 	ft_new_sprite(void *mlx, char *path);
void 		move(char **tab/*, void *mlx*/, t_program program, int x);
#endif
