/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:26:55 by joao-vri          #+#    #+#             */
/*   Updated: 2025/06/17 21:02:48 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calc_julia(t_fractal *fractal, double zr, double zi, int max_iter)
{
	double	tmp;
	double	cr;
	double	ci;
	int		n;

	cr = fractal->cr;
	ci = fractal->ci;
	n = 0;
	while (n < max_iter)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		n++;
	}
	return (n);
}

void	draw_julia(t_fractal *fractal)
{
	double	zr;
	double	zi;
	int		x;
	int		y;
	int		iter;

	x = 0;
	y = 0;
	while (y < fractal->height)
	{
		x = 0;
		while (x < fractal->width)
		{
			zr = 1.5 * (x - fractal->width / 2)
				/ (0.5 * fractal->zoom * fractal->width) + fractal->offset_x;
			zi = (y - fractal->height / 2)
				/ (0.5 * fractal->zoom * fractal->height) + fractal->offset_y;
			iter = calc_julia(fractal, zr, zi, fractal->max_iter);
			my_mlx_pixel_put(&fractal->img, x, y,
				get_color(iter, fractal->max_iter, fractal));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
}
