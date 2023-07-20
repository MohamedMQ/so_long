/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:11:14 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/04/08 11:11:15 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fast_check_2(int j, int *long_line, int *valid, t_data *data)
{
	if (*valid == 0)
		*long_line = j;
	else if (*valid > 0 && *long_line != j)
		eroor_map(data);
	*valid = *valid + 1;
}

void	fast_check_1(t_data *data)
{
	int	i;
	int	j;
	int	valid;
	int	valid_2;

	valid = 0;
	valid_2 = 0;
	i = 0;
	while (data->m_p.ptr[i])
	{
		j = 0;
		while (data->m_p.ptr[i][j] != '\n' && data->m_p.ptr[i][j] != '\0')
		{
			if (data->m_p.ptr[i][j] == 'P')
				valid++;
			if (data->m_p.ptr[i][j] == 'E')
				valid_2++;
			fast_check_1_1(data, i, j);
			j++;
		}
		i++;
	}
	if (valid != 1 || valid_2 != 1)
		eroor_map(data);
}

void	fast_check_3(t_data *data)
{
	int	i;
	int	j;
	int	stock;

	i = 0;
	stock = data->m_p.y - 1;
	while (data->m_p.ptr[i])
	{
		j = 0;
		while (data->m_p.ptr[i][j] != '\n' && data->m_p.ptr[i][j] != '\0')
		{
			if ((data->m_p.ptr[i][j] != '1' && i == 0)
				|| (data->m_p.ptr[i][j] != '1' && i == stock))
				eroor_map(data);
			if (data->m_p.ptr[i][0] != '1' || data->m_p.ptr[i][data->m_p.x
				- 1] != '1')
				eroor_map(data);
			j++;
		}
		i++;
	}
}

void	fast_check_4(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->m_p.ptr[i])
	{
		j = 0;
		while (data->m_p.ptr[i][j] != '\n' && data->m_p.ptr[i][j] != '\0')
		{
			if (data->m_p.ptr[i][j] == 'C')
				data->data_2.sum_coin += 1;
			j++;
		}
		i++;
	}
}

void	check_map(t_data *data)
{
	int	i;
	int	j;
	int	valid;
	int	long_line;

	valid = 0;
	i = 0;
	fast_check_1(data);
	while (data->m_p.ptr[i])
	{
		j = 0;
		while (data->m_p.ptr[i][j] != '\n' && data->m_p.ptr[i][j] != '\0')
			j++;
		fast_check_2(j, &long_line, &valid, data);
		i++;
	}
	if (data->m_p.ptr[i - 1][j] == '\n')
		eroor_map(data);
	fast_check_3(data);
	fast_check_4(data);
}
