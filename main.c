/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 12:14:44 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/01 12:14:45 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_save_list(t_map **save, char **line)
{
	t_map		*temp;
	t_map		*tmp2;

	temp = (t_map *)malloc(sizeof(t_map));
	temp->sssssss = line;
	temp->next = NULL;
	if (*save == NULL)
		*save = temp;
	else
	{
		tmp2 = *save;
		while (tmp2->next != NULL)
			tmp2 = tmp2->next;
		tmp2->next = temp;
	}
}

t_map		*ft_read(char *test_file)
{
	int			fd;
	t_map		*save;
	char		*line;
	char		**tab;

	save = NULL;
	if ((fd = open(test_file, O_RDONLY)) > 0)
	{
		while (get_next_line(fd, &line) > 0)
		{
			tab = ft_strsplit(line, ' ');
			free(line);
			ft_save_list(&save, tab);
		}
	}
	return (save);
}

int			main(int argc, char **argv)
{
	t_map		*read;
	t_shlak		my;

	read = NULL;
	if (argc != 2)
	{
		write(1, "usage: *.fdf file\n", 19);
		return (0);
	}
	my.x_len = ft_long_map(argv[1]);
	if ((ft_check(&my, argv[1])) == 0)
		return (0);
	if (!(read = (ft_read(argv[1]))))
		return (0);
	ft_moving(&my);
	my.arr = ft_save_matrix(read, &my);
	ft_new_window(my.arr, &my);
	return (0);
}
