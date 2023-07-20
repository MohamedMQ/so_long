/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:11:44 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/04/08 11:11:46 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_name_map(char *argv)
{
	int			i;
	int			j;
	int			tmp;
	char		*ptr;
	static int	valid;

	ptr = ".ber";
	i = -1;
	while (argv[++i])
	{
		j = 0;
		tmp = i;
		while (argv[tmp] == ptr[j] && ptr[j])
		{
			tmp++;
			j++;
		}
		if (ptr[j] == '\0')
			valid = 1;
	}
	if (valid == 0)
	{
		ft_printf("Name map invalid !!!\n");
		exit(1);
	}
}

void	initialize_some_struct(t_data *data)
{
	data->just_one_coin = 0;
	data->data_2.sum_coin = 0;
	data->check = 0;
	data->m_p.y = 0;
	data->m_p.x = 0;
	data->m_p.ptr = 0;
	data->m_p.ptr_2 = 0;
}

void	check_esp(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->data_2.mlx, data->w_n.mlx_win);
		exit(0);
	}
}

void	eroor_map(t_data *data)
{
	if (data->m_p.ptr)
		free(data->m_p.ptr);
	if (data->m_p.ptr_2)
		free(data->m_p.ptr_2);
	ft_printf("Error\n");
	ft_printf("you have error in your map\n");
	exit(1);
}

t_data	get_map_ptr(t_data data, char *argv)
{
	int	i;
	int	fd;

	i = 0;
	data.m_p.ptr = (char **)malloc((data.m_p.y + 1) * sizeof(char *));
	if (!data.m_p.ptr)
		exit (1);
	fd = open(argv, O_RDWR);
	if (fd < 0)
		exit (0);
	while (i < data.m_p.y)
		data.m_p.ptr[i++] = get_next_line(fd);
	data.m_p.ptr[data.m_p.y] = 0;
	close(fd);
	return (data);
}
