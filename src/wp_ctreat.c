/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wp_ctreat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/30 12:44:39 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/16 19:58:45 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

static void			ft_affich_letter(t_flag flag, unsigned char letter)
{
	if (flag.conv == 'c')
		ft_putchar(letter);
	else
		ft_putchar('%');
}

int					wp_ctreat(t_flag flag, va_list ap)
{
	int				nb_char;
	int				i;
	unsigned char	letter;

	if (flag.conv == 'c')
		i = va_arg(ap, int);
	letter = (unsigned char)i;
	i = 1;
	nb_char = 0;
	if (flag.minus)
		ft_affich_letter(flag, letter);
	while (i++ < flag.width)
	{
		if (flag.zero)
			nb_char += ft_putchar_add('0');
		else
			nb_char += ft_putchar_add(' ');
	}
	if (!flag.minus)
		ft_affich_letter(flag, letter);
	return (nb_char + 1);
}
