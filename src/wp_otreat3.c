/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wp_otreat3.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/14 17:20:11 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/28 16:20:11 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

int				o_treat_8(t_flag flag, long long dig, char *nbr, int nb_char)
{
	int			putspace;
	int			i;

	putspace = 0;
	i = -1;
	if (flag.hashtag > 0 && !flag.minus &&
		((flag.zero && flag.width && flag.plus && flag.point)
		|| (flag.width && !flag.point && !flag.precision && !flag.zero)
		|| (!flag.zero && !flag.precision) ||
		(flag.width > 0 && flag.point > 0 && !flag.precision)))
		nb_char = char_treat('0', nb_char);
	if (flag.width > 0 && flag.point > 0 && !flag.precision && flag.minus > 0)
	{
		putspace = flag.width - ft_strlen(nbr);
		if (flag.hashtag > 0)
			putspace -= 1;
		if ((size_t)flag.width > ft_strlen(nbr))
			while (++i < putspace)
				nb_char = char_treat(' ', nb_char);
	}
	return (nb_char);
}

int				o_treat_9(t_flag flag, long long dig, char *nbr, int nb_char)
{
	if (dig == 0 && !flag.point && !flag.precision && flag.width < 2
		&& !flag.space && !flag.hashtag)
		nb_char = char_treat('0', nb_char);
	if (dig == 0)
		nbr[0] = '\0';
	if (flag.width > 0 && dig == 0 && flag.point && !flag.precision)
		return (nb_char);
	else if (flag.precision > 0 && dig == 0 && flag.point && !flag.width)
		return (nb_char);
	else if (dig == 0 && flag.point && !flag.precision && !flag.width)
		return (nb_char);
	else if (dig == 0 && !flag.precision && !flag.point)
		return (nb_char);
	else if (flag.minus > 0 && flag.precision <= 1 && (!(dig == 0)))
		return (nb_char);
	else
		ft_putstr(nbr);
	return (nb_char);
}

int				o_treat_10(t_flag flag, long long dig, char *nbr, int nb_char)
{
	int			putspace;
	int			i;

	putspace = 0;
	i = -1;
	if (flag.width > 0 && flag.point > 0 && !flag.precision && flag.minus > 0)
	{
		putspace = flag.width - ft_strlen(nbr);
		if (flag.hashtag > 0)
			putspace -= 1;
		if ((size_t)flag.width > ft_strlen(nbr))
			while (++i < putspace)
				nb_char = char_treat(' ', nb_char);
	}
	if (flag.width > 0 && flag.point > 0 && flag.precision > 0
		&& flag.minus > 0 && !flag.hashtag)
	{
		putspace = flag.width - ft_strlen(nbr) - 1;
		if ((size_t)flag.width > ft_strlen(nbr))
			while (++i < putspace)
				nb_char = char_treat(' ', nb_char);
	}
	return (nb_char);
}
