/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 13:33:57 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/02/08 18:49:37 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	count_elements(t_data *data, char c)
{
	if (!ft_findchar(c, ELEMENTS))
	{
		ft_printf("Error\nThe element %c is not acceptable in the map\n", c);
		free_map(data->map);
		free_map(data->cpy_map);
		exit(1);
	}
	if (c == 'C')
		data->n_collect++;
	else if (c == 'E')
		data->n_exit++;
	else if (c == 'P')
		data->n_player++;
	else if (c == '0')
		data->n_floor++;
	else if (c == 'G')
		data->n_goblins++;
}

static int	elements_present(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			count_elements(data, data->map[y][x]);
			x++;
		}
		y++;
	}
	return (check_num_elemnts(data));
}

static int	is_rectangle(t_data *data)
{
	int	length;
	int	height;
	int	i;
	int	j;

	i = 0;
	length = 0;
	height = 0;
	while (data->map[0][length])
		length++;
	while (data->map[height])
		height++;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
			j++;
		if (j != length)
			return (0);
		i++;
	}
	if (length == height)
		return (0);
	return (1);
}

static int	is_walls_arround(t_data *data)
{
	int	x;
	int	y;
	int	len;

	x = 0;
	y = 0;
	while (data->map[y])
		y++;
	while (data->map[0][x] != '\0' && data->map[y - 1][x] != '\0')
	{
		if (data->map[0][x] != '1' || data->map[y - 1][x] != '1')
			return (0);
		x++;
	}
	y = 1;
	len = ft_strlen(data->map[y]);
	while (data->map[y])
	{
		if (data->map[y][0] != '1' || data->map[y][len - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	map_checker(t_data *data)
{
	if (!data)
		return (0);
	map_size(data);
	player_position(data);
	if (elements_present(data) && is_rectangle(data)
		&& is_walls_arround(data) && check_path(data))
		return (1);
	return (0);
}
