/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:19:24 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/08 17:35:04 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*map_generator(int size)
{
	int		i;
	int		j;
	char	*map;

	if (!(map = (char*)malloc(sizeof(*map) * ((size * size) + size))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < (size * size) + size)
	{
		if (j == size)
		{
			j = 0;
			map[i] = '\n';
			i++;
		}
		else
		{
			map[i] = '.';
			i++;
			j++;
		}
	}
	map[(size * size) + size] = '\0';
	return (map);
}
