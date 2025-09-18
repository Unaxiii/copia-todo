/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:38:50 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/23 10:32:03 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <limits.h> */

static int	ft_intlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = n;
	len = ft_intlen(nb);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (--len >= 0 && str[len] != '-')
	{
		str[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
/* 
int	main(void)
{
	int		numeros[] = {0, 42, -42, 123456, -987654, INT_MAX, INT_MIN};
	size_t	i;
	char	*resultado;

	for (i = 0; i < sizeof(numeros) / sizeof(numeros[0]); i++)
	{
		resultado = ft_itoa(numeros[i]);
		if (resultado)
		{
			printf("ft_itoa(%d) = \"%s\"\n", numeros[i], resultado);
			free(resultado);
		}
		else
			printf("Error con ft_itoa(%d)\n", numeros[i]);
	}
	return (0);
} */