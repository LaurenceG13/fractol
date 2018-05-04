/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 19:49:00 by lagirard          #+#    #+#             */
/*   Updated: 2017/10/31 19:54:22 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_init_struct_bis(t_param *s)
{
	s->zoom_flag = 0;
	s->zoom = 1;
	s->mouse_flag = -1;
	s->mouse_flag_bis = 0;
	s->x_mouse = 0;
	s->y_mouse = 0;
	s->flag_freeze = 0;
	s->c_r_tmp = 0.285;
	s->c_i_tmp = 0.01;
	s->r = 0;
	s->g = 0;
	s->b = 0;
}

void	ft_init_struct(t_param *s)
{
	s->x_win = 0;
	s->y_win = 0;
	s->tmp_pixels = NULL;
	s->size_coord = 0;
	s->mlx = NULL;
	s->win = NULL;
	s->img = NULL;
	s->key = 0;
	s->str_img = NULL;
	s->bpp = 0;
	s->s_l = 0;
	s->endian = 0;
	s->color = 0;
	s->x_min = 0;
	s->x_max = 0;
	s->y_min = 0;
	s->y_max = 0;
	s->keycolor = 5;
	s->slide_x = 0;
	s->slide_y = 0;
}
