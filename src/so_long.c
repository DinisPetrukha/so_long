/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:54:12 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/02/08 18:38:48 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	file_checker(char *file_name)
{
	int	i;

	if (!file_name)
		return (0);
	i = 0;
	while (file_name[i])
		i++;
	if (file_name[i - 1] && file_name[i - 1] == 'r'
		&& file_name[i - 2] == 'e' && file_name[i - 3] == 'b')
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	static t_data	data;

	if (argc == 2)
	{
		read_map(argv[1], &data);
		if (file_checker(argv[1]) && map_checker(&data))
		{
			game_init(&data);
			mlx_loop(data.mlx_ptr);
		}
		else
		{
			if (data.map)
			{
				free_map(data.map);
				free_map(data.cpy_map);
			}
			write(1, "Error\nInvalid Map\n", 18);
			exit(1);
		}
	}
	else
	{
		write(1, "Error\n[so_long] [map/map1.ber]\n", 32);
		exit(1);
	}
	return (0);
}
