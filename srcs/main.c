/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:27:03 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/14 15:12:28 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

int		return_usage(void)
{
	ft_putstr("usage: ./fillit test_file\n");
	return (-1);
}

int		return_error(void)
{
	ft_putstr("error\n");
	return (-1);
}

void	lst_delete(t_tet *tet)
{
	t_tet	*tmp;

	while (tet)
	{
		tmp = tet->next;
		free(tet->coor);
		free(tet);
		tet = tmp;
	}
}

char	*launcher(t_tet *tet, int size)
{
	char	*map;

	map = map_generator(size);
	while (solve_tet(&map, tet, 0, size) == 0)
	{
		size++;
		free(map);
		map = map_generator(size);
	}
	return (map);
}

int		main(int ac, char **av)
{
	int			fd;
	int			size;
	int			nb;
	t_tet		*tet;
	char		*map;

	if (ac == 2)
	{
		tet = NULL;
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (return_error());
		if ((nb = verif_take_tet(fd, &tet)) == -1)
			return (return_error());
		if (close(fd) == -1)
			return (return_error());
		size = get_size(nb);
		map = launcher(tet, size);
		ft_putstr(map);
		free(map);
		lst_delete(tet);
		return (0);
	}
	else
		return (return_usage());
}
