/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:49:53 by joao-vri          #+#    #+#             */
/*   Updated: 2025/06/18 21:49:05 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	parse(t_fractal *fractal, int ac, char **av)
{
	char	*name;

	name = av[1];
	if (!name)
		error_function();
	if (ft_strncmp(name, "mandelbrot", 11) == 0 && ac == 2)
		fractal->type = 0;
	else if (ft_strncmp(name, "julia", 6) == 0)
	{
		check_arguments(fractal, ac, av);
		fractal->type = 1;
	}
	else if (ft_strncmp(name, "burning_ship", 13) == 0 && ac == 2)
		fractal->type = 2;
	else
		error_function();
}

void	check_arguments(t_fractal *fractal, int ac, char **av)
{
	if (ac < 4)
		error_function();
	fractal->cr = atof(av[2]);
	fractal->ci = atof(av[3]);
	if (fractal->cr < -2.0 || fractal->cr > 2.0
		|| fractal->ci < -2.0 || fractal->ci > 2.0)
		error_function();
}
