/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wp_oxtreat3.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/28 16:33:32 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/28 16:34:05 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

int				ox_treat_7(t_flag flag, long long dig, char *nbr, int nb_char)
{
	if (dig == 0 && flag.point && !flag.width)
		nbr[0] = '\0';
	else if (dig == 0 && !flag.width && !flag.precision &&
		!flag.point && flag.hashtag)
		return (nb_char);
	else if (dig == 0 && flag.hashtag && !flag.precision && !flag.zero)
		nbr[0] = '\0';
	else if (flag.minus > 0 && flag.precision < 1 && (!(dig == 0)))
		return (nb_char);
	else if (dig == 0 && !flag.precision && !flag.point)
		return (nb_char);
	else if (dig == 0 && !flag.width && !flag.precision && flag.point)
		return (nb_char);
	else if (dig == 0 && flag.width && flag.point)
		return (nb_char);
	else
		flag.conv == 'X' ? ft_putstr(ft_strcaps(nbr)) : ft_putstr(nbr);
	return (nb_char);
}

int				ox_treat_8(t_flag flag, long long dig, char *nbr, int nb_char)
{
	int			putspace;
	int			i;

	i = -1;
	putspace = 0;
	if (flag.width > 0 && flag.point > 0 &&
		!flag.precision && flag.minus > 0 && !flag.zero)
	{
		putspace = flag.width - ft_strlen(nbr);
		if ((size_t)flag.width > ft_strlen(nbr))
			while (++i < putspace)
				nb_char = char_treat(' ', nb_char);
	}
	if (flag.width > 0 && flag.point && flag.precision && flag.minus > 0)
	{
		putspace = flag.width - flag.precision;
		if ((size_t)flag.width > ft_strlen(nbr))
			while (++i < putspace)
				nb_char = char_treat(' ', nb_char);
	}
	return (nb_char);
}
