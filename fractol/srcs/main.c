/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:33:05 by lagirard          #+#    #+#             */
/*   Updated: 2017/10/24 16:19:34 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_usage(void)
{
	ft_putendl("Usage : ./fractol fractal_name\nYou can choose one of the \
following fractals :\nMANDELBROT\nJULIA\nBURNINGSHIP\nJUJU\nTRICORN\n\
RORSCHACH");
	return (1);
}

int		ft_error_name(void)
{
	ft_putendl("Invalid fractal name\nYou can choose one of the following \
fractals :\nMANDELBROT\nJULIA\nBURNINGSHIP\nJUJU\nTRICORN\nRORSCHACH");
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_usage());
	if (ft_strcmp(argv[1], "MANDELBROT") == 0)
		return (ft_mandel());
	else if (ft_strcmp(argv[1], "JULIA") == 0)
		return (ft_julia());
	else if (ft_strcmp(argv[1], "BURNINGSHIP") == 0)
		return (ft_burning());
	else if (ft_strcmp(argv[1], "JUJU") == 0)
		return (ft_juju());
	else if (ft_strcmp(argv[1], "TRICORN") == 0)
		return (ft_tricorn());
	else if (ft_strcmp(argv[1], "RORSCHACH") == 0)
		return (ft_ror());
	else
		return (ft_error_name());
	return (0);
}
