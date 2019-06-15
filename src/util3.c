/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util3.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/14 18:02:35 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/14 18:03:02 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

char	*octa_zero(char *seg)
{
	seg = ft_strnew(1);
	seg[0] = 48;
	return (seg);
}

int		ret_int(unsigned long long n, int base)
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

char	*cut_str_long(char *seg, t_flag flags)
{
	if (flags.conv == 'x' || flags.conv == 'X')
	{
		if (flags._l && ft_strlen(seg) > 16)
			seg[16] = '\0';
		if (ft_strlen(seg) > 8 && !flags._l)
			seg[8] = '\0';
		if (flags._h == 1)
			seg[4] = '\0';
		if (flags._h == 2)
			seg[2] = '\0';
	}
	else
	{
		if (flags._h == 1)
			seg[6] = '\0';
		if (flags._h == 2)
			seg[3] = '\0';
	}
	return (seg);
}