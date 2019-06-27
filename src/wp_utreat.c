/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wp_utreat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/15 18:18:37 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 18:03:38 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

int				wp_utreat(t_flag flag, unsigned long long dig)
{
	int			putspace;
	int			nb_char;
	char		*nbr;

	putspace = 0;
	nb_char = 0;
	nbr = nbr_dig(dig, flag, nbr);
	nb_char = u_treat_1(flag, dig, nbr, nb_char);
	nb_char = u_treat_2(flag, dig, nbr, nb_char);
	if (flag.width > 0 && !flag.point)
		nb_char = u_treat_3(flag, dig, nbr, nb_char);
	nb_char = u_treat_4(flag, dig, nbr, nb_char);
	nb_char = u_treat_5(flag, dig, nbr, nb_char);
	nb_char = u_treat_5bis(flag, dig, nbr, nb_char);
	nb_char = u_treat_6(flag, dig, nbr, nb_char);
	nb_char = u_treat_7(flag, dig, nbr, nb_char);
	return (ft_strlen(nbr) + nb_char);
}

int				u_treat_1(t_flag flag, long long dig, char *nbr, int nb_char)
{
	int			putspace;
	int			i;

	i = -1;
	putspace = flag.width - ft_strlen(nbr);
	if (flag.minus > 0 && flag.precision <= 1 && (!(dig == 0)))
		ft_putstr(nbr);
	if (flag.width > 0 && dig == 0 && flag.point > 0 && !flag.precision)
	{
		putspace = flag.width;
		while (++i < putspace)
			nb_char = char_treat(' ', nb_char);
	}
	if (flag.precision > 0 && flag.point && flag.zero)
	{
		putspace = flag.precision - ft_strlen(nbr);
		if (dig == 0 && !flag.width)
			putspace = flag.precision;
		i = -1;
		if ((size_t)flag.precision > ft_strlen(nbr) && (!(dig == 0)))
			while (++i < putspace)
				nb_char = char_treat('0', nb_char);
	}
	return (nb_char);
}

int				u_treat_2(t_flag flag, long long dig, char *nbr, int nb_char)
{
	int			putspace;
	int			i;

	i = -1;
	putspace = 0;
	if (!flag.width && flag.point && flag.precision &&
		!flag.minus && !flag.zero && (!(dig == 0)))
	{
		putspace = flag.precision - ft_strlen(nbr);
		while (++i < putspace)
			nb_char = char_treat('0', nb_char);
	}
	if (flag.precision > 0 && dig == 0 && flag.point &&
		!flag.width && !flag.zero)
	{
		putspace = flag.precision;
		i = -1;
		while (++i < putspace)
			nb_char = char_treat('0', nb_char);
	}
	return (nb_char);
}

int				u_treat_3(t_flag flag, long long dig, char *nbr, int nb_char)
{
	int			putspace;
	int			i;

	i = -1;
	putspace = flag.width - ft_strlen(nbr);
	if (dig == 0)
		putspace = flag.width;
	if ((size_t)flag.width > ft_strlen(nbr) && flag.minus)
		while (++i < putspace)
			nb_char = char_treat(' ', nb_char);
	putspace = flag.width - ft_strlen(nbr);
	if (dig == 0)
		putspace = flag.width;
	if ((size_t)flag.width > ft_strlen(nbr) && !flag.minus)
	{
		while (++i < putspace)
		{
			if (flag.point > 0 || flag.zero > 0)
				nb_char = char_treat('0', nb_char);
			else
				nb_char = char_treat(' ', nb_char);
		}
	}
	return (nb_char);
}

int				u_treat_4(t_flag flag, long long dig, char *nbr, int nb_char)
{
	int			putspace;
	int			i;

	putspace = flag.width - ft_strlen(nbr);
	i = -1;
	if (flag.width > 0 && flag.point > 0 && !flag.precision && (!(dig == 0)))
	{
		if ((size_t)flag.width > ft_strlen(nbr) && !flag.minus)
			while (++i < putspace)
				nb_char = char_treat(' ', nb_char);
	}
	if (!flag.width && flag.minus > 0 && flag.point > 0 && flag.precision > 0)
	{
		putspace = flag.precision - ft_strlen(nbr);
		if ((size_t)flag.precision > ft_strlen(nbr))
			while (++i < putspace)
				nb_char = char_treat('0', nb_char);
	}
	return (nb_char);
}
