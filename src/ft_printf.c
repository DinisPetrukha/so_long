/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:13:57 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/02/13 12:06:24 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_printf_char(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_printf_nbr(long nbr, int base, int size)
{
	int		count;
	char	*symbols;
	char	*symbols_up;

	count = 0;
	symbols = "0123456789abcdef";
	symbols_up = "0123456789ABCDEF";
	if (nbr < 0)
	{
		ft_printf_char('-');
		return (ft_printf_nbr(-nbr, base, size) + 1);
	}
	else if (nbr < base)
	{
		if (size == 1)
			return (ft_printf_char(symbols[nbr]));
		else
			return (ft_printf_char(symbols_up[nbr]));
	}
	else
	{
		count = ft_printf_nbr(nbr / base, base, size);
		return (ft_printf_nbr(nbr % base, base, size) + count);
	}
}

static int	ft_formatter(char symbol, va_list args)
{
	int	count;

	count = 0;
	if (symbol == 'd' || symbol == 'i')
		count = ft_printf_nbr(va_arg(args, int), 10, 1);
	else if (symbol == 'c')
		count = ft_printf_char((char)va_arg(args, int));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_formatter(str[i++], args);
		}
		else
			count += write(1, &str[i++], 1);
	}
	va_end(args);
	return (count);
}
