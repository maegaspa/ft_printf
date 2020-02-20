/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util2.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/14 17:55:34 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/22 15:35:10 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

int			is_option(char p)
{
	if (p == 's' || p == 'd' || p == 'i' || p == 'o' || p == 'u' || p == 'x'
		|| p == 'X' || p == 'c' || p == 'p' || p == 'l'
		|| p == 'L' || p == 'f' || p == 'h')
		return (1);
	return (0);
}

int			is_conv(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'o' || c == 'u' || c == 'x' || c == 'X'
		|| c == 'f' || c == '\0' || c == '%' || c == 'b' || c == 'B')
		return (1);
	return (0);
}

int			ft_putstr_add(char const *str)
{
	if (str != NULL)
		write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int			ft_pow(int nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

char		*ft_itoa_base(int value, int base)
{
	int		i;
	char	*nbr;
	int		neg;

	i = 1;
	neg = 0;
	if (value < 0)
	{
		if (base == 10)
			neg = 1;
		value *= -1;
	}
	while (ft_pow(base, i) - 1 < value)
		i++;
	if (!(nbr = (char *)malloc(sizeof(nbr) * i)))
		return (NULL);
	nbr[i + neg] = '\0';
	while (i-- > 0)
	{
		nbr[i + neg] = (value % base) + (value % base > 9 ? 'a' - 10 : '0');
		value = value / base;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}
