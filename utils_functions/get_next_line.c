/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:10:56 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/04/08 11:10:58 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*con;
	char		*ptr;
	int			r;

	r = 1;
	ptr = 0;
	if (con != NULL)
		ptr = ft_strjoin(con, ptr);
	while (r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0 || fd == 1 || fd == 2)
			break ;
		buf[r] = '\0';
		ptr = ft_strjoin(ptr, buf);
		if (new_line(ptr))
			break ;
	}
	con = get_last_line(ptr);
	return (_get_line(ptr));
}
