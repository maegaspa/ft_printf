/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wp_oxtreat2.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/14 16:56:59 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/28 16:34:50 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

int				ox_treat_4(t_flag flag, long long dig, char *nbr, int nb_char)
{
	int			putspace;
	int			i;

	putspace = 0;
	i = -1;
	if ((flag.hashtag && flag.width && flag.point
		&& !flag.precision && (!(dig == 0))) || ((!(dig == 0) && flag.width
		&& !flag.point && flag.hashtag && !flag.minus && !flag.zero)))
	{
		if (flag.conv == 'x')
			nb_char = multichar_treat("0x", nb_char);
		if (flag.conv == 'X')
			nb_char = multichar_treat("0X", nb_char);
	}
	if (!flag.width && flag.minus > 0 && flag.point > 0 && flag.precision > 0)
	{
		putspace = flag.precision - ft_strlen(nbr) - 1;
		if (flag.hashtag > 0)
			putspace -= 2;
		if ((size_t)flag.precision > ft_strlen(nbr))
			while (++i < putspace)
				nb_char = char_treat('0', nb_char);
	}
	return (nb_char);
}

int				ox_treat_5(t_flag flag, long long dig, char *nbr, int nb_char)
{
	int			put;
	int			i;

	put = 0;
	i = -1;
	if (flag.point && flag.precision)
	{
		put = flag.width - flag.precision - ft_strlen(nbr) + 1;
		put = ox_treat_5bis(flag, dig, nbr, put);
		if (flag.width > ft_strlen(nbr) && flag.precision > ft_strlen(nbr))
			put = flag.width - ft_strlen(nbr) -
			(flag.precision - ft_strlen(nbr));
		if ((size_t)flag.width > ft_strlen(nbr) && !flag.minus && !flag.hashtag)
			while (++i < put)
				nb_char = char_treat(' ', nb_char);
		put = flag.precision - ft_strlen(nbr);
		if (dig == 0 && flag.hashtag && flag.point
			&& flag.precision && !flag.width)
			nb_char = char_treat('0', nb_char);
		i = -1;
		if ((size_t)flag.precision > ft_strlen(nbr))
			while (++i < put)
				nb_char = char_treat('0', nb_char);
	}
	return (nb_char);
}

int				ox_treat_5bis(t_flag flag, long long dig, char *nbr, int put)
{
	if (flag.width > flag.precision)
		put = flag.width - ft_strlen(nbr);
	if (flag.hashtag > 0)
		put -= 2;
	return (put);
}

int				ox_treat_6(t_flag flag, long long dig, char *nbr, int nb_char)
{
	int			putspace;
	int			i;

	putspace = 0;
	i = -1;
	if (flag.hashtag > 0 && (!(dig == 0)) &&
		((!flag.width && !flag.precision && !flag.zero && !flag.minus)))
	{
		if (flag.conv == 'x')
			nb_char = multichar_treat("0x", nb_char);
		if (flag.conv == 'X')
			nb_char = multichar_treat("0X", nb_char);
	}
	if (flag.width > 0 && !flag.point && !flag.precision
		&& flag.minus > 0 && flag.zero > 0)
	{
		putspace = flag.width - ft_strlen(nbr);
		if (flag.hashtag > 0)
			putspace -= 2;
		if ((size_t)flag.width > ft_strlen(nbr) && !flag.minus)
			while (++i < putspace)
				nb_char = char_treat('0', nb_char);
	}
	return (nb_char);
}
