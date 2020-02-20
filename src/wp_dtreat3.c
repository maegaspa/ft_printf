/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wp_dtreat3.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/28 15:49:15 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/28 16:01:43 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

int				d_treat5bis(t_flag flag, long long dig, char *len, int nb_char)
{
	int			putspace;
	int			i;

	putspace = flag.precision - ft_strlen(len);
	i = -1;
	if (((size_t)flag.precision > ft_strlen(len)
		&& flag.precision > flag.width && (!(dig < 0)))
		|| (flag.precision && (!(dig == 0)) && !flag.minus && (!(dig < 0))))
		while (++i < putspace)
			nb_char = char_treat('0', nb_char);
	return (nb_char);
}

int				d_treat5ter(t_flag flag, long long dig, char *len, int nb_char)
{
	int			putspace;
	int			i;

	i = -1;
	if (dig < 0 && flag.precision && flag.width && flag.point)
	{
		putspace = flag.width - ft_strlen(len) - 2;
		if (flag.precision < ft_strlen(len))
			putspace = flag.width - flag.precision - 3;
		i = -1;
		if ((size_t)flag.width > ft_strlen(len))
			while (++i < putspace)
				nb_char = char_treat(' ', nb_char);
		ft_putchar('-');
		putspace = flag.precision - ft_strlen(len) + 1;
		i = -1;
		if (flag.precision > 1)
			while (++i < putspace)
				nb_char = char_treat('0', nb_char);
		i = 0;
		while (len[++i] != '\0')
			ft_putchar(len[i]);
	}
	return (nb_char);
}

int				d_treat_6(t_flag flag, long long dig, char *len, int nb_char)
{
	if (dig == 0 && flag.width == 0 && flag.precision > 0)
	{
		len[0] = '\0';
		nb_char = char_treat('0', nb_char);
	}
	if (dig == 0 && flag.width && !flag.point && flag.zero)
		len[0] = '\0';
	if (dig == 0 && !flag.space && flag.point)
		len[0] = '\0';
	if (dig == 0 && flag.space && flag.point && !flag.width && !flag.precision)
		len[0] = '\0';
	return (nb_char);
}

int				d_treat_7(t_flag flag, long long dig, char *len, int nb_char)
{
	int			i;

	i = 0;
	if (dig == 0 && (flag.width || flag.point))
		return (nb_char);
	else if (flag.minus > 0 && !flag.precision)
		return (nb_char);
	else if (flag.minus > 0 && (flag.width > flag.precision) && flag.point)
		return (nb_char);
	else if (dig < 0 && flag.precision && flag.width && flag.point)
		return (nb_char);
	else if (dig < 0 && ((!flag.precision && flag.width)
		|| (flag.precision && !flag.width)))
		while (len[++i] != '\0')
			ft_putchar(len[i]);
	else
		ft_putstr(len);
	return (nb_char);
}
