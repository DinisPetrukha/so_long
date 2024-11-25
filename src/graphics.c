/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:10:19 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/02/13 12:06:08 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (color == -16777216)
		return ;
	dst = image->addr + (y * image->line_len + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	my_mlx_pixel_get(t_image *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	return (*(unsigned int *)dst);
}

void	my_mlx_put_image(t_image *image, t_image *canva, int sx, int sy)
{
	int	y;
	int	x;

	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			my_mlx_pixel_put(canva, sx + x, sy + y, \
			my_mlx_pixel_get(image, x, y));
			x++;
		}
		y++;
	}
}

void	load_image(char *path, t_image *img, void *mlx_ptr)
{
	img->img_ptr = mlx_xpm_file_to_image(mlx_ptr, path,
			&img->width, &img->height);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_len,
			&img->endian);
}

void	load_all_images(t_data *data)
{
	load_image("assets/player/player_left.xpm",
		&data->imgs[PLAYER_LEFT_], data->mlx_ptr);
	load_image("assets/player/player_right.xpm",
		&data->imgs[PLAYER_RIGHT_], data->mlx_ptr);
	load_image("assets/player/player_up.xpm",
		&data->imgs[PLAYER_UP_], data->mlx_ptr);
	load_image("assets/player/player_down.xpm",
		&data->imgs[PLAYER_DOWN_], data->mlx_ptr);
	load_image("assets/enemies/goblin/goblin_left.xpm",
		&data->imgs[GOBLIN_LEFT_], data->mlx_ptr);
	load_image("assets/enemies/goblin/goblin_right.xpm",
		&data->imgs[GOBLIN_RIGHT_], data->mlx_ptr);
	load_image("assets/enemies/goblin/goblin_up.xpm",
		&data->imgs[GOBLIN_UP_], data->mlx_ptr);
	load_image("assets/enemies/goblin/goblin_down.xpm",
		&data->imgs[GOBLIN_DOWN_], data->mlx_ptr);
	load_image("assets/itens/barrel.xpm",
		&data->imgs[BARREL_], data->mlx_ptr);
	load_image("assets/itens/coin_bonus0.xpm",
		&data->imgs[COINS_0_], data->mlx_ptr);
	load_image("assets/itens/coin_bonus1.xpm",
		&data->imgs[COINS_1_], data->mlx_ptr);
	load_image("assets/itens/coin_bonus2.xpm",
		&data->imgs[COINS_2_], data->mlx_ptr);
	load_all_images2(data);
}
