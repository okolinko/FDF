/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 13:49:00 by akolinko          #+#    #+#             */
/*   Updated: 2018/09/20 13:49:02 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "mlx.h"

# define HEIGHT 2200
# define WIDTH 1320

typedef struct		s_map
{
	char			**sssssss;
	struct s_map	*next;
}					t_map;

typedef struct		s_cord
{
	int				z;
	int				color;

}					t_cord;

typedef struct		s_coord
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				dx;
	int				dy;
	int				sx;
	int				sy;

}					t_coord;

typedef struct		s_shlak
{
	int				x_len;
	int				y_len;
	int				f_x;
	int				f_y;
	int				zoom;
	int				height;
	void			*mlx_ptr;
	void			*win_ptr;
	t_cord			**arr;

}					t_shlak;

t_cord				**ft_save_matrix(t_map *read, t_shlak *my);
int					ft_long_map(char *argv);
void				ft_save_list(t_map **save, char **line);
t_map				*ft_read(char *test_file);
void				ft_new_window(t_cord **map_save, t_shlak *my);
void				ft_bresenham(t_shlak *my, t_coord coord, int color);
void				ft_moving(t_shlak *my);
int					ft_check(t_shlak *my, char *argv);
void				ft_error(void);
int					ft_len_x(char **str);
int					ft_atoi_base(char *str, int str_base);
void				ft_drav(t_shlak *my, t_cord **map_save);
void				ft_string_put(t_shlak *my);
void				ft_standart(t_shlak *my);
void				ft_free_matrix(char ***str);

#endif
