/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 18:12:51 by akolinko          #+#    #+#             */
/*   Updated: 2018/10/24 18:12:53 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_shlak *my)
{
	if (key == 0X35)
		exit(1);
	else if (key == 0X45)
		my->zoom++;
	else if (key == 0X4E)
		my->zoom--;
	else if (key == 0X7C)
		my->f_x = my->f_x + 10;
	else if (key == 0X7B)
		my->f_x = my->f_x - 10;
	else if (key == 0X7E)
		my->f_y = my->f_y - 10;
	else if (key == 0X7D)
		my->f_y = my->f_y + 10;
	else if (key == 0X74)
		my->height++;
	else if (key == 0X79)
		my->height--;
	else if (key == 0X31)
		ft_standart(my);
	else
		return (1);
	ft_drav(my, ((my->arr)));
	return (0);
}

void	ft_new_window(t_cord **map_save, t_shlak *my)
{
	my->mlx_ptr = mlx_init();
	my->win_ptr = mlx_new_window(my->mlx_ptr, HEIGHT, WIDTH, "FDF_42");
	mlx_hook(my->win_ptr, 2, 5, deal_key, my);
	ft_drav(my, map_save);
	mlx_loop(my->mlx_ptr);
}
