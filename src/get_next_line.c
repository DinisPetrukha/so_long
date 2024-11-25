/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:07:47 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/01/27 13:41:33 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	ft__strlen(const char	*str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return ((i + (str[i] == '\n')));
}

static char	*ft__strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	int		len;
	char	*new_str;

	i = 0;
	j = 0;
	len = ft__strlen(str2);
	new_str = malloc((ft__strlen(str1) + len + 1) * sizeof(char));
	if (!new_str)
	{
		free(str1);
		return (NULL);
	}
	while (str1 && str1[i])
	{
		new_str[i] = str1[i];
		i++;
	}
	while (str2[j] && j < len)
		new_str[i++] = str2[j++];
	new_str[i] = '\0';
	free(str1);
	return (new_str);
}

static int	ft_update_buffer(char *buffer, int check_point)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (check_point == 1)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			check_point = 1;
		buffer[i] = '\0';
		i++;
	}
	return (check_point);
}

static char	*ft_read(int fd, char *buffer, char *line)
{
	int		char_read;

	char_read = 1;
	while (char_read > 0)
	{
		if (!buffer[0])
			char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read == 0)
			return (line);
		line = ft__strjoin(line, buffer);
		if (line == NULL)
		{
			ft_update_buffer(buffer, 1);
			return (NULL);
		}
		if (ft_update_buffer(buffer, 0))
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
	{
		ft_update_buffer(buffer, 1);
		return (NULL);
	}
	line = ft_read(fd, buffer, NULL);
	return (line);
}
