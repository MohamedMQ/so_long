/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_and_display_3_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:09:18 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/04/08 11:09:19 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	go_right_2(t_data *data)
{
	if (data->m_p.ptr[data->p_l.y][data->p_l.x + 1] == '0')
	{
		data->p_l.count_move += 1;
		data->m_p.ptr[data->p_l.y][data->p_l.x] = '0';
		data->m_p.ptr[data->p_l.y][data->p_l.x + 1] = 'P';
	}
	else if (data->m_p.ptr[data->p_l.y][data->p_l.x + 1] == 'C')
	{
		data->p_l.count_move += 1;
		data->m_p.ptr[data->p_l.y][data->p_l.x] = '0';
		data->m_p.ptr[data->p_l.y][data->p_l.x + 1] = 'P';
		data->just_one_coin += 1;
	}
}

void	go_top_2(t_data *data)
{
	if (data->m_p.ptr[data->p_l.y - 1][data->p_l.x] == '0')
	{
		data->p_l.count_move += 1;
		data->m_p.ptr[data->p_l.y][data->p_l.x] = '0';
		data->m_p.ptr[data->p_l.y - 1][data->p_l.x] = 'P';
	}
	else if (data->m_p.ptr[data->p_l.y - 1][data->p_l.x] == 'C')
	{
		data->p_l.count_move += 1;
		data->m_p.ptr[data->p_l.y][data->p_l.x] = '0';
		data->m_p.ptr[data->p_l.y - 1][data->p_l.x] = 'P';
		data->just_one_coin += 1;
	}
}

void	go_left_2(t_data *data)
{
	if (data->m_p.ptr[data->p_l.y][data->p_l.x - 1] == '0')
	{
		data->p_l.count_move += 1;
		data->m_p.ptr[data->p_l.y][data->p_l.x] = '0';
		data->m_p.ptr[data->p_l.y][data->p_l.x - 1] = 'P';
	}
	else if (data->m_p.ptr[data->p_l.y][data->p_l.x - 1] == 'C')
	{
		data->p_l.count_move += 1;
		data->m_p.ptr[data->p_l.y][data->p_l.x] = '0';
		data->m_p.ptr[data->p_l.y][data->p_l.x - 1] = 'P';
		data->just_one_coin += 1;
	}
}

void	go_down_2(t_data *data)
{
	if (data->m_p.ptr[data->p_l.y + 1][data->p_l.x] == '0')
	{
		data->p_l.count_move += 1;
		data->m_p.ptr[data->p_l.y][data->p_l.x] = '0';
		data->m_p.ptr[data->p_l.y + 1][data->p_l.x] = 'P';
	}
	else if (data->m_p.ptr[data->p_l.y + 1][data->p_l.x] == 'C')
	{
		data->p_l.count_move += 1;
		data->m_p.ptr[data->p_l.y][data->p_l.x] = '0';
		data->m_p.ptr[data->p_l.y + 1][data->p_l.x] = 'P';
		data->just_one_coin += 1;
	}
}
