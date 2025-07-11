/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:01:19 by joao-vri          #+#    #+#             */
/*   Updated: 2024/05/29 15:31:54 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_pf(int nb)
{
	size_t	i;

	i = 0;
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (i += 11);
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar_pf('-');
			i++;
			nb = -nb;
		}
		if (nb >= 10)
			i += ft_putnbr_pf(nb / 10);
	}
	i += ft_putchar_pf(nb % 10 + '0');
	return (i);
}
