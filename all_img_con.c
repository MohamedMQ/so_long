/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_img_con.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:11:09 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/04/08 11:11:10 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	all_img_con_2(t_data data)
{
	data.w_n.img_bg = "./textures/BG.XPM";
	data.p_l.img_player = "./textures/player.XPM";
	data.p_l.img_player_2 = "./textures/player_2.XPM";
	data.b_x.img_box = "./textures/box.XPM";
	data.c_o.img_coin = "./textures/coin3.XPM";
	data.d_r.img_door = "./textures/door.XPM";
	data.win.img_door = "./textures/win.XPM";
	data.floor.img_floor = "./textures/floor.XPM";
	return (data);
}

t_data	all_img_con(t_data data)
{
	data = all_img_con_2(data);
	data.p_l.count_move = 0;
	data.data_2.mlx = mlx_init();
	data.w_n.mlx_win = mlx_new_window(data.data_2.mlx, 106 * data.m_p.x, 106
			* data.m_p.y, "hello word");
	data.w_n.new_bg = mlx_xpm_file_to_image(data.data_2.mlx, data.w_n.img_bg,
			&data.width, &data.height);
	data.p_l.new_player = mlx_xpm_file_to_image(data.data_2.mlx,
			data.p_l.img_player, &data.width, &data.height);
	data.p_l.new_player_2 = mlx_xpm_file_to_image(data.data_2.mlx,
			data.p_l.img_player_2, &data.width, &data.height);
	data.b_x.new_box = mlx_xpm_file_to_image(data.data_2.mlx, data.b_x.img_box,
			&data.width, &data.height);
	data.c_o.new_coin = mlx_xpm_file_to_image(data.data_2.mlx,
			data.c_o.img_coin, &data.width, &data.height);
	data.d_r.new_door = mlx_xpm_file_to_image(data.data_2.mlx,
			data.d_r.img_door, &data.width, &data.height);
	data.win.new_door = mlx_xpm_file_to_image(data.data_2.mlx,
			data.win.img_door, &data.width, &data.height);
	data.floor.mlx = mlx_xpm_file_to_image(data.data_2.mlx,
			data.floor.img_floor, &data.width, &data.height);
	display_empty_space(&data);
	return (data);
}
