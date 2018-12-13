/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:44:39 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/08 17:44:38 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

int		check_pos(char *map, t_tet *current, int t)
{
	int i;
	int nb;
	int len;
	int x;
	int	y;

	len = 0;
	while (map[len] != '\n')
		len++;
	len++;
	i = 0;
	nb = 1;
	while (map[t + i] != '\0')
	{
		if (nb == 1)
			if (map[t + i] != '.')
				nb = 5;
		while (nb < 4)
		{
			x = 0;
			y = 0;
			if (current->coor[nb] % 10 != 0)
				x = current->coor[nb] % 10;
			if (current->coor[nb] / 100 != 0)
				y = current->coor[nb] / 100;
			if (current->coor[nb] % 100 != 0 && current->coor[nb] % 10 == 0)
				x = -((current->coor[nb] % 100) / 10);
			if (map[t + i + x + (y * len)] != '.' )
				nb = 5;
			nb++;
			if (nb == 4)
				return (t + i);
		}
		nb = 1;
		i++;
	}
	return (-1);
}

void	put_tetri(char *map, t_tet *current, int t)
{
	int	nb;
	int	x;
	int	y;
	int len;

	len = 0;
	while (map[len] != '\n')
		len++;
	len++;
	//printf("le caractere est: %c\n", map[10000000]);
	//printf("premier lettre a la position: %d\n", t);
	//printf("premier lettre remplace: %c\n", map[t]);
	map[t] = 'A' + (current->p - 1);
	nb = 1;
	while (nb < 4)
	{
		x = 0;
		y = 0;
		if (current->coor[nb] % 10 != 0)
			x = current->coor[nb] % 10;
		if (current->coor[nb] / 100 != 0)
			y = current->coor[nb] / 100;
		if (current->coor[nb] % 100 != 0 && current->coor[nb] % 10 == 0)
			x = -((current->coor[nb] % 100) / 10);
		//printf("Index: (%d)\n", t + x + (y * len));
		//printf("Caractere:  [%c]\n", map[t + x + (y * len)]);
		map[t + x + (y * len)] = 'A' + (current->p - 1);
		nb++;
	}
}

void	replace_tetri(char *map, t_tet *current, int t)
{
	int	nb;
	int	x;
	int	y;
	int len;

	len = 0;
	while (map[len] != '\n')
		len++;
	len++;
	map[t] = '.'; 
	nb = 1;
	while (nb < 4)
	{
		x = 0;
		y = 0;
		if (current->coor[nb] % 10 != 0)
			x = current->coor[nb] % 10;
		if (current->coor[nb] / 100 != 0)
			y = current->coor[nb] / 100;
		if (current->coor[nb] % 100 != 0 && current->coor[nb] % 10 == 0)
			x = -((current->coor[nb] % 100) / 10);
		map[t + x + (y * len)] = '.';
		nb++;
	}
}

int		solve_tet(char **map, t_tet *current, int t)
{
	char	*tmp;
	int		i;

	i = 0;
	if (current == NULL)
		return (1);
	while ((*map)[t] != '\0')
	{
		tmp = ft_strdup(*map);
		if ((i = check_pos(*map, current, t)) >= 0)
		{
			put_tetri(*map, current, i);
			if (solve_tet(map, current->next, i + 1) == 1)
				return (1);
		}
		if (i == -1)
			return (0);
		//free(*map);
		*map = tmp;
		t = i + 1;
	}
	return (0);
}
