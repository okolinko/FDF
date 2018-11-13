/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drav.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:42:43 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/06 14:42:44 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_string_put(t_shlak *my)
{
	mlx_string_put(my->mlx_ptr, my->win_ptr, 18, 30, 0x8ff, "space  - RESET");
	mlx_string_put(my->mlx_ptr, my->win_ptr, 9, 50, 0x8ff, "pU & pD - HEIGHT");
	mlx_string_put(my->mlx_ptr, my->win_ptr, 9, 70, 0x8ff, "<- & -> - L & R");
	mlx_string_put(my->mlx_ptr, my->win_ptr, 9, 90, 0x8ff, "UP & DW - U & D");
	mlx_string_put(my->mlx_ptr, my->win_ptr, 19, 110, 0x8ff, "+ & -  - ZOOM");
}

void	draw_hor(t_shlak *my, t_cord **map_save)
{
	int			i;
	int			j;
	t_coord		cord;

	i = 0;
	if (my->zoom <= 0)
		my->zoom = 1;
	while (i < my->y_len)
	{
		j = 0;
		while (j < my->x_len - 1)
		{
			if ((map_save[i][j].z > 10000) || (map_save[i][j].z < -10000))
				ft_error();
			cord.y1 = (my->f_y - j * my->zoom + i * my->zoom)
			- map_save[i][j].z * my->height;
			cord.y2 = (my->f_y - (j + 1) * my->zoom + i * my->zoom)
			- map_save[i][j + 1].z * my->height;
			cord.x1 = my->f_x + 2 * (j * my->zoom + i * my->zoom);
			cord.x2 = my->f_x + 2 * ((j + 1) * my->zoom + i * my->zoom);
			ft_bresenham(my, cord, map_save[i][j].color);
			j++;
		}
		i++;
	}
}

void	draw_wer(t_shlak *my, t_cord **map_save)
{
	int				x;
	int				l;
	t_coord			cord;

	x = 0;
	while (x < my->x_len)
	{
		l = 0;
		if (my->zoom <= 0)
			my->zoom = 1;
		while (l < my->y_len - 1)
		{
			if ((map_save[l][x].z > 10000) || (map_save[l][x].z < -10000))
				ft_error();
			cord.x1 = my->f_x + 2 * (l * my->zoom + x * my->zoom);
			cord.x2 = my->f_x + 2 * ((l + 1) * my->zoom + x * my->zoom);
			cord.y1 = my->f_y + l * my->zoom - x * my->zoom
			- map_save[l][x].z * my->height;
			cord.y2 = my->f_y + (l + 1) * my->zoom - x * my->zoom
			- map_save[l + 1][x].z * my->height;
			ft_bresenham(my, cord, map_save[l][x].color);
			l++;
		}
		x++;
	}
}

void	ft_drav(t_shlak *my, t_cord **map_save)
{
	mlx_clear_window(my->mlx_ptr, my->win_ptr);
	ft_string_put(my);
	draw_hor(my, map_save);
	draw_wer(my, map_save);
}
