/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:27:44 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/02/13 12:06:35 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	animation(t_data *data)
{
	if (data->coin.loop < 10)
	{
		data->coin.loop++;
		return (0);
	}
	if (data->coin.pos_coin == 1)
		data->coin.img = data->imgs[COINS_0_];
	else if (data->coin.pos_coin == 2)
		data->coin.img = data->imgs[COINS_1_];
	else if (data->coin.pos_coin == 3)
		data->coin.img = data->imgs[COINS_2_];
	else if (data->coin.pos_coin == 4)
	{
		data->coin.img = data->imgs[COINS_3_];
		data->coin.pos_coin = 0;
	}
	data->coin.pos_coin++;
	data->coin.loop = 0;
	return (0);
}

int	ft_findchar(char c, char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
