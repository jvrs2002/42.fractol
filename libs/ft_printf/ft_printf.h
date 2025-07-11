/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:06:25 by joao-vri          #+#    #+#             */
/*   Updated: 2024/06/03 11:21:11 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# include <unistd.h>

# include <stdarg.h>

int		ft_printf(const char *str, ...);
size_t	ft_putchar_pf(int c);
size_t	ft_putnbr_pf(int nb);
size_t	ft_putnbr_hex(unsigned long int nb, size_t ind);
size_t	ft_putnbr_unsigned_pf(unsigned int nb);
size_t	ft_putstr_pf(char *str);

#endif
