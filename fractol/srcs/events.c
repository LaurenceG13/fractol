/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 10:05:38 by lagirard          #+#    #+#             */
/*   Updated: 2017/10/31 16:18:00 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_again(t_param *s)
{
	mlx_clear_window(s->mlx, s->win);
	mlx_destroy_image(s->mlx, s->img);
	if (s->fractal_code == 'm')
		ft_fractal_mandel(s);
	else if (s->fractal_code == 'j')
		ft_fractal_julia(s);
	else if (s->fractal_code == 'b')
		ft_fractal_burning(s);
	else if (s->fractal_code == 'u')
		ft_fractal_juju(s);
	else if (s->fractal_code == 't')
		ft_fractal_tricorn(s);
	else if (s->fractal_code == 'r')
		ft_fractal_ror(s);
}

void		ft_reset_all(t_param *s)
{
	s->zoom_flag = 0;
	s->slide_x = 0;
	s->slide_y = 0;
	s->zoom_flag = 0;
	if (s->fractal_code == 'm' || s->fractal_code == 't')
		s->iter_max = 50;
	else if (s->fractal_code == 'j' || s->fractal_code == 'u')
		s->iter_max = 150;
	else if (s->fractal_code == 'b')
		s->iter_max = 100;
	else if (s->fractal_code == 'r')
		s->iter_max = 150;
	s->zoom_flag = 0;
	s->zoom = 200;
	if (s->fractal_code == 'j' || s->fractal_code == 'u')
	{
		s->mouse_flag_bis = 0;
		s->flag_freeze = 0;
		s->c_r_tmp = 0.285;
		s->c_i_tmp = 0.01;
	}
}

int			ft_keycode(int keycode, void *blabla)
{
	t_param	*s;

	s = (t_param *)blabla;
	s->key = keycode;
	if (s->key == 53)
	{
		free(s);
		s = NULL;
		exit(0);
	}
	if (s->key == 36)
	{
		ft_reset_all(s);
		ft_again(s);
	}
	if (keycode == 3 && ((s->fractal_code == 'j' || s->fractal_code == 'u')))
		s->flag_freeze = -1;
	ft_keycode_colors(s);
	ft_keycode_slide(s);
	ft_keycode_vary_itermax(s);
	ft_again(s);
	return (0);
}

int			ft_close(void *blabla)
{
	t_param	*s;

	s = (t_param *)blabla;
	free(s);
	s = NULL;
	exit(1);
	return (0);
}

int			ft_events(t_param *s)
{
	mlx_hook(s->win, 17, 0L, ft_close, s);
	mlx_hook(s->win, 2, 2, ft_keycode, s);
	mlx_hook(s->win, 4, 0, ft_zoom, s);
	if (s->fractal_code == 'j' || s->fractal_code == 'u')
		mlx_hook(s->win, 6, 0, ft_mouse, s);
	return (0);
}
