/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:10:42 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/04/08 11:10:43 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_coins_2(t_data *data, int *count_coins)
{
	if (data->m_p.ptr_2[data->p_l.x][data->p_l.y] == 'C')
	{
		if (data->m_p.ptr_2[data->p_l.x][data->p_l.y + 1] == 'A'
			|| data->m_p.ptr_2[data->p_l.x][data->p_l.y
			+ 1] == 'P')
			*count_coins = *count_coins + 1;
		else if (data->m_p.ptr_2[data->p_l.x][data->p_l.y - 1] == 'A'
				|| data->m_p.ptr_2[data->p_l.x][data->p_l.y - 1] == 'P')
			*count_coins = *count_coins + 1;
		else if (data->m_p.ptr_2[data->p_l.x + 1][data->p_l.y] == 'A'
			|| data->m_p.ptr_2[data->p_l.x
			+ 1][data->p_l.y] == 'P')
			*count_coins = *count_coins + 1;
		else if (data->m_p.ptr_2[data->p_l.x - 1][data->p_l.y] == 'A'
			|| data->m_p.ptr_2[data->p_l.x
			- 1][data->p_l.y] == 'P')
			*count_coins = *count_coins + 1;
	}
}

void	check_found_exit_coin_2(t_data *data, int *valid_3)
{
	if (data->m_p.ptr_2[data->p_l.x][data->p_l.y] == 'C')
	{
		if (data->m_p.ptr_2[data->p_l.x][data->p_l.y + 1] == 'A'
			|| data->m_p.ptr_2[data->p_l.x][data->p_l.y - 1] == 'A'
			|| data->m_p.ptr_2[data->p_l.x + 1][data->p_l.y] == 'A'
			|| data->m_p.ptr_2[data->p_l.x - 1][data->p_l.y] == 'A')
		{
			if (data->m_p.ptr_2[data->p_l.x][data->p_l.y + 1] == '0')
				data->m_p.ptr_2[data->p_l.x][data->p_l.y + 1] = 'A';
			if (data->m_p.ptr_2[data->p_l.x][data->p_l.y - 1] == '0')
				data->m_p.ptr_2[data->p_l.x][data->p_l.y - 1] = 'A';
			if (data->m_p.ptr_2[data->p_l.x + 1][data->p_l.y] == '0')
				data->m_p.ptr_2[data->p_l.x + 1][data->p_l.y] = 'A';
			if (data->m_p.ptr_2[data->p_l.x - 1][data->p_l.y] == '0')
				data->m_p.ptr_2[data->p_l.x - 1][data->p_l.y] = 'A';
		}
		if (data->m_p.ptr_2[data->p_l.x][data->p_l.y] == 'C'
			&& (data->m_p.ptr_2[data->p_l.x][data->p_l.y + 1] == 'E'
				|| data->m_p.ptr_2[data->p_l.x][data->p_l.y - 1] == 'E'
				|| data->m_p.ptr_2[data->p_l.x + 1][data->p_l.y] == 'E'
				|| data->m_p.ptr_2[data->p_l.x - 1][data->p_l.y] == 'E'))
			*valid_3 = 1;
	}
}
