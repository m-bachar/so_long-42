/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:48:00 by mbachar           #+#    #+#             */
/*   Updated: 2023/01/22 22:56:09 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_rectangular(t_list *no)
{
	char	*str;
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 1;
	i = 0;
	str = no->mapone;
	while (str[i] != '\n')
	{
		i++;
		x++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			y++;
		i++;
	}
	if (x == y)
		return (0);
	return (1);
}

int	ft_equal_lines(t_list *no)
{
	char	*map;
	int		reference;
	int		i;

	map = no->mapone;
	reference = ft_strlen_n(map);
	i = 0;
	while (*map != '\0')
	{
		if (*map == '\0' || *map == '\n')
		{
			if (i != reference)
				return (0);
			i = 0;
			map++;
		}
		else
		{
			i++;
			map++;
		}
	}
	if (i != reference)
		return (0);
	return (1);
}

int	ft_closed_map_up_left(t_list *no)
{
	char	*str;
	int		i;

	str = no->mapone;
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			i++;
			if (str[i] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_closed_map_down_right(t_list *no)
{
	char	*str;
	int		i;

	str = no->mapone;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			i--;
			if (str[i] != '1')
				return (0);
			i++;
		}
		i++;
	}
	i = ft_strlen(str) - 1;
	while (str[i] != '\n')
	{
		if (str[i] != '1')
			return (0);
		i--;
	}
	return (1);
}
