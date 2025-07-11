/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:10:04 by joao-vri          #+#    #+#             */
/*   Updated: 2025/06/18 15:15:01 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_fractal *fractal)
{
	arrow_keys(fractal, keycode);
	if (keycode == ESC_LINUX)
		close_window(fractal);
	else if (keycode == PLUS_KEY_1 || keycode == PLUS_KEY_2)
		fractal->zoom *= 1.2;
	else if (keycode == MINUS_KEY_1 || keycode == MINUS_KEY_2)
		fractal->zoom /= 1.2;
	else if (keycode == P_KEY)
		fractal->current_palette = (fractal->current_palette + 1)
			% NUM_PALETTES;
	else if (keycode == R_KEY)
		reset_fractal(fractal);
	else if (keycode == I_KEY || keycode == D_KEY)
	{
		if (keycode == I_KEY && fractal->max_iter <= 490)
			fractal->max_iter += 10;
		else if (keycode == D_KEY && fractal->max_iter >= 11)
			fractal->max_iter -= 10;
		ft_printf("Iterations: %i\n", fractal->max_iter);
	}
	choose_fractal(fractal);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_fractal *fractal)
{
	double	og_cr;
	double	og_ci;
	double	new_cr;
	double	new_ci;
	double	zoom_factor;

	if (mouse_scrool(keycode, &zoom_factor) == 0)
		return (0);
	if (fractal->max_iter > 200)
		fractal->max_iter = 200;
	og_cr = (x - fractal->width / 2.0) * (4.0 / fractal->width)
		/ fractal->zoom + fractal->offset_x;
	og_ci = (y - fractal->height / 2.0) * (4.0 / fractal->height)
		/ fractal->zoom + fractal->offset_y;
	fractal->zoom *= zoom_factor;
	new_cr = (x - fractal->width / 2.0) * (4.0 / fractal->width)
		/ fractal->zoom;
	new_ci = (y - fractal->height / 2.0) * (4.0 / fractal->height)
		/ fractal->zoom;
	fractal->offset_x = og_cr - new_cr;
	fractal->offset_y = og_ci - new_ci;
	choose_fractal(fractal);
	return (0);
}

int	mouse_scrool(int keycode, double *zoom_factor)
{
	if (keycode == SCROLL_UP)
	{
		*zoom_factor = 1.2;
		return (1);
	}
	else if (keycode == SCROLL_DOWN)
	{
		*zoom_factor = 1.0 / 1.2;
		return (1);
	}
	else
		return (0);
}

void	arrow_keys(t_fractal *fractal, int keycode)
{
	if (keycode != UP_ARROW && keycode != DOWN_ARROW
		&& keycode != LEFT_ARROW && keycode != RIGHT_ARROW)
		return ;
	if (keycode == UP_ARROW)
		fractal->offset_y -= 0.1 / fractal->zoom;
	else if (keycode == DOWN_ARROW)
		fractal->offset_y += 0.1 / fractal->zoom;
	else if (keycode == LEFT_ARROW)
		fractal->offset_x -= 0.1 / fractal->zoom;
	else if (keycode == RIGHT_ARROW)
		fractal->offset_x += 0.1 / fractal->zoom;
}

void	choose_fractal(t_fractal *fractal)
{
	if (fractal->type == 0)
		draw_mandelbrot(fractal);
	else if (fractal->type == 1)
		draw_julia(fractal);
	else if (fractal->type == 2)
		draw_burning_ship(fractal);
}
