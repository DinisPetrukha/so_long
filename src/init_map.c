/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:47:13 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/11/18 16:02:46 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_size(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[0][i])
		i++;
	data->map_l = i;
	i = 0;
	while (data->map[i])
		i++;
	data->map_h = i;
}

void	player_position(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->player.x = x;
				data->player.y = y;
			}
			x++;
		}
		y++;
	}
}

void	set_goblin_positons(t_data *data)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	i = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'G')
			{
				data->goblin[i].y = y;
				data->goblin[i].x = x;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	elements_init(t_data *data)
{
	int	i;

	i = 0;
	data->goblin = malloc(sizeof(t_goblin) * (data->n_goblins + 1));
	if (!data->goblin)
		return ;
	set_goblin_positons(data);
	while (i < data->n_goblins)
	{
		data->goblin[i].img = data->imgs[GOBLIN_RIGHT_];
		data->goblin[i].c = 'R';
		i++;
	}
	data->goblin[i].c = '\0';
	data->player.img = data->imgs[PLAYER_DOWN_];
	data->door.img = data->imgs[DOOR_CLOSED_];
	data->coin.img = data->imgs[COINS_0_];
}


void	game_init(t_data *data)
{
	map_size(data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map_l * BLOCK,
			data->map_h * BLOCK, "so_long");
	if (!data->win_ptr)
		return ;
	data->canva.img_ptr = mlx_new_image(data->mlx_ptr, data->map_l * BLOCK,
			data->map_h * BLOCK);
	data->canva.addr = mlx_get_data_addr(data->canva.img_ptr, &data->canva.bpp,
			&data->canva.line_len, &data->canva.endian);
	load_all_images(data);
	elements_init(data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask,
		close_window, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, keypress, data);
	mlx_loop_hook(data->mlx_ptr, draw_map, data);
}
