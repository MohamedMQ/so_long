/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:10:04 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/04/08 11:10:05 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_found_exit_coin(t_data *data, int *valid_3, int *found_0)
{
	if (data->m_p.ptr_2[data->p_l.x][data->p_l.y] == 'P'
		|| data->m_p.ptr_2[data->p_l.x][data->p_l.y] == 'A')
	{
		if (data->m_p.ptr_2[data->p_l.x][data->p_l.y + 1] == '0'
			|| data->m_p.ptr_2[data->p_l.x][data->p_l.y - 1] == '0'
			|| data->m_p.ptr_2[data->p_l.x + 1][data->p_l.y] == '0'
			|| data->m_p.ptr_2[data->p_l.x - 1][data->p_l.y] == '0')
			*found_0 = 1;
		if (data->m_p.ptr_2[data->p_l.x][data->p_l.y + 1] == '0')
			data->m_p.ptr_2[data->p_l.x][data->p_l.y + 1] = 'A';
		if (data->m_p.ptr_2[data->p_l.x][data->p_l.y - 1] == '0')
			data->m_p.ptr_2[data->p_l.x][data->p_l.y - 1] = 'A';
		if (data->m_p.ptr_2[data->p_l.x + 1][data->p_l.y] == '0')
			data->m_p.ptr_2[data->p_l.x + 1][data->p_l.y] = 'A';
		if (data->m_p.ptr_2[data->p_l.x - 1][data->p_l.y] == '0')
			data->m_p.ptr_2[data->p_l.x - 1][data->p_l.y] = 'A';
		if (data->m_p.ptr_2[data->p_l.x][data->p_l.y + 1] == 'E'
			|| data->m_p.ptr_2[data->p_l.x][data->p_l.y - 1] == 'E'
			|| data->m_p.ptr_2[data->p_l.x + 1][data->p_l.y] == 'E'
			|| data->m_p.ptr_2[data->p_l.x - 1][data->p_l.y] == 'E')
			*valid_3 = 1;
	}
	check_found_exit_coin_2(data, valid_3);
}

void	if_exit_or_contune(int *found_0, int *i)
{
	if (*found_0 == 1)
	{
		*i = 0;
		*found_0 = 0;
	}
}

void	check_coins_(t_data *data)
{
	int	i;
	int	j;
	int	count_coins;

	i = 0;
	j = 0;
	count_coins = 0;
	while (data->m_p.ptr_2[i])
	{
		j = 0;
		while (data->m_p.ptr_2[i][j] != '\0')
		{
			data->p_l.x = i;
			data->p_l.y = j;
			check_coins_2(data, &count_coins);
			j++;
		}
		i++;
	}
	if (count_coins != data->data_2.sum_coin)
		eroor_map(data);
	if (count_coins < 1)
		eroor_map(data);
}

void	stock_path(t_data *data)
{
	int	i;
	int	j;
	int	found_0;
	int	valid_3;

	i = 0;
	valid_3 = 0;
	found_0 = 0;
	data->data_2.sum_in_map = 0;
	while (data->m_p.ptr_2[i])
	{
		j = 0;
		while (data->m_p.ptr_2[i][j] != '\0')
		{
			data->p_l.x = i;
			data->p_l.y = j;
			check_found_exit_coin(data, &valid_3, &found_0);
			j++;
		}
		if_exit_or_contune(&found_0, &i);
		i++;
	}
	if (valid_3 != 1)
		eroor_map(data);
}

void	check_path(t_data *data, char *argv)
{
	int	i;
	int	fd;

	i = 0;
	data->m_p.ptr_2 = (char **)malloc((data->m_p.y + 1) * sizeof(char *));
	fd = open(argv, O_RDWR);
	if (fd < 0)
	{
		free(data->m_p.ptr);
		free(data->m_p.ptr_2);
		exit (1);
	}
	while (i < data->m_p.y)
		data->m_p.ptr_2[i++] = get_next_line(fd);
	data->m_p.ptr_2[data->m_p.y] = 0;
	close(fd);
	stock_path(data);
	check_coins_(data);
}
