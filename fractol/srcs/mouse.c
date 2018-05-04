/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:23:22 by lagirard          #+#    #+#             */
/*   Updated: 2017/10/31 19:53:35 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			ft_mouse(int x_mouse, int y_mouse, t_param *s)
{
	s->x_mouse = x_mouse;
	s->y_mouse = y_mouse;
	if (s->fractal_code == 'j' || s->fractal_code == 'u')
	{
		if (s->flag_freeze == -1)
		{
			s->c_r = s->c_r_tmp;
			s->c_i = s->c_i_tmp;
		}
		else
		{
			if (s->mouse_flag == -1 && x_mouse >= 0 && x_mouse < s->image_x && \
				y_mouse >= 0 && y_mouse < s->image_y)
			{
				s->c_r = cos(x_mouse * 1000 + 1);
				s->c_i = cos(y_mouse * 1000 + 1);
				s->c_r_tmp = s->c_r;
				s->c_i_tmp = s->c_i;
			}
		}
		s->mouse_flag_bis = -1;
		ft_again(s);
	}
	return (0);
}
