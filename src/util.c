/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/30 15:47:32 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 13:17:58 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

int			char_treat(char c, int nb_char)
{
	ft_putchar(c);
	nb_char++;
	return (nb_char);
}

int			multichar_treat(char *c, int nb_char)
{
	ft_putstr(c);
	nb_char += ft_strlen(c);
	return (nb_char);
}

int			ft_putchar_add(char c)
{
	write(1, &c, 1);
	return (1);
}

double long	ft_pow10(double long f, int exp)
{
	while (exp)
	{
		f = f * 10;
		exp--;
	}
	return (f);
}

void		free_compt(t_compt *compt)
{
	free(compt->num);
	free(compt->num2);
}
