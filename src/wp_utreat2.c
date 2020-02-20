/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wp_utreat2.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/14 17:50:52 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/28 16:35:27 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

int				u_treat_5(t_flag flag, long long dig, char *nbr, int nb_char)
{
	int			putspace;
	int			i;

	i = -1;
	putspace = 0;
	if (flag.width && flag.point && flag.precision)
	{
		putspace = flag.width - ft_strlen(nbr);
		if (flag.width > ft_strlen(nbr) && flag.precision > ft_strlen(nbr))
			putspace = flag.width - ft_strlen(nbr) -
			(flag.precision - ft_strlen(nbr));
		if ((size_t)flag.width > ft_strlen(nbr) + flag.precision)
			while (++i < putspace)
				nb_char = char_treat(' ', nb_char);
		putspace = flag.precision - ft_strlen(nbr);
		i = -1;
		if ((size_t)flag.precision > ft_strlen(nbr))
			while (++i < putspace)
				nb_char = char_treat('0', nb_char);
	}
	return (nb_char);
}

int				u_treat_5bis(t_flag flag, long long dig, char *nbr, int nb_char)
{
	int			putspace;
	int			i;

	i = -1;
	putspace = 0;
	if (flag.width > 0 && flag.point > 0 && !flag.precision && flag.minus > 0)
	{
		putspace = flag.width - ft_strlen(nbr);
		if ((size_t)flag.width > ft_strlen(nbr))
			while (++i < putspace)
				nb_char = char_treat(' ', nb_char);
	}
	return (nb_char);
}

int				u_treat_6(t_flag flag, long long dig, char *nbr, int nb_char)
{
	if (dig == 0 && flag.point && !flag.width && !flag.precision)
		nbr[0] = '\0';
	if (dig == 0 && !flag.precision && !flag.point
		&& !flag.hashtag && !flag.minus)
		ft_putchar('0');
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

int				u_treat_7(t_flag flag, long long dig, char *nbr, int nb_char)
{
	int			putspace;
	int			i;

	putspace = 0;
	i = -1;
	if (flag.width > 0 && flag.point > 0 && !flag.precision && flag.minus > 0)
	{
		putspace = flag.width - ft_strlen(nbr);
		if ((size_t)flag.width > ft_strlen(nbr))
			while (++i < putspace)
				nb_char = char_treat(' ', nb_char);
	}
	if (flag.width > 0 && flag.point > 0 && flag.precision && flag.minus > 0)
	{
		putspace = flag.width - ft_strlen(nbr);
		if ((size_t)flag.width > ft_strlen(nbr))
			while (++i < putspace)
				nb_char = char_treat(' ', nb_char);
	}
	return (nb_char);
}
