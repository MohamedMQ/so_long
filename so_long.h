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

# include "./utils_functions/get_next_line.h"
# include "./ft_printf/ft_printf.h"
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

typedef struct t_data_2
{
	char		*img_floor;
	void		*mlx;
	int			sum_coin;
	int			sum_in_map;
}				t_data_2;

typedef struct s_data
{
	t_data_2	data_2;
	t_map		m_p;
	int			width;
	int			height;
	int			check;
	int			just_one_coin;
}				t_data;

t_data				get_map_ptr(t_data data, char *argv);
void				check_map(t_data *data);
void				check_path(t_data *data, char *argv);
void				check_name_map(char *argv);
void				initialize_some_struct(t_data *data);
void				eroor_map(t_data *data);
char				*ft_itoa(int n);

#endif
