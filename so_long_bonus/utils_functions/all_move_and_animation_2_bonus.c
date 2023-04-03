/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_move_and_animation_2_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 10:35:58 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/04/08 10:36:00 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	move_enemy_help_1(t_data *data, int c, int t)
{
	if (data->m_p.ptr[c][t + 1] == 'P')
	{
		data->check = 2;
		data->data_2.check_lose = 1;
	}
	data->m_p.ptr[c][t] = '0';
	data->m_p.ptr[c][t + 1] = 'M';
}

void	move_enemy_help_2(t_data *data, int c, int t)
{
	if (data->m_p.ptr[c][t - 1] == 'P')
	{
		data->check = 2;
		data->data_2.check_lose = 1;
	}
	data->m_p.ptr[c][t] = '0';
	data->m_p.ptr[c][t - 1] = 'M';
}
