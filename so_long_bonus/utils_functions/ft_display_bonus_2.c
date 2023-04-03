/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_bonus_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:09:23 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/04/08 11:09:25 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	display_all_window_2_2(t_data *data, int keycode, int i, int j)
{
	if (data->m_p.ptr[i][j] == '1')
		mlx_put_image_to_window(data->data_2.mlx, data->w_n.mlx_win,
			data->b_x.new_box, j * 106, i * 106);
	if (data->m_p.ptr[i][j] == 'P')
	{
		print_position(keycode, data, i, j);
		data->p_l.y = i;
		data->p_l.x = j;
	}
	if (data->m_p.ptr[i][j] == 'C')
		mlx_put_image_to_window(data->data_2.mlx, data->w_n.mlx_win,
			data->c_o.new_coin, j * 106, i * 106);
}
