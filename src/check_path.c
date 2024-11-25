/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:21:29 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/02/08 18:53:50 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	y;

	if (!map)
		return ;
	y = 0;
	while (map[y])
		free(map[y++]);
	free(map);
}

static void	fill(t_data *data, t_point cur, int *c_ptr, int *e_ptr)
{
	if (cur.y < 0 || cur.y >= data->map_h
		|| cur.x < 0 || cur.x >= data->map_l
		|| data->cpy_map[cur.y][cur.x] == '1'
		|| data->cpy_map[cur.y][cur.x] == 'B')
		return ;
	if (data->cpy_map[cur.y][cur.x] == 'C')
		(*c_ptr) -= 1;
	else if (data->cpy_map[cur.y][cur.x] == 'E')
		(*e_ptr) -= 1;
	data->cpy_map[cur.y][cur.x] = '1';
	fill(data, (t_point){cur.x - 1, cur.y}, c_ptr, e_ptr);
	fill(data, (t_point){cur.x + 1, cur.y}, c_ptr, e_ptr);
	fill(data, (t_point){cur.x, cur.y - 1}, c_ptr, e_ptr);
	fill(data, (t_point){cur.x, cur.y + 1}, c_ptr, e_ptr);
}

static void	flood_fill(t_data *data, int *c_ptr, int *e_ptr)
{
	t_point	begin;

	begin.x = data->player.x;
	begin.y = data->player.y;
	fill(data, begin, c_ptr, e_ptr);
}

int	check_path(t_data *data)
{
	int		c;
	int		e;

	if (!data)
		return (0);
	c = data->n_collect;
	e = data->n_exit;
	flood_fill(data, &c, &e);
	if (c == 0 && e == 0)
		return (1);
	return (0);
}
