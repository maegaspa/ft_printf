/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util4.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/15 14:10:03 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 15:02:32 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

void					ft_putnstr(char const *s, int size)
{
	if (s != 0)
		write(1, s, size);
}

char					*dectohexa(unsigned long long n, t_flag flags, int i)
{
	char				*seg;
	int					j;
	int					tmp;

	if (n >= 429496729 && n <= 4563402751 && !flags.l)
		n = n - 4294967296;
	if (n == 0)
		return (octa_zero(seg));
	j = ret_int(n, 16);
	if (!(seg = malloc(sizeof(char) * j + 1)))
		return (NULL);
	seg[j] = '\0';
	while (n != 0)
	{
		tmp = n % 16;
		if (tmp < 10)
			seg[i] = tmp + 48;
		else if (flags.conv == 'x' || flags.conv == 'p')
			seg[i] = tmp + 87;
		else if (flags.conv == 'X')
			seg[i] = tmp + 55;
		i++;
		n = n / 16;
	}
	return (ft_strrev(cut_str_long(seg, flags)));
}

int						ft_atoi_2(char const *str)
{
	int		i;
	int		nbr;

	i = 0;
	nbr = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || ft_isalpha(str[i])
			|| str[i] == '%' || str[i] == '0' || str[i] == '+' || str[i] == '-'
			|| str[i] == '#' || str[i] == 'l' || str[i] == 'h' || str[i] == 'L')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + str[i++] - '0';
	return (nbr);
}

char					*ft_strcaps(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		while (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
			i++;
		}
		i++;
	}
	return (str);
}

int						ft_is_in_string(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o'
			|| c == 'u' || c == 'x' || c == 'X' || c == 'f'
			|| c == '%' || c == '-' || c == '+' || c == '.'
			|| (c >= 48 && c <= 57) || c == ' ' || c == '#' || c == 'l'
			|| c == 'h' || c == 'L')
		return (1);
	return (0);
}
