/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:30:34 by lagirard          #+#    #+#             */
/*   Updated: 2017/10/31 16:29:04 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

typedef struct	s_param
{
	float		x1;
	float		y1;
	float		x2;
	float		y2;
	float		zoom;
	float		image_x;
	float		image_y;
	float		c_r;
	float		c_i;
	float		z_r;
	float		z_i;
	int			iter_max;
	float		**tmp_pixels;
	int			size_coord;
	void		*mlx;
	void		*win;
	void		*img;
	int			key;
	int			*str_img;
	int			bpp;
	int			s_l;
	int			endian;
	int			color;
	int			x_win;
	int			y_win;
	int			x_min;
	int			x_max;
	int			y_min;
	int			y_max;
	int			r;
	int			g;
	int			b;
	int			keycolor;
	float		slide_x;
	float		slide_y;
	int			mouse_x;
	int			mouse_y;
	int			zoom_flag;
	int			mouse_flag;
	int			mouse_flag_bis;
	int			x_mouse;
	int			y_mouse;
	char		fractal_code;
	int			flag_freeze;
	float		c_r_tmp;
	float		c_i_tmp;
}				t_param;

int				main(int argc, char **argv);
int				ft_error_malloc_struct(void);
int				ft_error_malloc_tab(void);
int				ft_error_malloc_minilib(void);
float			**ft_memalloc_tab_float(int size_i, int size_j);
void			ft_free_tab_float(float **tab, int size_i);
void			ft_init_struct(t_param *s);
int				ft_keycode(int keycode, void *blabla);
int				ft_convert_rgb_to_hexa(int r, int g, int b);
void			ft_again(t_param *s);
int				ft_events(t_param *s);
void			ft_init_struct(t_param *s);
void			ft_free_tab_float(float **tab, int size_i);
int				ft_put_tab_to_img(t_param *s);
int				ft_zoom(int button, int x, int y, t_param *s);
int				ft_mouse(int x_mouse, int y_mouse, t_param *s);
void			ft_keycode_slide(t_param *s);
void			ft_keycode_colors(t_param *s);
void			ft_keycode_vary_itermax(t_param *s);
void			ft_init_xy(t_param *s, int x, int y);
void			ft_init_colors_julia(t_param *s, int i);
void			ft_init_colors_burning(t_param *s, int i);
int				ft_mandel(void);
int				ft_fractal_mandel(t_param *s);
void			ft_init_mandel(t_param *s, int x, int y);
int				ft_compute_mandel(t_param *s, int x, int y);
int				ft_julia(void);
int				ft_fractal_julia(t_param *s);
void			ft_init_julia(t_param *s, int x, int y);
int				ft_compute_julia(t_param *s, int x, int y);
int				ft_burning(void);
int				ft_fractal_burning(t_param *s);
void			ft_init_burning(t_param *s, int x, int y);
int				ft_compute_burning(t_param *s, int x, int y);
int				ft_juju(void);
int				ft_fractal_juju(t_param *s);
void			ft_init_juju(t_param *s, int x, int y);
int				ft_compute_juju(t_param *s, int x, int y);
int				ft_tricorn(void);
int				ft_fractal_tricorn(t_param *s);
void			ft_init_tricorn(t_param *s, int x, int y);
int				ft_compute_tricorn(t_param *s, int x, int y);
int				ft_ror(void);
int				ft_fractal_ror(t_param *s);
void			ft_init_ror(t_param *s, int x, int y);
int				ft_compute_ror(t_param *s, int x, int y);

#endif
