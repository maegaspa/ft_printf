/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wp_ftreat2.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/18 15:48:41 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 15:57:41 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

int				ft_sfloatinit(double flo, t_flag flag, t_float *sfloat)
{
	sfloat->preci = flag.precision;
	sfloat->enti = (long)flo;
	if (!(sfloat->digit = ft_strnew(0)))
		return (0);
	sfloat->digit[0] = '\0';
	sfloat->i = 1;
	return (1);
}

int				ft_putzero(int zero, char **temp, char **nb)
{
	while (zero-- != 0 && zero > 0)
	{
		free(*temp);
		*temp = ft_strdup(*nb);
		free(*nb);
		if (!(*nb = ft_strjoin(*temp, "0")))
			return (0);
	}
	return (1);
}

int				ft_print_before(t_flag flag, int putspace, char *str, double nb)
{
	int		nb_char;

	nb_char = 0;
	if (flag.space && !flag.plus)
		nb_char += ft_putchar_add(' ');
	if (putspace > 0 && !flag.minus && !flag.zero)
		while (putspace--)
			nb_char += ft_putchar_add(' ');
	if (flag.plus)
		if (nb >= 0)
			nb_char += ft_putchar_add('+');
	if (nb < 0 && ft_strlen(str) > 0 && str[0] != '-')
		nb_char += ft_putchar_add('-');
	if (putspace > 0 && !flag.minus && flag.zero)
		while (putspace--)
			nb_char += ft_putchar_add('0');
	return (nb_char);
}
