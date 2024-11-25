/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:06:22 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/02/13 11:57:45 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_w(t_data *data)
{
	if (data->map[data->player.y][data->player.x] == 'E' &&
		data->n_collect == 0)
	{
		data->n_moves++;
		data->endgame = 1;
	}
	else if (data->map[data->player.y][data->player.x] == '1' ||
		(data->map[data->player.y][data->player.x] == 'E' &&
		data->n_collect > 0) ||
		data->map[data->player.y][data->player.x] == 'B')
	{
		data->player.y += 1;
	}
	else
	{
		if (data->map[data->player.y][data->player.x] == 'C')
		{
			data->n_collect--;
			data->map[data->player.y][data->player.x] = '0';
		}
		data->n_moves++;
	}
	draw_map(data);
}

void	player_s(t_data *data)
{
	if (data->map[data->player.y][data->player.x] == 'E' &&
		data->n_collect == 0)
	{
		data->n_moves++;
		data->endgame = 1;
	}
	else if (data->map[data->player.y][data->player.x] == '1' ||
		(data->map[data->player.y][data->player.x] == 'E' &&
		data->n_collect > 0) ||
		data->map[data->player.y][data->player.x] == 'B')
	{
		data->player.y -= 1;
	}
	else
	{
		if (data->map[data->player.y][data->player.x] == 'C')
		{
			data->n_collect--;
			data->map[data->player.y][data->player.x] = '0';
		}
		data->n_moves++;
	}
	draw_map(data);
}

void	player_a(t_data *data)
{
	if (data->map[data->player.y][data->player.x] == 'E' &&
		data->n_collect == 0)
	{
		data->n_moves++;
		data->endgame = 1;
	}
	else if (data->map[data->player.y][data->player.x] == '1' ||
		(data->map[data->player.y][data->player.x] == 'E' &&
		data->n_collect > 0) ||
		data->map[data->player.y][data->player.x] == 'B' )
	{
		data->player.x += 1;
	}
	else
	{
		if (data->map[data->player.y][data->player.x] == 'C')
		{
			data->n_collect--;
			data->map[data->player.y][data->player.x] = '0';
		}
		data->n_moves++;
	}
	draw_map(data);
}

void	player_d(t_data *data)
{
	if (data->map[data->player.y][data->player.x] == 'E' &&
		data->n_collect == 0)
	{
		data->n_moves++;
		data->endgame = 1;
	}
	else if (data->map[data->player.y][data->player.x] == '1'
		|| (data->map[data->player.y][data->player.x] == 'E'
		&& data->n_collect > 0)
		|| data->map[data->player.y][data->player.x] == 'B')
	{
		data->player.x -= 1;
	}
	else
	{
		if (data->map[data->player.y][data->player.x] == 'C')
		{
			data->n_collect--;
			data->map[data->player.y][data->player.x] = '0';
		}
		data->n_moves++;
	}
	draw_map(data);
}
