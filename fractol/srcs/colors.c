/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 09:48:22 by lagirard          #+#    #+#             */
/*   Updated: 2017/10/31 19:46:01 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_convert_rgb_to_hexa(int r, int g, int b)
{
	int		hexa;

	hexa = ((r & 0xff) << 16) + ((g & 0xff) << 8) + ((b & 0xff) << 0);
	return (hexa);
}

void	ft_init_colors_psy(t_param *s, int i)
{
	if (s->keycolor == 1)
	{
		s->r = i * 255 / s->iter_max;
		s->g = (i * i) * 255 / s->iter_max;
		s->b = (i * 3) * 125 / s->iter_max;
	}
	if (s->keycolor == 2)
	{
		s->g = i * 255 / s->iter_max;
		s->b = (i * i) * 255 / s->iter_max;
		s->r = (i * 3) * 125 / s->iter_max;
	}
	if (s->keycolor == 3)
	{
		s->b = i * 255 / s->iter_max;
		s->r = (i * i) * 255 / s->iter_max;
		s->g = (i * 3) * 125 / s->iter_max;
	}
}

void	ft_init_colors_electric(t_param *s, int i)
{
	if (s->keycolor == 7)
	{
		s->b = (i - 10) * 63 / s->iter_max;
		s->r = (i - 20) * (i - 10) * 255 / s->iter_max;
		s->g = (i - 30) * (i - 20) * (i - 10) * 128 / s->iter_max;
	}
	if (s->keycolor == 8)
	{
		s->r = (i - 10) * 63 / s->iter_max;
		s->g = (i - 20) * (i - 10) * 255 / s->iter_max;
		s->b = (i - 30) * (i - 20) * (i - 10) * 128 / s->iter_max;
	}
	if (s->keycolor == 9)
	{
		s->g = (i - 10) * 63 / s->iter_max;
		s->b = (i - 20) * (i - 10) * 255 / s->iter_max;
		s->r = (i - 30) * (i - 20) * (i - 10) * 128 / s->iter_max;
	}
}

void	ft_init_colors_julia(t_param *s, int i)
{
	ft_init_colors_psy(s, i);
	if (s->keycolor == 4)
	{
		s->r = cos(i + 1) * 255;
		s->g = -sin(i + 1) * 255;
		s->b = -cos(i + 1) * 255;
	}
	if (s->keycolor == 5)
	{
		s->r = cos(i + 1) * 75;
		s->g = -sin(i * i + 1) * 75;
		s->b = -cos(i * i * i + 1) * 75;
	}
	if (s->keycolor == 6)
	{
		s->r = cos(i + 1) * 310;
		s->g = -sin(i + 1) * 310;
		s->b = -cos(i + 1) * 310;
	}
	ft_init_colors_electric(s, i);
}

void	ft_init_colors_burning(t_param *s, int i)
{
	ft_init_colors_psy(s, i);
	if (s->keycolor == 4)
	{
		s->r = i * 255 / s->iter_max;
		s->g = (i + 20) * 255 / s->iter_max;
		s->b = (i - 20) * 255 / s->iter_max;
	}
	if (s->keycolor == 5)
	{
		s->g = i * 255 / s->iter_max;
		s->b = (i + 20) * 255 / s->iter_max;
		s->r = (i - 20) * 255 / s->iter_max;
	}
	if (s->keycolor == 6)
	{
		s->b = i * 255 / s->iter_max;
		s->r = (i + 20) * 255 / s->iter_max;
		s->g = (i - 20) * 255 / s->iter_max;
	}
	ft_init_colors_electric(s, i);
}
