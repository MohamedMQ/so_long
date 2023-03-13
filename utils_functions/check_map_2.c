/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:10:38 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/04/08 11:10:39 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fast_check_1_1(t_data *data, int i, int j)
{
	int	empty;

	if (data->m_p.ptr[i][j] == 'E' || data->m_p.ptr[i][j] == 'P'
		|| data->m_p.ptr[i][j] == '1' || data->m_p.ptr[i][j] == '0'
		|| data->m_p.ptr[i][j] == 'C')
		empty = 0;
	else
		eroor_map(data);
}
