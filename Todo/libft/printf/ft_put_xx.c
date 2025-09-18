/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_xx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:44:55 by uelizegi          #+#    #+#             */
/*   Updated: 2025/05/08 12:42:06 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_xx(unsigned int n, char format)
{
	char	*hex;
	char	c;
	int		count;

	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += ft_put_xx(n / 16, format);
	c = hex[n % 16];
	count += write(1, &c, 1);
	return (count);
}
