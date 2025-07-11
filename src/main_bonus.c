/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:21:03 by joao-vri          #+#    #+#             */
/*   Updated: 2025/06/17 22:45:28 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	error_function(void)
{
	write(STDOUT_FILENO, "Usage: ./fractol <fractal_name> [julia_params]", 47);
	write(STDOUT_FILENO, "\nAvailable fractals:\n", 22);
	write(STDOUT_FILENO, "  mandelbrot\n", 13);
	write(STDOUT_FILENO, "  burning_ship\n", 15);
	write(STDOUT_FILENO, "  julia <r> <i> (between -2.0 and 2.0)\n", 40);
	write(STDOUT_FILENO, "    Example: ./fractol julia 0.285 0.01\n", 39);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;
	int			choice;

	parse(&fractal, ac, av);
	choice = get_resolution();
	set_resolution(&fractal, choice);
	fractal.mlx = mlx_init();
	fractal.win = mlx_new_window(fractal.mlx,
			fractal.width, fractal.height, "fractol");
	init_image(&fractal);
	init_fractal(&fractal);
	if (init_palettes(&fractal) == 1)
		close_window(&fractal);
	help_window(&fractal);
	choose_fractal(&fractal);
	mlx_key_hook(fractal.win, key_hook, &fractal);
	mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
	mlx_hook(fractal.win, 17, 0, close_window, &fractal);
	mlx_hook(fractal.help_window, 17, 0, close_window, &fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
