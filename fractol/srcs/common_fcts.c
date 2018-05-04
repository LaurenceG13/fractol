/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_fcts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:45:33 by lagirard          #+#    #+#             */
/*   Updated: 2017/10/28 19:40:00 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_init_xy(t_param *s, int x, int y)
{
	s->x_min = fmin(s->x_min, x);
	s->x_max = fmax(s->x_max, x);
	s->y_min = fmin(s->y_min, y);
	s->y_max = fmax(s->y_max, y);
}

float	**ft_memalloc_tab_float(int size_i, int size_j)
{
	float	**tab;
	int		i;
	int		j;

	if (!(tab = (float **)malloc(sizeof(float *) * size_i)))
		return (NULL);
	i = 0;
	while (i < size_i)
	{
		j = 0;
		if (!(tab[i] = (float *)malloc(sizeof(float) * size_j)))
			return (NULL);
		while (j < size_j)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (tab);
}

void	ft_free_tab_float(float **tab, int size_i)
{
	int		i;

	if (tab == NULL)
		return ;
	i = 0;
	while (i < size_i)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

int		ft_put_tab_to_img(t_param *s)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	s->r = 0;
	s->g = 0;
	s->b = 0;
	while (i < s->size_coord)
	{
		x = s->tmp_pixels[i][0];
		y = s->tmp_pixels[i][1];
		s->r = s->tmp_pixels[i][2];
		s->g = s->tmp_pixels[i][3];
		s->b = s->tmp_pixels[i][4];
		if (x < s->x_max && y < s->y_max && x >= s->x_min && y >= s->y_min)
			s->str_img[(y - s->y_min) * s->x_win + (x - s->x_min)] = \
			ft_convert_rgb_to_hexa(s->r, s->g, s->b);
		i++;
	}
	return (0);
}
