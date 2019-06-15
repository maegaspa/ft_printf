/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util4.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/15 14:10:03 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/15 14:43:51 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

void		ft_putnstr(char const *s, int size)
{
	if (s != 0)
		write(1, s, size);
}

char	                *dectohexa(unsigned long long n, t_flag flags, int i)
{
	char				*seg;
	int					j;
	int					tmp;

	if (n >= 429496729 && n <= 4563402751 && !flags._l)
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