/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:10:14 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/04/08 11:14:45 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_position(int keycode, t_data *data, int i, int j)
{
	if (keycode == 0)
	{
		mlx_put_image_to_window(data->data_2.mlx, data->w_n.mlx_win,
			data->p_l.new_player_2, j * 106, i * 106);
		data->check = 0;
	}
	else if (keycode == 2)
	{
		mlx_put_image_to_window(data->data_2.mlx, data->w_n.mlx_win,
			data->p_l.new_player, j * 106, i * 106);
		data->check = 1;
	}
	else if (data->check == 1)
		mlx_put_image_to_window(data->data_2.mlx, data->w_n.mlx_win,
			data->p_l.new_player, j * 106, i * 106);
	else if (data->check == 0)
		mlx_put_image_to_window(data->data_2.mlx, data->w_n.mlx_win,
			data->p_l.new_player_2, j * 106, i * 106);
}

void	display_all_window_2(int keycode, t_data *data, int i, int j)
{
	void	*l_void;

	display_all_window_2_2(data, keycode, i, j);
	if (data->m_p.ptr[i][j] == 'E')
	{
		data->data_2.i = i;
		data->data_2.j = j;
		mlx_put_image_to_window(data->data_2.mlx, data->w_n.mlx_win,
			data->d_r.new_door, j * 106, i * 106);
	}
	if (data->m_p.ptr[i][j] == 'M')
	{
		l_void = mlx_xpm_file_to_image(data->data_2.mlx,
				"./so_long_bonus/textures/boom.XPM",
				&data->width, &data->height);
		mlx_put_image_to_window(data->data_2.mlx, data->w_n.mlx_win,
			l_void, j * 106, i * 106);
	}
}

void	display_all_window(int keycode, t_data *data)
{
	int		i;
	int		j;
	char	*string;

	i = 0;
	display_empty_space(data);
	while (data->m_p.ptr[i])
	{
		j = 0;
		while (data->m_p.ptr[i][j] != '\0')
		{
			display_all_window_2(keycode, data, i, j);
			j++;
		}
		i++;
	}
	string = ft_itoa(data->p_l.count_move);
	mlx_string_put(data->data_2.mlx, data->w_n.mlx_win,
		153, 0, 0xFFFFFFFF, string);
	mlx_string_put(data->data_2.mlx, data->w_n.mlx_win,
		0, 0, 0xFFFFFFFF, "Count_Mouve : ");
	free(string);
}
