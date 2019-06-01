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

int			wp_ctreat(t_flag flag, int size, int c)
{
	int putspace;
	int nb_char;
	int i;

	i = 0;
	nb_char = 0;
    putspace = size - 1;
	if (flag.width > 0 && flag.point == 0)
	{
		if (size > 1)
		{
            while (++i < putspace)
            {
                if (flag.zero > 0)
                { 
                    ft_putchar('0');
                    nb_char++;
                }
                else
                {
                    ft_putchar(' ');
                    nb_char++;
                }
            }
        }
    }
    ft_putchar(c);
    return (nb_char + 1);
}