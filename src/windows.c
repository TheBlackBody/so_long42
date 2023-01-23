/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:25:14 by sfernand          #+#    #+#             */
/*   Updated: 2023/01/23 17:16:32 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

void	put_map(int fd/*, void *mlx_ptr, void *win_ptr*/)
{
	char	*rand;
	/*int		coordx;
	int		coordy;
	void	*img_ptr;*/

	/*coordx = 0;
	coordy = 0;*/
	rand = get_next_line(fd);
	printf("%s", rand);
	rand = get_next_line(fd);
	printf("%s", rand);
	while (rand != NULL)
	{
		rand = get_next_line(fd);
		printf("%s", rand);
	}
}
