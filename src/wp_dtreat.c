/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wp_dtreat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:42:08 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/17 18:42:31 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

int				is_minus(char *len)
{
	if (len[0] == '-')
		return (1);
	return (0);
}

int				wp_dtreat(t_flag flag, long long dig)
{
	int			i;
	int			nb_char;
	char		*len;

	nb_char = 0;
	i = -1;
	len = nbr_dig(dig, flag, len);
	nb_char = d_treat_1(flag, dig, len, nb_char);
	nb_char = d_treat_2(flag, dig, len, nb_char);
	nb_char = d_treat_3(flag, dig, len, nb_char);
	if (flag.plus > 0 && !flag.precision && !flag.width && dig >= 0)
		nb_char = char_treat('+', nb_char);
	if (flag.width && flag.point && flag.precision)
	{
		nb_char = d_treat_4(flag, dig, len, nb_char);
		nb_char = d_treat_5(flag, dig, len, nb_char);
		nb_char = d_treat5bis(flag, dig, len, nb_char);
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
		ft_putchar('0');
	putspace = flag.width - ft_strlen(len);
	if (flag.plus > 0 && ((flag.width > 0 && flag.point > 0 &&
		flag.precision > flag.width)
		|| (!flag.width && flag.point > 0)) && dig >= 0)
		nb_char = char_treat('+', nb_char);
	if (flag.space > 0 && !flag.plus && flag.width <= ft_strlen(len))
		nb_char = char_treat(' ', nb_char);
	if (dig == 0 && flag.width & flag.point)
	{
		if ((size_t)flag.width > 0)
			while (++i < (size_t)flag.width)
				nb_char = char_treat(' ', nb_char);
	}
	return (nb_char);
}

int				d_treat_2(t_flag flag, long long dig, char *len, int nb_char)
{
	int			i;
	int			putspace;

	putspace = flag.width - ft_strlen(len);
	i = -1;
	if (flag.width > 0 && !flag.precision)
	{
		if (dig == 0 && !flag.minus)
			putspace = flag.width;
		if (dig < 0 && flag.zero)
			ft_putchar('-');
		if ((size_t)flag.width > ft_strlen(len))
		{
			while (++i < putspace)
				if (flag.zero > 0 && !flag.point)
					nb_char = char_treat('0', nb_char);
				else
					nb_char = char_treat(' ', nb_char);
		}
	}
	if (dig < 0 && !flag.zero && !flag.point && flag.width && !flag.minus)
		ft_putchar('-');
	return (nb_char);
}

int				d_treat_3(t_flag flag, long long dig, char *len, int nb_char)
{
	int			putspace;
	int			i;

	putspace = 0;
	i = -1;
	if (flag.point > 0 && !flag.width)
	{
		putspace = flag.precision - ft_strlen(len);
		if (is_minus(len) == 1 && flag.precision > 0)
			ft_putchar('-');
		if (dig < 0)
			putspace += 1;
		if ((size_t)flag.precision > ft_strlen(len))
			while (++i < putspace)
				nb_char = char_treat('0', nb_char);
	}
	return (nb_char);
}
