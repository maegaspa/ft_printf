/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wp_dtreat2.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/14 17:05:13 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/28 16:17:30 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

int				d_treat_2bis(t_flag flag, long long dig, char *len, int nb_char)
{
	int			i;
	int			putspace;

	putspace = flag.width - ft_strlen(len);
	i = -1;
	if (flag.width && !flag.precision && flag.point && dig > 0)
	{
		while (++i < putspace)
			if (flag.width > ft_strlen(len))
				nb_char = char_treat(' ', nb_char);
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

int				d_treat_4(t_flag flag, long long dig, char *len, int nb_char)
{
	int			putspace;
	int			i;

	i = -1;
	if (flag.minus > 0 && (!(dig < 0)) && flag.width > flag.precision)
	{
		if (flag.plus)
			nb_char = char_treat('+', nb_char);
		putspace = flag.precision - ft_strlen(len);
		if ((size_t)flag.precision > ft_strlen(len))
			while (++i < putspace)
				nb_char = char_treat('0', nb_char);
		ft_putstr(len);
	}
	putspace = flag.width - ft_strlen(len);
	if (flag.precision > ft_strlen(len))
		putspace = flag.width - flag.precision;
	if (flag.plus > 0)
		putspace -= 1;
	i = -1;
	if ((size_t)flag.width > ft_strlen(len) && dig > 0)
		while (++i < putspace)
			nb_char = char_treat(' ', nb_char);
	return (nb_char);
}

int				d_treat_5(t_flag flag, long long dig, char *len, int nb_char)
{
	int			putspace;
	int			i;

	i = -1;
	if (flag.width > flag.precision && flag.plus && !flag.minus && !flag.zero)
		nb_char = char_treat('+', nb_char);
	if (dig == 0 && flag.width > flag.precision)
	{
		if (flag.plus)
			nb_char = char_treat('+', nb_char);
		putspace = flag.width - flag.precision - 1;
		while (++i < putspace && !flag.zero)
			nb_char = char_treat(' ', nb_char);
		i = -1;
		if (flag.plus > 0)
			putspace -= 1;
		while (++i < putspace && flag.zero)
			nb_char = char_treat('0', nb_char);
	}
	if (flag.plus > 0 && !flag.minus && (!(flag.width > flag.precision)))
		nb_char = char_treat('+', nb_char);
	return (nb_char);
}
