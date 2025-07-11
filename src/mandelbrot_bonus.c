/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:05:41 by joao-vri          #+#    #+#             */
/*   Updated: 2025/06/17 20:39:12 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	calc_mandelbrot(double cr, double ci, int max_iter)
{
	double	zr;
	double	zi;
	double	tmp;
	int		n;

	n = 0;
	zr = 0;
	zi = 0;
	while ((zr * zr + zi * zi <= 4.0) && (n < max_iter))
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		n++;
	}
	return (n);
}

void	draw_mandelbrot(t_fractal *fractal)
{
	int	x;
	int	y;
	int	iter;

	y = 0;
	while (y < fractal->height)
	{
		x = 0;
		while (x < fractal->width)
		{
			fractal->cr = (x - fractal->width / 2.0) * (4.0 / fractal->width)
				/ fractal->zoom + fractal->offset_x;
			fractal->ci = (y - fractal->height / 2.0) * (4.0 / fractal->height)
				/ fractal->zoom + fractal->offset_y;
			iter = calc_mandelbrot(fractal->cr, fractal->ci, fractal->max_iter);
			my_mlx_pixel_put(&fractal->img, x, y,
				get_color(iter, fractal->max_iter, fractal));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
}
