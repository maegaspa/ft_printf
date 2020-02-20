/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wp_otreat2.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/14 17:19:23 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/28 16:19:45 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

int				o_treat_4(t_flag flag, long long dig, char *nbr, int nb_char)
{
	int			putspace;
	int			i;

	putspace = flag.width - ft_strlen(nbr);
	if (dig == 0)
		putspace = flag.width;
	if (flag.hashtag > 0)
		putspace -= 1;
	if ((size_t)flag.width > ft_strlen(nbr) && flag.minus)
		while (++i < putspace)
			nb_char = char_treat(' ', nb_char);
	return (nb_char);
}

int				o_treat_5(t_flag flag, long long dig, char *nbr, int nb_char)
{
	int			putspace;
	int			i;

	putspace = flag.width - ft_strlen(nbr);
	i = -1;
	if ((size_t)flag.width > ft_strlen(nbr) && !flag.minus)
	{
		if (dig == 0)
			putspace = flag.width;
		if (flag.hashtag > 0)
			putspace -= 1;
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

int				o_treat_6(t_flag flag, long long dig, char *nbr, int nb_char)
{
	int			putspace;
	int			i;

	i = -1;
	putspace = flag.width - ft_strlen(nbr);
	if (flag.width > 0 && flag.point > 0 && !flag.precision && (!(dig == 0)))
	{
		if (flag.hashtag > 0)
			putspace -= 1;
		if ((size_t)flag.width > ft_strlen(nbr) && !flag.minus)
			while (++i < putspace)
				nb_char = char_treat(' ', nb_char);
	}
	if (!flag.width && flag.minus > 0 && flag.point > 0 && flag.precision > 0)
	{
		putspace = flag.precision - ft_strlen(nbr);
		if (flag.hashtag > 0)
			putspace -= 1;
		if ((size_t)flag.precision > ft_strlen(nbr))
			while (++i < putspace)
				nb_char = char_treat('0', nb_char);
	}
	return (nb_char);
}

int				o_treat_7(t_flag flag, long long dig, char *nbr, int nb_char)
{
	int			putspace;
	int			i;

	putspace = 0;
	i = -1;
	if (flag.width && flag.point && flag.precision && (!(dig == 0)))
	{
		putspace = flag.width - ft_strlen(nbr);
		if (flag.precision > ft_strlen(nbr))
			putspace = flag.width - flag.precision;
		if ((size_t)flag.width > ft_strlen(nbr) && !flag.zero && !flag.minus)
			while (++i < putspace)
				nb_char = char_treat(' ', nb_char);
		putspace = flag.precision - ft_strlen(nbr);
		i = -1;
		if ((size_t)flag.precision > ft_strlen(nbr) && !flag.zero)
			while (++i < putspace)
				nb_char = char_treat('0', nb_char);
	}
	return (nb_char);
}

int				o_treat_7bis(t_flag flag, long long dig, char *nbr, int nb_char)
{
	int			putspace;
	int			i;

	i = -1;
	putspace = 0;
	if (dig == 0 && flag.width && flag.point && flag.precision
		&& flag.minus && flag.hashtag)
	{
		putspace = flag.precision;
		while (++i < putspace)
			nb_char = char_treat('0', nb_char);
		i = -1;
		putspace = flag.width - flag.precision;
		while (++i < putspace)
			nb_char = char_treat(' ', nb_char);
	}
	if (dig == 0 && flag.width && flag.point &&
		flag.precision && !flag.minus && !flag.hashtag)
	{
		putspace = flag.precision;
		while (++i < putspace)
			nb_char = char_treat('0', nb_char);
	}
	return (nb_char);
}
