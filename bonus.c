/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:00:19 by akolinko          #+#    #+#             */
/*   Updated: 2018/10/30 15:00:20 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_moving(t_shlak *my)
{
	my->f_x = 600;
	my->f_y = 650;
	my->zoom = 2;
	my->height = 1;
}

void	ft_standart(t_shlak *my)
{
	my->f_x = 600;
	my->f_y = 650;
	my->zoom = 2;
	my->height = 1;
}
