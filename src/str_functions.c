/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:34:05 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/02/11 16:55:46 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char	*str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	char	*ptr;

	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	i = 0;
	ptr = malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (s1 && *s1)
		ptr[i++] = *s1++;
	while (s2 && *s2)
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen((char *)str);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i < len)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int	ft_digits(long long num)
{
	int	digits;

	digits = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	int			len;
	int			len_cpy;
	long long	num;
	char		*ptr;

	num = n;
	len = ft_digits(num);
	len_cpy = len;
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	if (num == 0)
		ptr[0] = '0';
	while (num != 0)
	{
		ptr[--len] = '0' + (num % 10);
		num /= 10;
	}
	ptr[len_cpy] = '\0';
	return (ptr);
}
