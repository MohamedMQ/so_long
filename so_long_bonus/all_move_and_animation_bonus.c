/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_move_and_animation_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:09:54 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/04/08 11:09:56 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	all_move_enemy_help(t_data *data, int c, int t, int *valid)
{
	while (data->m_p.ptr[c][t])
	{
		if (data->m_p.ptr[c][t] == 'M' && data->m_p.ptr[c][t + 1] != '1'
			&& data->m_p.ptr[c][t + 1] != 'C' && data->m_p.ptr[c][t + 1] != 'E'
			&& data->m_p.ptr[c][t + 1] != 'M' && *valid == 0)
		{
			move_enemy_help_1(data, c, t);
			break ;
		}
		else if (data->m_p.ptr[c][t] == 'M' && data->m_p.ptr[c][t - 1] != '1'
				&& data->m_p.ptr[c][t - 1] != 'E' && data->m_p.ptr[c][t
				- 1] != 'C' && data->m_p.ptr[c][t - 1] != 'M')
		{
			move_enemy_help_2(data, c, t);
			*valid = 1;
			break ;
		}
		else if (data->m_p.ptr[c][t] == 'M' && (data->m_p.ptr[c][t - 1] == '1'
			|| data->m_p.ptr[c][t - 1] == 'E' || data->m_p.ptr[c][t
			- 1] == 'C' || data->m_p.ptr[c][t - 1] != 'E'))
			*valid = 0;
		t++;
	}
}

void	move_enemy(t_data *data)
{
	static int	valid;
	static int	l;
	int			c;
	int			t;

	c = 0;
	t = 0;
	if (l == 20 && data->data_2.check_win != 1)
	{
		while (data->m_p.ptr[c])
		{
			t = 0;
			all_move_enemy_help(data, c, t, &valid);
			c++;
		}
		if (l == 20)
			l = 0;
	}
	l++;
	if (data->data_2.check_lose == 1)
		mlx_put_image_to_window(data->data_2.mlx, data->w_n.mlx_win,
			data->l_s.mlx, ((data->m_p.x * 106) - 500) / 2, ((data->m_p.y
					* 106) - 500) / 2);
}

void	check_for_dis_win(t_data *data)
{
	if (data->data_2.check_win == 1)
		mlx_put_image_to_window(data->data_2.mlx, data->w_n.mlx_win,
			data->win.new_door, ((data->m_p.x * 106) - 300) / 2,
			((data->m_p.y * 106) - 200) / 2);
}

int	move(t_data *data)
{
	static int	count;
	static int	i;

	check_for_dis_win(data);
	if (data->data_2.check_win != 1)
	{
		if (count >= 0)
		{
			data->c_o.new_coin = mlx_xpm_file_to_image(data->data_2.mlx,
					data->data_2.ptr[i], &data->width, &data->height);
			mlx_clear_window(data->data_2.mlx, data->w_n.mlx_win);
			display_all_window(9, data);
			if (count == 10)
			{
				count = 0;
				if (i < 5)
					i++;
				else
					i = 0;
			}
		}
		count++;
	}
	move_enemy(data);
	return (1);
}
