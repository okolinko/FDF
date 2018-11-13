/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 17:10:44 by akolinko          #+#    #+#             */
/*   Updated: 2018/10/31 17:10:45 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_is_input(char ch)
{
	int			i;
	char		*test_str;

	i = 0;
	test_str = "0123456789AaBbCcDdEeFf\0";
	while (test_str[i] != '\0')
	{
		if (test_str[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

int			ft_check_color(char *str)
{
	int			i;
	int			j;

	i = 0;
	while (str[i] != ',')
		i++;
	if ((str[i + 1] != '0' && str[i + 2] != 'x') || str[i + 3] == '\0')
		ft_error();
	j = 0;
	while (str[i + 3])
	{
		if (!ft_is_input(str[i + 3]) || j > 6)
			ft_error();
		i++;
		j++;
	}
	return (1);
}

void		ft_input_color(char **str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == ',')
				ft_check_color(str[i]);
			j++;
		}
		i++;
	}
}

int			ft_check(t_shlak *my, char *argv)
{
	int		fd;
	char	*line;
	char	**tab;
	int		check_line;

	check_line = 0;
	if ((fd = open(argv, O_RDONLY)) > 0)
	{
		while (get_next_line(fd, &line) > 0)
		{
			tab = ft_strsplit(line, ' ');
			free(line);
			check_line = ft_len_x(tab);
			if (my->x_len > check_line || my->x_len < check_line)
				ft_error();
			ft_input_color(tab);
			ft_free_matrix(&tab);
		}
	}
	return (1);
}
