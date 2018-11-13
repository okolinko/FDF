/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhaim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:08:59 by akolinko          #+#    #+#             */
/*   Updated: 2018/10/24 17:09:01 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_abs(int x)
{
	return (x > 0 ? x : -(x));
}

void	ft_bresenham_dy(void *mlx_ptr, void *win_ptr, t_coord coord, int color)
{
	int	const	d2 = (coord.dx - coord.dy) << 1;
	int	const	d1 = coord.dx << 1;
	int			d;
	int			i;

	mlx_pixel_put(mlx_ptr, win_ptr, coord.x1, coord.y1, color);
	i = 0;
	d = d1 - coord.dy;
	while (++i <= coord.dy)
	{
		coord.y1 += coord.sy;
		if (d > 0)
		{
			d += d2;
			coord.x1 += coord.sx;
		}
		else
			d += d1;
		mlx_pixel_put(mlx_ptr, win_ptr, coord.x1, coord.y1, color);
	}
}

void	ft_bresenham_dx(void *mlx_ptr, void *win_ptr, t_coord coord, int color)
{
	int const	d2 = (coord.dy - coord.dx) << 1;
	int const	d1 = coord.dy << 1;
	int			d;
	int			i;

	mlx_pixel_put(mlx_ptr, win_ptr, coord.x1, coord.y1, color);
	i = 0;
	d = d1 - coord.dx;
	while (++i <= coord.dx)
	{
		coord.x1 += coord.sx;
		if (d > 0)
		{
			d += d2;
			coord.y1 += coord.sy;
		}
		else
			d += d1;
		mlx_pixel_put(mlx_ptr, win_ptr, coord.x1, coord.y1, color);
	}
}

void	ft_bresenham(t_shlak *my, t_coord coord, int color)
{
	coord.dx = ft_abs(coord.x2 - coord.x1);
	coord.dy = ft_abs(coord.y2 - coord.y1);
	coord.sx = (coord.x2 >= coord.x1 ? 1 : -1);
	coord.sy = (coord.y2 >= coord.y1 ? 1 : -1);
	if (coord.dy <= coord.dx)
		ft_bresenham_dx(my->mlx_ptr, my->win_ptr, coord, color);
	else
		ft_bresenham_dy(my->mlx_ptr, my->win_ptr, coord, color);
}
