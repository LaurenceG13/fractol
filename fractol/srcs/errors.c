/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 19:50:08 by lagirard          #+#    #+#             */
/*   Updated: 2017/10/31 19:50:10 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_error_malloc_minilib(void)
{
	ft_putendl("Error : malloc struc failed");
	return (1);
}

int		ft_error_malloc_struct(void)
{
	ft_putendl("Error : malloc struc failed");
	return (1);
}

int		ft_error_malloc_tab(void)
{
	ft_putendl("Error : malloc tab failed");
	return (1);
}
