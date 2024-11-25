/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:30:51 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/02/08 18:55:13 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *data)
{
	int	i;

	i = 0;
	free_map(data->map);
	free_map(data->cpy_map);
	while (i < NBR_OF_IMGS)
	{
		if (data->imgs[i].img_ptr)
		{
			mlx_destroy_image(data->mlx_ptr, data->imgs[i].img_ptr);
			data->imgs[i].img_ptr = NULL;
		}
		i++;
	}
	free(data->goblin);
	mlx_destroy_image(data->mlx_ptr, data->canva.img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

void	player_movement(int keycode, t_data *data)
{
	if (keycode == W || keycode == UP)
	{
		data->player.img = data->imgs[PLAYER_UP_];
		data->player.y -= 1;
		player_w(data);
	}
	if (keycode == S || keycode == DOWN)
	{
		data->player.img = data->imgs[PLAYER_DOWN_];
		data->player.y += 1;
		player_s(data);
	}
	if (keycode == A || keycode == LEFT)
	{
		data->player.img = data->imgs[PLAYER_LEFT_];
		data->player.x -= 1;
		player_a(data);
	}
	if (keycode == D || keycode == RIGHT)
	{
		data->player.img = data->imgs[PLAYER_RIGHT_];
		data->player.x += 1;
		player_d(data);
	}
}

void	game_finished(t_data *data)
{
	if (data->n_collect == 0)
		data->door.img = data->imgs[DOOR_OPENED_];
	if (data->endgame == 1)
	{
		ft_printf("You Win! :D\nTotal Moves: %i", data->n_moves);
		close_window(data);
	}
}

int	keypress(int keycode, t_data *data)
{
	if (keycode == ESC || keycode == Q)
	{
		close_window(data);
		exit(0);
	}
	player_movement(keycode, data);
	game_finished(data);
	ft_printf("Moves: %i\n", data->n_moves);
	return (0);
}
