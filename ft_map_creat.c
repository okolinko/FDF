/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_creat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:12:32 by akolinko          #+#    #+#             */
/*   Updated: 2018/10/22 12:12:33 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_list_len(t_map *read)
{
	int		i;

	i = 0;
	while (read != NULL)
	{
		read = read->next;
		i++;
	}
	return (i);
}

void			ft_map_creat(t_cord **map_save, t_map *read, t_shlak *my)
{
	int		x_ln;
	int		y_up;

	y_up = 0;
	while (my->y_len > y_up)
	{
		x_ln = 0;
		while (my->x_len > x_ln)
		{
			map_save[y_up][x_ln].z = ft_atoi(read->sssssss[x_ln]);
			map_save[y_up][x_ln].color =
			ft_atoi_base((ft_strchr(read->sssssss[x_ln], ',')), 16);
			x_ln++;
		}
		y_up++;
		read = read->next;
	}
}

t_cord			**ft_save_matrix(t_map *read, t_shlak *my)
{
	int			i;
	t_cord		**map_save;

	my->y_len = ft_list_len(read);
	if (!(map_save = (t_cord **)malloc(my->y_len * sizeof(t_cord *))))
		return (0);
	i = 0;
	while (i < my->y_len)
	{
		if (!(map_save[i] = (t_cord *)malloc(my->x_len * sizeof(t_cord))))
			return (0);
		i++;
	}
	ft_map_creat(map_save, read, my);
	return (map_save);
}
