/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_and_display_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:10:08 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/04/08 11:10:10 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	go_right(t_data *data)
{
	mlx_clear_window(data->data_2.mlx, data->w_n.mlx_win);
	go_right_2(data);
	if (data->m_p.ptr[data->p_l.y][data->p_l.x + 1] == 'M')
	{
		data->p_l.count_move += 1;
		data->m_p.ptr[data->p_l.y][data->p_l.x] = '0';
		data->data_2.check_lose = 1;
		data->check = 2;
	}
	else if (data->m_p.ptr[data->p_l.y][data->p_l.x + 1] == 'E'
			&& data->just_one_coin == data->data_2.sum_coin)
	{
		data->data_2.check_win = 1;
		data->p_l.count_move += 1;
		data->m_p.ptr[data->p_l.y][data->p_l.x] = '0';
		return (1);
	}
	return (0);
}

int	go_top(t_data *data)
{
	mlx_clear_window(data->data_2.mlx, data->w_n.mlx_win);
	go_top_2(data);
	if (data->m_p.ptr[data->p_l.y - 1][data->p_l.x] == 'M')
	{
		data->p_l.count_move += 1;
		data->m_p.ptr[data->p_l.y][data->p_l.x] = '0';
		data->data_2.check_lose = 1;
		data->check = 2;
	}
	else if (data->m_p.ptr[data->p_l.y - 1][data->p_l.x] == 'E'
		&& data->just_one_coin == data->data_2.sum_coin)
	{
		data->data_2.check_win = 1;
		data->p_l.count_move += 1;
		data->m_p.ptr[data->p_l.y][data->p_l.x] = '0';
		return (1);
	}
	return (0);
}

int	go_left(t_data *data)
{
	mlx_clear_window(data->data_2.mlx, data->w_n.mlx_win);
	go_left_2(data);
	if (data->m_p.ptr[data->p_l.y][data->p_l.x - 1] == 'M')
	{
		data->p_l.count_move += 1;
		data->m_p.ptr[data->p_l.y][data->p_l.x] = '0';
		data->data_2.check_lose = 1;
		data->check = 2;
	}
	else if (data->m_p.ptr[data->p_l.y][data->p_l.x - 1] == 'E'
			&& data->just_one_coin == data->data_2.sum_coin)
	{
		data->data_2.check_win = 1;
		data->p_l.count_move += 1;
		data->m_p.ptr[data->p_l.y][data->p_l.x] = '0';
		return (1);
	}
	return (0);
}

int	go_down(t_data *data)
{
	mlx_clear_window(data->data_2.mlx, data->w_n.mlx_win);
	go_down_2(data);
	if (data->m_p.ptr[data->p_l.y + 1][data->p_l.x] == 'M')
	{
		data->p_l.count_move += 1;
		data->m_p.ptr[data->p_l.y][data->p_l.x] = '0';
		data->data_2.check_lose = 1;
		data->check = 2;
	}
	else if (data->m_p.ptr[data->p_l.y + 1][data->p_l.x] == 'E'
			&& data->just_one_coin == data->data_2.sum_coin)
	{
		data->p_l.count_move += 1;
		data->data_2.check_win = 1;
		data->m_p.ptr[data->p_l.y][data->p_l.x] = '0';
		return (1);
	}
	return (0);
}

int	ft_check_and_display(int keycode, t_data *data)
{
	int	k;

	if (keycode == 53)
	{
		mlx_destroy_window(data->data_2.mlx, data->w_n.mlx_win);
		exit(0);
	}
	k = 0;
	if (keycode == 2 && data->check != 2)
	{
		if (go_right(data))
			k = 1;
		display_all_window(keycode, data);
		if (k == 1)
		{
			mlx_put_image_to_window(data->data_2.mlx, data->w_n.mlx_win,
				data->win.new_door, ((data->m_p.x * 106) - 300) / 2,
				((data->m_p.y * 106) - 200) / 2);
			data->check = 2;
		}
	}
	else if (keycode == 13 && data->check != 2)
		ft_check_and_display_2(data, keycode, &k);
	ft_check_and_display_3(data, keycode);
	return (0);
}
