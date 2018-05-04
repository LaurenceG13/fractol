/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 20:28:22 by lagirard          #+#    #+#             */
/*   Updated: 2017/10/31 21:34:53 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_init_mandel(t_param *s, int x, int y)
{
	if (s->zoom_flag == 0)
	{
		s->x1 = -2.1 + s->slide_x;
		s->x2 = 0.6 + s->slide_x;
		s->y1 = -1.2 + s->slide_y;
		s->y2 = 1.2 + s->slide_y;
		if (s->zoom != 0)
		{
			s->image_x = (s->x2 - s->x1) * s->zoom;
			s->image_y = (s->y2 - s->y1) * s->zoom;
		}
	}
	if (s->zoom != 0)
	{
		s->c_r = (x + s->slide_x * s->zoom) / s->zoom + s->x1;
		s->c_i = (y + s->slide_y * s->zoom) / s->zoom + s->y1;
	}
	s->z_r = 0;
	s->z_i = 0;
}

int		ft_compute_mandel(t_param *s, int x, int y)
{
	float	tmp;
	int		i;

	ft_init_mandel(s, x, y);
	i = 0;
	while (s->z_r * s->z_r + s->z_i * s->z_i < 4 && i < s->iter_max)
	{
		tmp = s->z_r;
		s->z_r = s->z_r * s->z_r - s->z_i * s->z_i + s->c_r;
		s->z_i = 2 * s->z_i * tmp + s->c_i;
		i++;
	}
	return (i);
}
