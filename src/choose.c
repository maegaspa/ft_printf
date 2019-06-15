/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   choose.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/15 14:12:02 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/15 16:59:06 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

char			*nbr_dig(long long dig, t_flag flag, char *str)
{
	if (flag.conv == 'u')
	{
		if (flag._l)
			str = ft_ulltoa(dig);
		else if (flag._h == 1)
			str = ft_uhtoa(dig);
		else if (flag._h == 2)
			str = ft_hhtoa(dig);
		else
			str = ft_utoa(dig);
	}
	if (flag.conv == 'i' || flag.conv == 'd')
	{
		if (flag._l)
			str = ft_lltoa(dig);
		else if (flag._h == 1)
			str = ft_htoa(dig);
		else if (flag._h == 2)
			str = ft_hhtoa(dig);
		else
			str = ft_itoa(dig);
	}
	return (str);
}

int				choose_xo(t_flag flag, va_list ap, int nb_char, t_out out)
{
	char		*nbr;

	if (flag.conv == 'x' || flag.conv == 'X')
	{
		out.yessai = va_arg(ap, unsigned long long);
		nb_char += wp_oxtreat(flag, out.yessai);
	}
	if (flag.conv == 'p')
	{
		out.void_pointer = va_arg(ap, void*);
		nb_char += wp_oxtreat(flag, (unsigned long long)out.void_pointer);
	}
	if (flag.conv == 'o')
	{
		out.o = va_arg(ap, unsigned long);
		nb_char += wp_otreat(flag, out.o);
	}
	return (nb_char);
}

int				choose_dig(t_flag flag, int nb_char, va_list ap, t_out out)
{
	if (flag._l && flag.conv == 'u')
		nb_char += choose_dig_1(ap, flag, out, nb_char);
	else if (flag.conv == 'u' && !flag._h && flag._l)
		nb_char += choose_dig_2(ap, flag, out, nb_char);
	else if (flag.conv == 'u' && flag._h)
	{
		out.sh_int = va_arg(ap, unsigned short);
		nb_char += wp_utreat(flag, out.sh_int);
	}
	else if (flag._l && (flag.conv == 'd' || flag.conv == 'i'))
	{
		out.ld = va_arg(ap, long long);
		nb_char += wp_dtreat(flag, out.ld);
	}
	else if (flag.conv == 'u' && !flag._h && !flag._l)
	{
		out.uns_integ = va_arg(ap, unsigned int);
		nb_char += wp_utreat(flag, out.uns_integ);
	}
	else
	{
		out.integ = va_arg(ap, int);
		nb_char += wp_dtreat(flag, out.integ);
	}
	return (nb_char);
}

int				choose_dig_1(va_list ap, t_flag flag, t_out out, int nb_char)
{
	out.yessai = va_arg(ap, unsigned long long);
	nb_char = wp_utreat(flag, out.yessai);
	return (nb_char);
}

int				choose_dig_2(va_list ap, t_flag flag, t_out out, int nb_char)
{
	out.uns_integ = va_arg(ap, unsigned int);
	nb_char = wp_utreat(flag, out.uns_integ);
	return (nb_char);
}
