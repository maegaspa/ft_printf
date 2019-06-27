/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolve.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/18 12:58:27 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 15:01:30 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

int				resolve_option(char *str, va_list ap, t_flag flag, int nb_char)
{
	int			i;
	char		*nbr;
	t_out		out;

	i = -1;
	if (flag.conv == 'd' || flag.conv == 'i' || flag.conv == 'u')
		nb_char = choose_dig(flag, nb_char, ap, out);
	if (flag.conv == 's')
		nb_char += wp_streat(flag, ap);
	if (flag.conv == 'c' || flag.conv == '%')
		nb_char += wp_ctreat(flag, ap);
	if (flag.conv == 'f')
	{
		if (flag.ll)
			out.doub = va_arg(ap, long double);
		else
			out.doub = va_arg(ap, double);
		nb_char += wp_ftreat(flag, out.doub);
	}
	if (flag.conv == 'x' || flag.conv == 'X'
		|| flag.conv == 'o' || flag.conv == 'p')
		nb_char = choose_xo(flag, ap, nb_char, out);
	return (nb_char);
}

int				is_no_flag(t_compt *compt, t_flag *flags, char *str)
{
	if (!ft_is_in_string(str[compt->j]))
	{
		if (ft_strchr("lhL", str[compt->j - 1]))
			compt->i = compt->j;
		else
			compt->i = compt->j - 1;
		return (1);
	}
	*flags = compt_flags(*flags, *compt, str);
	return (0);
}
