/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rorschach_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 23:21:01 by lagirard          #+#    #+#             */
/*   Updated: 2017/11/01 12:39:07 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_init_ror(t_param *s, int x, int y)
{
	if (s->zoom_flag == 0)
	{
		s->x1 = -1 + s->slide_x;
		s->x2 = 1 + s->slide_x;
		s->y1 = -1.2 + s->slide_y;
		s->y2 = 1.2 + s->slide_y;
		if (s->zoom != 0)
		{
			s->image_x = (s->x2 - s->x1) * (s->zoom * 1.2);
			s->image_y = (s->y2 - s->y1) * s->zoom;
		}
	}
	s->c_r = 1;
	s->c_i = 1;
	if (s->zoom != 0)
	{
		s->z_r = (x + s->slide_x * s->zoom) / s->zoom + s->x1;
		s->z_i = (y + s->slide_y * s->zoom) / s->zoom + s->y1;
	}
}

int		ft_compute_ror(t_param *s, int x, int y)
{
	float	tmp;
	int		i;

	ft_init_ror(s, x, y);
	i = 0;
	while (s->z_r * s->z_r + s->z_i * s->z_i < 4 && i < s->iter_max)
	{
		tmp = fabs(s->z_r);
		s->z_r = s->z_r * s->z_r - s->z_i * s->z_i - s->c_r;
		s->z_i = 2 * s->z_i * tmp - s->c_i;
		i++;
	}
	return (i);
}
