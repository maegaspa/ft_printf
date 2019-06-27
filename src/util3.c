/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util3.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/14 18:02:35 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 14:49:36 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

char					*octa_zero(char *seg)
{
	seg = ft_strnew(1);
	seg[0] = 48;
	seg[1] = '\0';
	return (seg);
}

int						ret_int(unsigned long long n, int base)
{
	int		j;

	j = 0;
	while (n != 0)
	{
		n = n / base;
		j++;
	}
	return (j);
}

char					*cut_str_long(char *seg, t_flag flags)
{
	if (flags.conv == 'x' || flags.conv == 'X')
	{
		if (flags.l && ft_strlen(seg) > 16)
			seg[16] = '\0';
		if (ft_strlen(seg) > 8 && !flags.l)
			seg[8] = '\0';
		if (flags.h == 1)
			seg[4] = '\0';
		if (flags.h == 2)
			seg[2] = '\0';
	}
	else
	{
		if (flags.h == 1)
			seg[6] = '\0';
		if (flags.h == 2)
			seg[3] = '\0';
	}
	return (seg);
}

char					*dectoocta(unsigned long n, t_flag flags)
{
	char				*seg;
	int					i;
	int					j;
	unsigned long		tmp;

	if (flags.h)
		n = (unsigned short)n;
	if (flags.h == 2)
		n = (unsigned char)n;
	i = 0;
	if (n == 0)
		return (octa_zero(seg));
	j = ret_int(n, 8);
	if (!(seg = malloc(sizeof(char) * j + 1)))
		return (NULL);
	seg[j] = '\0';
	while (n != 0)
	{
		seg[i] = 48 + (n % 8);
		n = n / 8;
		i++;
	}
	return (ft_strrev(seg));
}

void					ft_putncaract(char c, int size)
{
	int					i;

	i = -1;
	while (++i != size)
		ft_putchar(c);
}
