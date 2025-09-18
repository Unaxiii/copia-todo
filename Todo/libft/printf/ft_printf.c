/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:00:21 by uelizegi          #+#    #+#             */
/*   Updated: 2025/05/09 14:08:39 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <limits.h> */
#include "ft_printf.h"

static int	find_specifer(char specifer, va_list list)
{
	if (specifer == 'c')
		return (ft_putchar(va_arg(list, int)));
	else if (specifer == 's')
		return (ft_putstr(va_arg(list, char *)));
	else if (specifer == 'p')
		return (ft_putptr(va_arg(list, void *)));
	else if ((specifer == 'd') || (specifer == 'i'))
		return (ft_putnbr(va_arg(list, int)));
	else if (specifer == 'u')
		return (ft_putnbr_unsigned(va_arg(list, unsigned int)));
	else if (specifer == 'x' || specifer == 'X')
		return (ft_put_xx(va_arg(list, unsigned int), specifer));
	else if (specifer == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		count;

	va_start(list, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			count += find_specifer(str[i + 1], list);
			i++;
		}
		else
		{
			count += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(list);
	return (count);
}

int	main(void)
{
	char	n = 'A';
	char	*str = "Hello, 42";
	void	*ptr = str;
	int		num = -42;
	unsigned int	u = 3436574;
}

/* int main(void)
{
	int			ret1, ret2;
	char		*str = "42%25%%";
	char		*nullstr = NULL;
	void		*nullp = NULL;
	void		*ptr = (void *)0x1234abcd;
	int			n = 42;

	printf("==== [%%c] ====\n");
	ret1 = printf("C: %c %c %c %c\n", 'a', 0, 'b', 127);
	ret2 = ft_printf("F: %c %c %c %c\n", 'a', 0, 'b', 127);
	printf("ret1: %d | ret2: %d\n\n", ret1, ret2);

	printf("==== [%%s] ====\n");
	ret1 = printf("C: %s %s %s\n", str, "", nullstr);
	ret2 = ft_printf("F: %s %s %s\n", str, "", nullstr);
	printf("ret1: %d | ret2: %d\n\n", ret1, ret2);

	printf("==== [%%d/%%i] ====\n");
	ret1 = printf("C: %d %i %d %i %d\n", 0, -1, INT_MAX, INT_MIN, 123456);
	ret2 = ft_printf("F: %d %i %d %i %d\n", 0, -1, INT_MAX, INT_MIN, 123456);
	printf("ret1: %d | ret2: %d\n\n", ret1, ret2);

	printf("==== [%%u] ====\n");
	ret1 = printf("C: %u %u %u\n", 0, UINT_MAX, 4294967295U);
	ret2 = ft_printf("F: %u %u %u\n", 0, UINT_MAX, 4294967295U);
	printf("ret1: %d | ret2: %d\n\n", ret1, ret2);

	printf("==== [%%x/%%X] ====\n");
	ret1 = printf("C: %x %x %X %X\n", 0, -1, 255, UINT_MAX);
	ret2 = ft_printf("F: %x %x %X %X\n", 0, -1, 255, UINT_MAX);
	printf("ret1: %d | ret2: %d\n\n", ret1, ret2);

	printf("==== [%%p] ====\n");
	ret1 = printf("C: %p %p %p\n", nullp, &n, ptr);
	ret2 = ft_printf("F: %p %p %p\n", nullp, &n, ptr);
	printf("ret1: %d | ret2: %d\n\n", ret1, ret2);

	printf("==== [%%] ====\n");
	ret1 = printf("C: %%\n");
	ret2 = ft_printf("F: %%\n");
	printf("ret1: %d | ret2: %d\n\n", ret1, ret2);

	printf("==== [Mix] ====\n");
	ret1 = printf("C: %d %u %x %X %c %s %p %%\n",
	 -42, 42, 42, 42, 'A', str, &n);
	ret2 = ft_printf("F: %d %u %x %X %c %s %p %%\n",
	 -42, 42, 42, 42, 'A', str, &n);
	printf("ret1: %d | ret2: %d\n\n", ret1, ret2);

	printf("==== [Edge: %% al final] ====\n");
	ret1 = printf("C: %%");
	ret2 = ft_printf("F: %%");
	printf("\nret1: %d | ret2: %d\n\n", ret1, ret2);

	printf("==== [Format NULL] ====\n");
	ret1 = printf(NULL);
	ret2 = ft_printf(NULL);
	printf("\nret1: %d | ret2: %d\n\n", ret1, ret2);
	return (0);
}
 */