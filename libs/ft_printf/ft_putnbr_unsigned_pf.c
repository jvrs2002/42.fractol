/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_pf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:33:21 by joao-vri          #+#    #+#             */
/*   Updated: 2024/05/29 15:31:02 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_unsigned_pf(unsigned int nb)
{
	size_t	i;

	i = 0;
	if (nb >= 10)
		i += ft_putnbr_unsigned_pf(nb / 10);
	i += ft_putchar_pf(nb % 10 + '0');
	return (i);
}
