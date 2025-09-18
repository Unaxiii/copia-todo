/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:46:17 by uelizegi          #+#    #+#             */
/*   Updated: 2025/05/09 11:58:03 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_hex(unsigned long n)
{
	char	*hex;
	char	c;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		count += ft_putptr_hex(n / 16);
	c = hex[n % 16];
	count += write(1, &c, 1);
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long	n;
	int				count;

	if (ptr == NULL)
		return (write (1, "(nil)", 5));
	n = (unsigned long)ptr;
	count = write (1, "0x", 2);
	count += ft_putptr_hex(n);
	return (count);
}
