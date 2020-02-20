/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wp_dtreat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:42:08 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/28 16:28:14 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

int				wp_dtreat(t_flag flag, long long dig)
{
	int			nb_char;
	char		*len;

	nb_char = 0;
	len = nbr_dig(dig, flag, len);
	if (flag.width && flag.plus && !flag.point && dig >= 0)
		nb_char = char_treat('+', nb_char);
	nb_char = d_treat_1(flag, dig, len, nb_char);
	nb_char = d_treat_1bis(flag, dig, len, nb_char);
	nb_char = d_treat_2(flag, dig, len, nb_char);
	nb_char = d_treat_2bis(flag, dig, len, nb_char);
	nb_char = d_treat_3(flag, dig, len, nb_char);
	if ((flag.plus > 0 && !flag.precision && !flag.width && dig >= 0))
		nb_char = char_treat('+', nb_char);
	if (flag.width && flag.point && flag.precision)
	{
		nb_char = d_treat_4(flag, dig, len, nb_char);
		nb_char = d_treat_5(flag, dig, len, nb_char);
		nb_char = d_treat5bis(flag, dig, len, nb_char);
		nb_char = d_treat5ter(flag, dig, len, nb_char);
	}
	nb_char = d_treat_6(flag, dig, len, nb_char);
	nb_char = d_treat_7(flag, dig, len, nb_char);
	return (ft_strlen(len) + nb_char);
}

int				d_treat_1(t_flag flag, long long dig, char *len, int nb_char)
{
	int			i;
	int			putspace;

	i = -1;
	putspace = 0;
	if (flag.minus > 0 && flag.precision < 1 && (!(dig == 0)))
		ft_putstr(len);
	if (flag.minus > 0 && flag.width && !flag.point && dig == 0)
		nb_char = char_treat('0', nb_char);
	putspace = flag.width - ft_strlen(len);
	if (flag.plus > 0 && dig >= 0 && ((flag.width > 0 && flag.point > 0 &&
		flag.precision > flag.width)
		|| (!flag.width && flag.point > 0)))
		nb_char = char_treat('+', nb_char);
	if (flag.space > 0 && !flag.plus &&
		flag.width <= ft_strlen(len) && dig >= 0)
		nb_char = char_treat(' ', nb_char);
	return (nb_char);
}

int				d_treat_1bis(t_flag flag, long long dig, char *len, int nb_char)
{
	int			i;
	int			putspace;

	i = -1;
	if (dig == 0 && flag.width && flag.point)
	{
		putspace = flag.width;
		if (flag.width > flag.precision)
			putspace = flag.width - flag.precision;
		if (flag.plus > 0)
			putspace -= 1;
		if ((size_t)flag.width > 0)
			while (++i < putspace)
				nb_char = char_treat(' ', nb_char);
		putspace = flag.precision;
		i = -1;
		if (flag.precision && !flag.plus)
			while (++i < putspace)
				nb_char = char_treat('0', nb_char);
	}
	return (nb_char);
}

int				d_treat_2(t_flag flag, long long dig, char *len, int nb_char)
{
	int			i;
	int			putspace;

	putspace = flag.width - ft_strlen(len);
	i = -1;
	if (flag.width > 0 && !flag.precision && !flag.point)
	{
		if (dig == 0 && !flag.minus)
			putspace = flag.width;
		if (flag.space)
		{
			nb_char = char_treat(' ', nb_char);
			putspace -= 1;
		}
		putspace = d_treat_2plus(flag, dig, len, putspace);
		if ((size_t)flag.width > ft_strlen(len))
		{
			while (++i < putspace)
				if (flag.zero > 0 && !flag.point && !flag.minus)
					nb_char = char_treat('0', nb_char);
				else
					nb_char = char_treat(' ', nb_char);
		}
	}
	return (nb_char);
}

int				d_treat_2plus(t_flag flag, long long dig, char *len, int put)
{
	if (dig < 0 && flag.zero && !flag.minus)
		ft_putchar('-');
	if (flag.plus > 0 && dig >= 0)
		put -= 1;
	return (put);
}
