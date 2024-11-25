/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:19:11 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/02/08 18:38:44 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_num_elemnts(t_data *data)
{
	if (data->n_exit == 1 && data->n_player == 1
		&& data->n_collect > 0 && data->n_floor > 0)
		return (1);
	return (0);
}

void	read_map_2(t_data *data, char *map_holder)
{
	data->map = ft_split(map_holder, '\n');
	if (!data->map)
	{
		free(map_holder);
		printf("Error\nThe Map Is Empty\n");
		exit(1);
	}
	data->cpy_map = ft_split(map_holder, '\n');
}

void	read_map(char *path, t_data *data)
{
	int			fd;
	char		*map_line;
	static char	*map_holder;
	char		*tmp;

	map_line = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\nInvalid Map\n", 18);
		exit(0);
	}
	while (1)
	{
		map_line = get_next_line(fd);
		if (!map_line)
			break ;
		tmp = map_holder;
		map_holder = ft_strjoin(map_holder, map_line);
		free(map_line);
		free(tmp);
	}
	read_map_2(data, map_holder);
	free(map_holder);
}

void	load_all_images2(t_data *data)
{
	load_image("assets/itens/coin_bonus3.xpm",
		&data->imgs[COINS_3_], data->mlx_ptr);
	load_image("assets/tiles/floor/floor_1.xpm",
		&data->imgs[FLOOR_1_], data->mlx_ptr);
	load_image("assets/tiles/wall/wall_1.xpm",
		&data->imgs[WALL_1_], data->mlx_ptr);
	load_image("assets/tiles/door/door_closed.xpm",
		&data->imgs[DOOR_CLOSED_], data->mlx_ptr);
	load_image("assets/tiles/door/door_opened.xpm",
		&data->imgs[DOOR_OPENED_], data->mlx_ptr);
}
