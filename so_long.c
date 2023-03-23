/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:11:49 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/04/08 11:11:51 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len_line(char *buffer, int *chec)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] != '\n' && *chec == 0)
			j++;
		else
			*chec = 1;
		i++;
	}
	return (j);
}

int	count_of_line(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			j++;
		i++;
	}
	return (j);
}

t_data	get_wid_hei(t_data data, char *argv)
{
	int			fd;
	int			r;
	int			chec;
	static int	valid;
	char		buffer[2];

	r = 1;
	chec = 0;
	fd = open(argv, O_RDWR);
	if (fd < 0)
		exit (0);
	while (r)
	{
		r = read(fd, buffer, 1);
		if (r == -1)
			exit (1);
		buffer[r] = '\0';
		data.m_p.x += len_line(buffer, &chec);
		data.m_p.y += count_of_line(buffer);
		valid++;
	}
	if (valid > 1)
		data.m_p.y += 1;
	close(fd);
	return (data);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->data_2.mlx, data->w_n.mlx_win);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int		i;

	if (argc != 2)
		return (1);
	i = 0;
	initialize_some_struct(&data);
	check_name_map(argv[1]);
	data = get_wid_hei(data, argv[1]);
	data = get_map_ptr(data, argv[1]);
	check_map(&data);
	check_path(&data, argv[1]);
	data = all_img_con(data);
	display_all_window(9, &data);
	mlx_hook(data.w_n.mlx_win, 2, 0, ft_check_and_display, &data);
	mlx_hook(data.w_n.mlx_win, 17, 0, close_window, &data);
	mlx_loop(data.data_2.mlx);
	return (0);
}
