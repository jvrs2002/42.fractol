/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:29:30 by joao-vri          #+#    #+#             */
/*   Updated: 2024/06/03 11:27:30 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_hex(unsigned long int nb, size_t ind)
{
	size_t	i;

	i = 0;
	if (nb == 0 && ind == 3)
		return (ft_putstr_pf("(nil)"));
	if (nb != 0 && ind == 3)
	{
		i += ft_putstr_pf("0x");
		ind = 1;
	}
	if (nb >= 16)
		i += ft_putnbr_hex(nb / 16, ind);
	if ((nb % 16) < 10)
		i += ft_putchar_pf((nb % 16) + 48);
	else if (ind == 1)
		i += ft_putchar_pf((nb % 16) + 87);
	else if (ind == 2)
		i += ft_putchar_pf((nb % 16) + 55);
	return (i);
}
