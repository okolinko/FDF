/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:22:57 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/05 15:23:41 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_free_matrix(char ***str)
{
	int i;

	i = -1;
	while ((*str)[++i])
	{
		free((*str)[i]);
		(*str)[i] = NULL;
	}
	free(*str);
	*str = NULL;
}

int				ft_len_x(char **str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

int				ft_long_map(char *argv)
{
	int			fd;
	char		*line;
	char		**tab;
	int			len;

	len = 0;
	if ((fd = open(argv, O_RDONLY)) < 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	else
	{
		if (get_next_line(fd, &line) > 0)
		{
			tab = ft_strsplit(line, ' ');
			free(line);
			len = ft_len_x(tab);
			ft_free_matrix(&tab);
		}
		if (len <= 0)
			ft_error();
	}
	return (len);
}
