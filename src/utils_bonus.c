/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:25:21 by joao-vri          #+#    #+#             */
/*   Updated: 2025/06/17 22:43:12 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	unsigned char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_color(int iter, int max_iter, t_fractal *fractal)
{
	int	i;
	int	offset;

	offset = 2;
	if (iter == max_iter)
		return (FRACTAL);
	if (fractal->current_palette < 0
		|| fractal->current_palette >= NUM_PALETTES)
		fractal->current_palette = 0;
	i = (iter * COLORS_PER_PALETTE) / max_iter;
	i = (i + offset) % COLORS_PER_PALETTE;
	return (fractal->palettes[fractal->current_palette][i]);
}
