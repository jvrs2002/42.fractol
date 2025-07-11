/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:26:55 by joao-vri          #+#    #+#             */
/*   Updated: 2025/06/18 14:59:24 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_fractal *fractal)
{
	fractal->offset_x = 0.0;
	fractal->offset_y = 0.0;
	fractal->max_iter = MAX_ITERATIONS;
	fractal->current_palette = 0;
	fractal->x = 0;
	fractal->y = 0;
	fractal->help_window = NULL;
	if (fractal->type == 0)
	{
		fractal->zoom = 1.5;
		fractal->offset_x = -0.75;
	}
	else if (fractal->type == 1)
		fractal->zoom = 0.9;
	if (fractal->type == 2)
	{
		fractal->zoom = 1.2;
		fractal->offset_x = -0.45;
		fractal->offset_y = -0.6;
	}
}

void	reset_fractal(t_fractal *fractal)
{
	fractal->zoom = 1.0;
	fractal->offset_x = 0.0;
	fractal->offset_y = 0.0;
	fractal->max_iter = MAX_ITERATIONS;
	fractal->x = 0;
	fractal->y = 0;
	if (fractal->type == 0)
	{
		fractal->zoom = 1.5;
		fractal->offset_x = -0.75;
	}
	else if (fractal->type == 1)
		fractal->zoom = 0.9;
	if (fractal->type == 2)
	{
		fractal->zoom = 1.2;
		fractal->offset_x = -0.45;
		fractal->offset_y = -0.6;
	}
}

void	init_image(t_fractal *fractal)
{
	fractal->img.img = mlx_new_image(fractal->mlx,
			fractal->width, fractal->height);
	fractal->img.addr = (unsigned char *)mlx_get_data_addr(fractal->img.img,
			&fractal->img.bpp, &fractal->img.line_length, &fractal->img.endian);
}

int	init_palettes(t_fractal *fractal)
{
	int	i;

	fractal->palettes = malloc(sizeof(int *) * NUM_PALETTES);
	if (!fractal->palettes)
		return (1);
	i = 0;
	while (i < NUM_PALETTES)
	{
		fractal->palettes[i] = malloc(sizeof(int) * COLORS_PER_PALETTE);
		if (!fractal->palettes[i])
			return (i);
		i++;
	}
	set_palette_a(fractal->palettes[0]);
	set_palette_b(fractal->palettes[1]);
	set_palette_c(fractal->palettes[2]);
	set_palette_d(fractal->palettes[3]);
	set_palette_e(fractal->palettes[4]);
	set_palette_f(fractal->palettes[5]);
	set_palette_g(fractal->palettes[6]);
	set_palette_h(fractal->palettes[7]);
	set_palette_i(fractal->palettes[8]);
	return (0);
}

void	free_palettes(t_fractal *fractal)
{
	int	i;

	i = 0;
	while (i < NUM_PALETTES)
	{
		free(fractal->palettes[i]);
		i++;
	}
	free(fractal->palettes);
}
