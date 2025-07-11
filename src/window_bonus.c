/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:43:39 by joao-vri          #+#    #+#             */
/*   Updated: 2025/06/18 15:16:29 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	close_window(t_fractal *fractal)
{
	if (fractal->help_window)
	{
		mlx_destroy_window(fractal->mlx, fractal->help_window);
		fractal->help_window = NULL;
	}
	if (fractal->img.img)
	{
		mlx_destroy_image(fractal->mlx, fractal->img.img);
		fractal->img.img = NULL;
	}
	if (fractal->win)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		fractal->win = NULL;
	}
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	free(fractal->help_window);
	free_palettes(fractal);
	exit(0);
	return (0);
}

int	get_resolution(void)
{
	size_t	n;
	char	buffer[3];
	int		choice;

	choice = 0;
	write(STDOUT_FILENO, "Choose resolution:\n", 19);
	write(STDOUT_FILENO, "1. 800x600 (default)\n", 21);
	write(STDOUT_FILENO, "2. 1280x720\n", 12);
	write(STDOUT_FILENO, "3. 1366x768\n", 12);
	write(STDOUT_FILENO, "4. 1920x1080\n", 13);
	n = read(STDIN_FILENO, buffer, 2);
	if (n <= 0)
		return (1);
	buffer[n] = '\0';
	if (buffer[0] >= '1' && buffer[0] <= '4')
		choice = buffer[0] - '0';
	else
		choice = 1;
	return (choice);
}

void	set_resolution(t_fractal *fractal, int choice)
{
	if (choice < 1 || choice > 4)
		choice = 1;
	if (choice == 1)
	{
		fractal->width = 800;
		fractal->height = 600;
	}
	else if (choice == 2)
	{
		fractal->width = 1280;
		fractal->height = 720;
	}
	else if (choice == 3)
	{
		fractal->width = 1366;
		fractal->height = 768;
	}
	else if (choice == 4)
	{
		fractal->width = 1920;
		fractal->height = 1080;
	}
	fractal->current_palette = 0;
}

void	help_window(t_fractal *fractal)
{
	int	y;

	y = 20;
	fractal->help_window
		= mlx_new_window(fractal->mlx, 400, 200, "Help - Commands");
	if (!fractal->help_window)
		error_function();
	mlx_string_put(fractal->mlx, fractal->help_window,
		20, y, 0xFFFFFF, "Fractol Controls:");
	y += 25;
	mlx_string_put(fractal->mlx, fractal->help_window, 20,
		y, 0xAAAAAA, "Zoom:        Scroll | + | -");
	y += 20;
	mlx_string_put(fractal->mlx, fractal->help_window, 20,
		y, 0xAAAAAA, "Move:        Arrow Keys");
	y += 20;
	mlx_string_put(fractal->mlx, fractal->help_window, 20,
		y, 0xAAAAAA, "Palette:     P");
	y += 20;
	help_window_2(fractal, y);
}

void	help_window_2(t_fractal *fractal, int y)
{
	mlx_string_put(fractal->mlx, fractal->help_window, 20,
		y, 0xAAAAAA, "Reset:       R");
	y += 20;
	mlx_string_put(fractal->mlx, fractal->help_window, 20,
		y, 0xAAAAAA, "Exit:        ESC");
	y += 20;
	mlx_string_put(fractal->mlx, fractal->help_window, 20,
		y, 0xAAAAAA, "Inc./Dec. Iter.:      I | D");
	y += 20;
	mlx_string_put(fractal->mlx, fractal->help_window, 20,
		y, 0xAAAAAA, "(MIN. ITERATIONS: 10 | MAX ITERATIONS: 500)");
}
