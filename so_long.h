/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:11:56 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/04/08 11:38:08 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct map
{
	char		**ptr;
	char		**ptr_2;
	int			x;
	int			y;
}				t_map;

typedef struct s_data
{
	t_map		m_p;
	int			width;
	int			height;
}				t_data;

void				check_name_map(char *argv);
void				initialize_some_struct(t_data *data);
void				eroor_map(t_data *data);

#endif
