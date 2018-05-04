/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:19:17 by lagirard          #+#    #+#             */
/*   Updated: 2017/10/31 16:22:46 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_zoom_plus(t_param *s)
{
	float	tmp_zoom;

	s->zoom_flag = 1;
	tmp_zoom = s->zoom;
	s->zoom = s->zoom * 1.2;
	s->iter_max += 5;
	s->x1 += (s->mouse_x / tmp_zoom) - (s->mouse_x / s->zoom);
	s->y1 += (s->mouse_y / tmp_zoom) - (s->mouse_y / s->zoom);
}

void	ft_zoom_less(t_param *s)
{
	float	tmp_zoom;

	s->zoom_flag = -1;
	tmp_zoom = s->zoom;
	s->zoom = s->zoom / 1.2;
	s->iter_max -= 5;
	s->x1 += (s->mouse_x / tmp_zoom) - (s->mouse_x / s->zoom);
	s->y1 += (s->mouse_y / tmp_zoom) - (s->mouse_y / s->zoom);
}

int		ft_zoom(int button, int x, int y, t_param *s)
{
	if (button == 5)
	{
		s->mouse_x = x;
		s->mouse_y = y;
		ft_zoom_plus(s);
		ft_again(s);
	}
	if (button == 4)
	{
		s->mouse_x = x;
		s->mouse_y = y;
		ft_zoom_less(s);
		ft_again(s);
	}
	return (0);
}
