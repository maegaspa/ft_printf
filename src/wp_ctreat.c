/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wp_ctreat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/30 12:44:39 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/30 12:45:17 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

int			wp_ctreat(t_flag flag, int c)
{
	int nb_char;
	int i;
    unsigned char letter;

    letter = (unsigned char)c;
	i = 1;
	nb_char = 0;
	if (flag.minus)
        ft_putchar(letter);
	if (flag.width && !flag.point)
	{
        while (i++ < flag.width)
        {
        	if (flag.zero)
				nb_char += ft_putchar_add('0');
            else
                nb_char += ft_putchar_add(' ');
        }
    }
    if (!flag.minus)
        ft_putchar(letter);
    return (nb_char + 1);
}