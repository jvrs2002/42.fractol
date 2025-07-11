/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:15:55 by joao-vri          #+#    #+#             */
/*   Updated: 2025/06/18 16:49:53 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "libft.h"
# include "ft_printf.h"

// Deep Blue
# define A_0  0x020659
# define A_1  0x0B1354
# define A_2  0x1C1B6B
# define A_3  0x2E2D87
# define A_4  0x3F3FA3
# define A_5  0x505FBF
# define A_6  0x6281DB
# define A_7  0x74A3F7
# define A_8  0xB4D2FF
# define A_9  0xEAF4FF

// Inferno
# define B_0  0x000004
# define B_1  0x1b0c41
# define B_2  0x4f0c4f
# define B_3  0x841654
# define B_4  0xbd3655
# define B_5  0xee6a4e
# define B_6  0xfca636
# define B_7  0xfedc90
# define B_8  0xfefbd3
# define B_9  0xffffff

// Cubehelix
# define C_0  0x000000
# define C_1  0x1e194d
# define C_2  0x3d3362
# define C_3  0x5c4c6e
# define C_4  0x7c6481
# define C_5  0x9d7b92
# define C_6  0xbe94a6
# define C_7  0xdfafbd
# define C_8  0xffcbd5
# define C_9  0xffffff

// Sunset
# define D_0  0x370617
# define D_1  0x6a040f
# define D_2  0x9d0208
# define D_3  0xd00000
# define D_4  0xdc2f02
# define D_5  0xe85d04
# define D_6  0xf48c06
# define D_7  0xfaa307
# define D_8  0xffba08
# define D_9  0xfefae0

// Aqua Blue
# define E_0  0x012a4a
# define E_1  0x013a63
# define E_2  0x01497c
# define E_3  0x014f86
# define E_4  0x2a6f97
# define E_5  0x468faf
# define E_6  0x61a5c2
# define E_7  0x89c2d9
# define E_8  0xa9d6e5
# define E_9  0xcbf3f0

// Toxic Green
# define F_0  0x001f00
# define F_1  0x003300
# define F_2  0x004d00
# define F_3  0x006600
# define F_4  0x00b300
# define F_5  0x00e600
# define F_6  0x66ff66
# define F_7  0x99ff99
# define F_8  0xccffcc
# define F_9  0xffffff

// Firestorm
# define G_0  0x070707
# define G_1  0x401F0F
# define G_2  0x7F231C
# define G_3  0xBA2F1E
# define G_4  0xEA4E1B
# define G_5  0xF76F1D
# define G_6  0xFF9B1D
# define G_7  0xFFC857
# define G_8  0xFFD97D
# define G_9  0xFFF8E1

// Ice
# define H_0  0x0f0f3d
# define H_1  0x1c2541
# define H_2  0x2a3a4e
# define H_3  0x395c68
# define H_4  0x478c89
# define H_5  0x56bccf
# define H_6  0x65e4ff
# define H_7  0xaaf0ff
# define H_8  0xd0faff
# define H_9  0xf1ffff

// Rainbow
# define I_0  0xFF0000
# define I_1  0xFF7F00
# define I_2  0xFFFF00
# define I_3  0x7FFF00
# define I_4  0x00FF00
# define I_5  0x00FFFF
# define I_6  0x0000FF
# define I_7  0x4B0082
# define I_8  0x8B00FF
# define I_9  0xFFFFFF

# define FRACTAL 0x1D0033

# define NUM_PALETTES 9
# define COLORS_PER_PALETTE 10

# define MAX_ITERATIONS 250

# define ESC_LINUX 65307
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define PLUS_KEY_1 61
# define PLUS_KEY_2 24
# define MINUS_KEY_1 45
# define MINUS_KEY_2 27
# define P_KEY 112
# define R_KEY 114
# define I_KEY 105
# define D_KEY 100
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_data
{
	unsigned char	*addr;
	void			*img;
	int				bpp;
	int				line_length;
	int				endian;
}				t_data;

typedef struct s_fractal
{
	t_data	img;
	void	*mlx;
	void	*win;
	double	zoom;
	double	offset_x;
	double	offset_y;
	double	cr;
	double	ci;
	int		range_shift;
	int		type;
	int		max_iter;
	int		**palettes;
	int		current_palette;
	int		x;
	int		y;
	int		width;
	int		height;
	void	*help_window;
}	t_fractal;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		calc_mandelbrot(double cr, double ci, int max_iter);
void	draw_mandelbrot(t_fractal *fractal);
int		close_window(t_fractal *fractal);
void	init_image(t_fractal *fractal);
void	init_fractal(t_fractal *fractal);
int		get_color(int iter, int max_iter, t_fractal *fractal);
int		key_hook(int keycode, t_fractal *fractal);
int		mouse_hook(int button, int x, int y, t_fractal *fractal);
int		get_resolution(void);
void	set_resolution(t_fractal *fractal, int choice);
void	error_function(void);
int		calc_julia(t_fractal *fractal, double zr, double zi, int max_iter);
void	draw_julia(t_fractal *fractal);
void	parse(t_fractal *fractal, int ac, char **av);
void	check_arguments(t_fractal *fractal, int ac, char **av);
void	help_window(t_fractal *fractal);
void	draw_burning_ship(t_fractal *fractal);
int		calc_burning_ship(double cr, double ci, int max_iter);
void	help_window_2(t_fractal *fractal, int y);
void	reset_fractal(t_fractal *fractal);
void	choose_fractal(t_fractal *fractal);
void	arrow_keys(t_fractal *fractal, int keycode);
int		mouse_scrool(int keycode, double *zoom_factor);
int		init_palettes(t_fractal *fractal);
void	set_palette_a(int *dest);
void	set_palette_b(int *dest);
void	set_palette_c(int *dest);
void	set_palette_d(int *dest);
void	set_palette_e(int *dest);
void	set_palette_f(int *dest);
void	set_palette_g(int *dest);
void	set_palette_h(int *dest);
void	set_palette_i(int *dest);
void	free_palettes(t_fractal *fractal);

#endif
