/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:22:36 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/08 15:32:07 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "../libft/libft.h"

typedef struct	s_tet
{
	int				p;
	int				i;
	int				*coor;
	struct s_tet	*next;
}				t_tet;

int				verif_take_tet(const int fd, t_tet **tet);
char			*map_generator(int size);
int				solve_tet(char **map, t_tet *current, int t);
int				take_tet(char *s, t_tet **tet, int nb);
int				get_size(int nb);

#endif
