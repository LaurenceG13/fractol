/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:50:55 by lagirard          #+#    #+#             */
/*   Updated: 2017/10/28 19:35:19 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_nb_points_julia(t_param *s)
{
	int		x;
	int		y;
	int		point;

	x = 0;
	y = 0;
	ft_init_julia(s, x, y);
	point = 0;
	x = 0;
	while (x < s->image_x)
	{
		y = 0;
		while (y < s->image_y)
		{
			if (ft_compute_julia(s, x, y) != s->iter_max)
			{
				ft_init_xy(s, x, y);
				point = point + 1;
			}
			y++;
		}
		x++;
	}
	return (point);
}

int		ft_coord_julia_bis(t_param *s, int point, int x, int y)
{
	int		i;
	int		p;

	i = ft_compute_julia(s, x, y);
	p = point;
	if (i != s->iter_max)
	{
		s->tmp_pixels[p][0] = x;
		s->tmp_pixels[p][1] = y;
		ft_init_colors_julia(s, i);
		s->tmp_pixels[p][2] = s->r;
		s->tmp_pixels[p][3] = s->g;
		s->tmp_pixels[p][4] = s->b;
		ft_init_xy(s, x, y);
		p = p + 1;
	}
	return (p);
}

int		ft_coord_julia(t_param *s)
{
	int		x;
	int		y;
	int		point;

	x = 0;
	y = 0;
	s->size_coord = ft_nb_points_julia(s);
	ft_init_julia(s, x, y);
	if (!(s->tmp_pixels = ft_memalloc_tab_float(s->size_coord, 5)))
		return (ft_error_malloc_tab());
	point = 0;
	x = 0;
	while (x < s->image_x)
	{
		y = 0;
		while (y < s->image_y)
		{
			point = ft_coord_julia_bis(s, point, x, y);
			y++;
		}
		x++;
	}
	return (0);
}

int		ft_fractal_julia(t_param *s)
{
	char *str;

	if (ft_coord_julia(s) == 1)
	{
		ft_putendl("ERROR ft_coord");
		return (1);
	}
	if (!(s->img = mlx_new_image(s->mlx, s->x_win, s->y_win)))
		return (ft_error_malloc_minilib());
	if (!(s->str_img = (int *)mlx_get_data_addr(s->img, &(s->bpp), &(s->s_l), \
	&(s->endian))))
		return (ft_error_malloc_minilib());
	ft_put_tab_to_img(s);
	ft_free_tab_float(s->tmp_pixels, s->size_coord);
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	mlx_string_put(s->mlx, s->win, 5, 5, 0X00FFFFFF, "JULIA");
	mlx_string_put(s->mlx, s->win, 80, 5, 0X00FFFFFF, "imax: ");
	str = ft_itoa(s->iter_max);
	mlx_string_put(s->mlx, s->win, 145, 5, 0X00FFFFFF, str);
	free(str);
	return (0);
}

int		ft_julia(void)
{
	t_param	*s;

	if (!(s = (t_param *)ft_memalloc(sizeof(t_param))))
		return (ft_error_malloc_struct());
	s->fractal_code = 'j';
	ft_init_struct(s);
	s->keycolor = 8;
	s->iter_max = 150;
	s->zoom_flag = 0;
	s->zoom = 200;
	s->mouse_flag = -1;
	ft_nb_points_julia(s);
	s->x_win = (s->x_max - s->x_min + 1);
	s->y_win = (s->y_max - s->y_min + 1);
	if (!(s->mlx = mlx_init()))
		return (ft_error_malloc_minilib());
	if (!(s->win = mlx_new_window(s->mlx, s->x_win, s->y_win, "Fractol")))
		return (ft_error_malloc_minilib());
	if (ft_fractal_julia(s) == 1)
		return (1);
	ft_events(s);
	mlx_loop(s->mlx);
	return (0);
}
