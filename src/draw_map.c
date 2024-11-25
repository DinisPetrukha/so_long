/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:38:38 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/02/13 11:49:48 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_player_enemies(t_data *data)
{
	int	i;

	i = 0;
	my_mlx_put_image(&data->player.img, &data->canva, data->player.x * BLOCK,
		data->player.y * BLOCK);
	while (data->goblin[i].c != '\0')
	{
		my_mlx_put_image(&data->goblin[i].img, &data->canva,
			data->goblin[i].x * BLOCK, data->goblin[i].y * BLOCK);
		i++;
	}
}

static void	element_checker(char c, int y, int x, t_data *data)
{
	if (c == '1')
	{
		my_mlx_put_image(&data->imgs[WALL_1_], &data->canva, x, y);
		return ;
	}
	my_mlx_put_image(&data->imgs[FLOOR_1_], &data->canva, x, y);
	if (c == 'C')
		my_mlx_put_image(&data->coin.img, &data->canva, x, y);
	else if (c == 'E')
		my_mlx_put_image(&data->door.img, &data->canva, x, y);
	else if (c == 'B')
		my_mlx_put_image(&data->imgs[BARREL_], &data->canva, x, y);
}

void	write_movements(t_data *data)
{
	data->s_moves = ft_itoa(data->n_moves);
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		32, 32, 0xFFFF00, data->s_moves);
	free(data->s_moves);
}

int	draw_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			element_checker(data->map[y][x], y * BLOCK, x * BLOCK, data);
			x++;
		}
		y++;
	}
	animation(data);
	enemies_walk(data);
	draw_player_enemies(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->canva.img_ptr, 0, 0);
	write_movements(data);
	return (0);
}
