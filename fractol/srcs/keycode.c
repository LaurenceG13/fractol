/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:36:08 by lagirard          #+#    #+#             */
/*   Updated: 2017/10/31 16:36:14 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_keycode_vary_itermax(t_param *s)
{
	if (s->key == 69)
		s->iter_max += 10;
	if (s->key == 78)
		s->iter_max -= 10;
}

void		ft_keycode_colors(t_param *s)
{
	if (s->key == 83)
		s->keycolor = 1;
	if (s->key == 84)
		s->keycolor = 2;
	if (s->key == 85)
		s->keycolor = 3;
	if (s->key == 86)
		s->keycolor = 4;
	if (s->key == 87)
		s->keycolor = 5;
	if (s->key == 88)
		s->keycolor = 6;
	if (s->key == 89)
		s->keycolor = 7;
	if (s->key == 91)
		s->keycolor = 8;
	if (s->key == 92)
		s->keycolor = 9;
}

void		ft_keycode_slide(t_param *s)
{
	if (s->key == 123)
		s->slide_x += 0.02;
	if (s->key == 124)
		s->slide_x -= 0.02;
	if (s->key == 126)
		s->slide_y += 0.02;
	if (s->key == 125)
		s->slide_y -= 0.02;
}
