/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:44:39 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/14 14:54:08 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	check_pos1(int pos, int *x, int *y)
{
	*x = 0;
	*y = 0;
	if (pos % 10 != 0)
		*x = pos % 10;
	if (pos / 100 != 0)
		*y = pos / 100;
	if (pos % 100 != 0 && pos % 10 == 0)
		*x = -((pos % 100) / 10);
}

int		check_pos(char *map, t_tet *current, int t, int size)
{
	int i;
	int nb;
	int x;
	int	y;

	i = -1;
	nb = 1;
	while (map[t + ++i] != '\0')
	{
		if (nb == 1)
			if (map[t + i] != '.')
				nb = 5;
		while (nb < 4)
		{
			check_pos1(current->coor[nb], &x, &y);
			if (map[t + i + x + (y * (size + 1))] != '.' ||
					t + i + x + (y * (size + 1)) > ((size * size) + size))
				nb = 5;
			nb++;
			if (nb == 4)
				return (t + i);
		}
		nb = 1;
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

int		solve_tet(char **map, t_tet *current, int t, int size)
{
	int		i;

	i = 0;
	if (current == NULL)
		return (1);
	while ((*map)[t] != '\0')
	{
		if ((i = check_pos(*map, current, t, size)) >= 0)
		{
			put_tetri(*map, current, i);
			if (solve_tet(map, current->next, 0, size) == 1)
				return (1);
			replace_tetri(*map, current, i);
		}
		if (i == -1)
			return (0);
		t = i + 1;
	}
	return (0);
}
