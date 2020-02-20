/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wp_oxtreat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/12 14:13:59 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/28 16:34:15 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

int			wp_oxtreat(t_flag flag, long long dig)
{
	int			putspace;
	int			i;
	int			nb_char;
	char		*nbr;

	putspace = 0;
	nb_char = 0;
	i = -1;
	nbr = dectohexa(dig, flag, 0);
	nb_char = ox_treat_1(flag, dig, nbr, nb_char);
	nb_char = ox_treat_1bis(flag, dig, nbr, nb_char);
	if (flag.width > 0 && !flag.point)
		nb_char = ox_treat_2(flag, dig, nbr, nb_char);
	nb_char = ox_treat_3(flag, dig, nbr, nb_char);
	nb_char = ox_treat_4(flag, dig, nbr, nb_char);
	nb_char = ox_treat_5(flag, dig, nbr, nb_char);
	nb_char = ox_treat_6(flag, dig, nbr, nb_char);
	nb_char = ox_treat_7(flag, dig, nbr, nb_char);
	nb_char = ox_treat_8(flag, dig, nbr, nb_char);
	free(nbr);
	return (ft_strlen(nbr) + nb_char);
}

int			ox_treat_1(t_flag flag, long long dig, char *nbr, int nb_char)
{
	int			putspace;
	int			i;

	i = -1;
	putspace = flag.width - ft_strlen(nbr);
	if (dig == 0 && !flag.width && !flag.precision && !flag.point)
		flag.conv == 'X' ? ft_putstr(ft_strcaps(nbr)) : ft_putstr(nbr);
	if (flag.hashtag > 0 && (!(dig == 0)) && (flag.precision > flag.width ||
		(flag.zero > 0 && !flag.precision && !flag.point)
		|| (flag.width == flag.precision && flag.width != 0)
		|| (flag.zero && !flag.plus && !flag.width)
		|| (flag.width > flag.precision && !flag.zero && flag.precision)
		|| (flag.zero && flag.width && flag.minus)))
	{
		if (flag.conv == 'x')
			nb_char = multichar_treat("0x", nb_char);
		if (flag.conv == 'X')
			nb_char = multichar_treat("0X", nb_char);
	}
	return (nb_char);
}

int			ox_treat_1bis(t_flag flag, long long dig, char *nbr, int nb_char)
{
	int			putspace;
	int			i;

	i = -1;
	putspace = flag.width - ft_strlen(nbr);
	if (flag.minus > 0 && !flag.precision && (!(dig == 0)))
		flag.conv == 'X' ? ft_putstr(ft_strcaps(nbr)) : ft_putstr(nbr);
	if ((dig == 0 && flag.width & flag.point))
		while (++i < (size_t)flag.width)
			nb_char = char_treat(' ', nb_char);
	if ((flag.width && flag.zero && flag.point && flag.hashtag))
		while (++i < putspace - 2)
			nb_char = char_treat(' ', nb_char);
	return (nb_char);
}

int			ox_treat_2(t_flag flag, long long dig, char *nbr, int nb_char)
{
	int			putspace;
	int			i;

	putspace = flag.width - ft_strlen(nbr);
	i = -1;
	if (flag.hashtag > 0)
		putspace -= 2;
	if ((size_t)flag.width > ft_strlen(nbr) && flag.minus)
		while (++i < putspace)
			nb_char = char_treat(' ', nb_char);
	if (dig == 0)
	{
		ft_putchar('0');
		putspace = flag.width - 1;
	}
	if ((size_t)flag.width > ft_strlen(nbr) && !flag.minus)
	{
		while (++i < putspace)
			if (flag.point > 0 || flag.zero > 0)
				nb_char = char_treat('0', nb_char);
			else
				nb_char = char_treat(' ', nb_char);
	}
	return (nb_char);
}

int			ox_treat_3(t_flag flag, long long dig, char *nbr, int nb_char)
{
	int			putspace;
	int			i;

	i = -1;
	putspace = flag.width - ft_strlen(nbr);
	if (flag.width > 0 && flag.point > 0 && !flag.precision)
	{
		if (flag.hashtag > 0)
			putspace -= 2;
		if (dig == 0)
		{
			putspace = flag.width;
			nbr[0] = '\0';
		}
	}
	return (nb_char);
}
