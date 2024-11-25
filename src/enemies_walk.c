/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_walk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:29:54 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/02/08 20:36:40 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	enemy_r(t_data *data, int i)
{
	data->goblin[i].img = data->imgs[GOBLIN_RIGHT_];
	data->goblin[i].x++;
	if (data->map[data->goblin[i].y][data->goblin[i].x] == '1' ||
		data->map[data->goblin[i].y][data->goblin[i].x] == 'B' ||
		data->map[data->goblin[i].y][data->goblin[i].x] == 'E' ||
		data->map[data->goblin[i].y][data->goblin[i].x] == 'C')
	{
		data->goblin[i].x--;
		data->goblin[i].c = 'D';
	}
	if (data->player.x == data->goblin[i].x
		&& data->player.y == data->goblin[i].y)
	{
		ft_printf("You Lose! T.T\nCoins Left: %i\nTotal Moves: %i\n",
			data->n_collect, data->n_moves);
		close_window(data);
	}
}

static void	enemy_d(t_data *data, int i)
{
	data->goblin[i].img = data->imgs[GOBLIN_DOWN_];
	data->goblin[i].y++;
	if (data->map[data->goblin[i].y][data->goblin[i].x] == '1'
		|| data->map[data->goblin[i].y][data->goblin[i].x] == 'B'
		|| data->map[data->goblin[i].y][data->goblin[i].x] == 'E'
		|| data->map[data->goblin[i].y][data->goblin[i].x] == 'C')
	{
		data->goblin[i].y--;
		data->goblin[i].c = 'L';
	}
	if (data->player.x == data->goblin[i].x
		&& data->player.y == data->goblin[i].y)
	{
		ft_printf("You Lose! T.T\nCoins Left: %i\nTotal Moves: %i\n",
			data->n_collect, data->n_moves);
		close_window(data);
	}
}

static void	enemy_l(t_data *data, int i)
{
	data->goblin[i].img = data->imgs[GOBLIN_LEFT_];
	data->goblin[i].x--;
	if (data->map[data->goblin[i].y][data->goblin[i].x] == '1'
		|| data->map[data->goblin[i].y][data->goblin[i].x] == 'B'
		|| data->map[data->goblin[i].y][data->goblin[i].x] == 'E'
		|| data->map[data->goblin[i].y][data->goblin[i].x] == 'C')
	{
		data->goblin[i].x++;
		data->goblin[i].c = 'U';
	}
	if (data->player.x == data->goblin[i].x
		&& data->player.y == data->goblin[i].y)
	{
		ft_printf("You Lose! T.T\nCoins left: %i\nTotal Moves: %i\n",
			data->n_collect, data->n_moves);
		close_window(data);
	}
}

static void	enemy_u(t_data *data, int i)
{
	data->goblin[i].img = data->imgs[GOBLIN_UP_];
	data->goblin[i].y--;
	if (data->map[data->goblin[i].y][data->goblin[i].x] == '1'
		|| data->map[data->goblin[i].y][data->goblin[i].x] == 'B'
		|| data->map[data->goblin[i].y][data->goblin[i].x] == 'E'
		|| data->map[data->goblin[i].y][data->goblin[i].x] == 'C')
	{
		data->goblin[i].y++;
		data->goblin[i].c = 'R';
	}
	if (data->player.x == data->goblin[i].x
		&& data->player.y == data->goblin[i].y)
	{
		ft_printf("You Lose! T.T\nCoins Left: %i\nTotal Moves: %i\n",
			data->n_collect, data->n_moves);
		close_window(data);
	}
}

void	enemies_walk(t_data *data)
{
	int	i;

	i = 0;
	if (data->loop < 25)
	{
		data->loop++;
		return ;
	}
	while (i < data->n_goblins)
	{
		if (data->goblin[i].c == 'R')
			enemy_r(data, i);
		else if (data->goblin[i].c == 'D')
			enemy_d(data, i);
		else if (data->goblin[i].c == 'L')
			enemy_l(data, i);
		else if (data->goblin[i].c == 'U')
			enemy_u(data, i);
		i++;
	}
	data->loop = 0;
}
