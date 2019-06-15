/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   nsm.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/13 16:07:29 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/15 17:12:35 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flag		flag_init(t_flag flag)
{
	flag.conv = 0;
	flag.hashtag = 0;
	flag.zero = 0;
	flag.plus = 0;
	flag.minus = 0;
	flag.point = 0;
	flag.space = 0;
	flag.width = 0;
	flag._l = 0;
	flag._L = 0;
	flag._h = 0;
	flag.precision = 0;
	return (flag);
}

t_out		out_init(void)
{
	t_out	out;

	out.integ = 0;
	out.string = 0;
	out.uns_char = 0;
	out.uns_integ = 0;
	out.lo = 0;
	out.lo_double = 0;
	out.doub = 0;
	out.sh_int = 0;
	out.void_pointer = 0;
	out.precis = 0;
	out.ld = 0;
	return (out);
}

int			parse(char *str, va_list ap)
{
	t_flag		flags;
	t_compt		compt;
	int			nb_char;

	nb_char = 0;
	compt.i = -1;
	while (str[++compt.i])
	{
		if (str[compt.i] != '%')
		{
			ft_putchar(str[compt.i]);
			nb_char++;
		}
		compt.m = 0;
		if (str[compt.i] == '%' && str[compt.i + 1] == '%')
		{
			while (str[compt.i] == '%')
			{
				compt.i++;
				compt.m++;
			}
			ft_putncaract('%', (compt.m  / 2));
			nb_char += compt.m  / 2;
			compt.i--;
		}
		if (str[compt.i] == '%' && (str[compt.i + 1] != '%' && str[compt.i + 1] != '\0'))
		{
			compt.j = compt.i + 1;
			compt.k = 0;
			flags = flag_init(flags);
			compt.num2 = ft_strnew(0);
			while (!(is_conv(str[compt.j]))) // Remplissage STRUCT FLAG
			{
				if (str[compt.j] == '#' && flags.hashtag < 1)
					flags.hashtag++;
				if (str[compt.j] == '+' && flags.plus < 1)
					flags.plus++;
				if (str[compt.j] == '-' && flags.minus < 1) //&& !is_conv(str[compt.j + 1]) && !ft_isdigit(str[compt.j - 1]))
					flags.minus++;
				if (str[compt.j] == '0' && flags.zero < 1 && !is_conv(str[compt.j + 1]) && !ft_isdigit(str[compt.j - 1]))
					flags.zero++;
				if (str[compt.j] == '.' && ((ft_isdigit(str[compt.j - 1]) || ft_isdigit(str[compt.j + 1])) || str[compt.j - 1] == ' ' || str[compt.j - 1] == '#' || str[compt.j - 1] == '+' || (str[compt.j - 1] == '%' && (is_conv(str[compt.j + 1]))))) //RAJOUT
				{
					flags.point++;
					compt.k = compt.j;
				}
				if (str[compt.j] == ' ' && flags.space < 1)
					flags.space++;
				if (str[compt.j] == 'l' && flags._l < 2)
					flags._l++;
				if (str[compt.j] == 'h' && flags._h < 2)
					flags._h++;
				if (str[compt.j] == 'L' && flags._L < 1)
					flags._L++;
				//printf("\n%c\n", str[compt.j]);
				compt.j++;
			}
			flags.conv = str[compt.j];
			if (!(compt.num = ft_strsub(str, compt.i, (compt.j - compt.i + 1))))
				return (0);
			if (flags.point)
				if (!(compt.num2 = ft_strsub(str, compt.k + 1, (compt.j - compt.k))))
					return (0);
			flags.precision = ft_atoi_2(compt.num2); // Ajout PRECISION
			flags.width = ft_atoi_2(compt.num); // Ajout LARGEUR
			compt.i = compt.j;
			//print_help(flags, compt.i);
			nb_char = resolve_option(str, ap, flags, nb_char);
		}
		//printf("{%d}\n", nb);
	}
	va_end(ap);
	return (nb_char);
}
/*
void		ft_setflag2(char *str, t_flag *flags, t_compt *compt)
{
	if (str[compt->j] == '#' && flags->hashtag < 1)
		flags->hashtag++;
	if (str[compt->j] == '+' && flags->plus < 1)
		flags->plus++;
	if (str[compt->j] == '-' && flags->minus < 1)
		flags->minus++;
	if (str[compt->j] == '0' && flags->zero < 1 && !is_conv(str[compt->j + 1]) && !ft_isdigit(str[compt->j - 1]))
		flags->zero++;
	if (str[compt->j] == '.' && ((ft_isdigit(str[compt->j - 1]) || ft_isdigit(str[compt->j + 1])) ||
		str[compt->j - 1] == ' ' || str[compt->j - 1] == '#' || str[compt->j - 1] == '+' ||
		(str[compt->j - 1] == '%' && is_conv(str[compt->j + 1]))))
	{
		flags->point++;
		compt->k = compt->j;
	}
	if (str[compt->j] == ' ' && flags->space < 1)
		flags->space++;
	if (str[compt->j] == 'l' && flags->_l < 2)
		flags->_l++;
	if (str[compt->j] == 'h' && flags->_h < 2)
		flags->_h++;
	if (str[compt->j] == 'L' && flags->_L < 1)
		flags->_L++;
}

int			ft_setflag(char *str, t_flag *flags, t_compt *compt)
{
	compt->j = compt->i;
	compt->k = 0;
	compt->num2 = ft_strnew(0);
	while (!(is_conv(str[compt->j++]))) // Remplissage STRUCT FLAG
		ft_setflag2(str, &flags, &compt);
	flags->conv = str[compt->j - 1];
	if (!(compt->num = ft_strsub(str, compt->i, (compt->j - compt->i))))
		return (0);
	if (flags->point)
		if (!(compt->num2 = ft_strsub(str, compt->k + 1, (compt->j - compt->k - 1))))
			return (0);
	flags->precision = ft_atoi_2(compt->num2); // Ajout PRECISION
	flags->width = ft_atoi_2(compt->num); // Ajout LARGEUR
	compt->i = compt->j - 1;
	return (1);
}

int			ft_normaltext(char *str, t_compt *compt)
{
	int		nb_char;

	nb_char = 0;
	if (str[compt->i] != '%')
		nb_char += ft_putchar_add(str[compt->i]);
	compt->m = 0;
	if (str[compt->i] == '%' && str[compt->i + 1] == '%')
	{
		while (str[compt->i] == '%')
		{
			compt->i++;
			compt->m++;
		}
		ft_putncaract('%', (compt->m  / 2));
		nb_char += compt->m  / 2;
		compt->i--;
	}
	return (nb_char);
}

int			parse(char *str, va_list ap)
{
	t_flag		flags;
	t_compt		compt;
	int			nb_char;

	nb_char = 0;
	compt.i = -1;
	while (str[++compt.i])
	{
		nb_char += ft_normaltext(str, &compt);
		if (str[compt.i] == '%' && (str[compt.i + 1] != '%' && str[compt.i + 1] != '\0'))
		{
			flags = flag_init(flags);
			if (!(ft_setflag(str, &flags, &compt)))
				return (0);
			nb_char = resolve_option(str, ap, flags, nb_char);
		}
	}
	va_end(ap);
	return (nb_char);
}*/

int			ft_printf(const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    return (parse((char *)format, ap));
}

int         resolve_option(char *str, va_list ap, t_flag flag, int nb_char)
{
    int         i;
    char        *nbr;
    t_out       out;

    i = -1;
    out = out_init(); //INUTIL POUR LE MOMENT
    if (flag.conv == 'd' || flag.conv == 'i' || flag.conv == 'u')
        nb_char = choose_dig(flag, nb_char, ap, out);
    if (flag.conv == 's')
		nb_char += wp_streat(flag, ap);
	if (flag.conv == 'c' || flag.conv == '%')
        nb_char += wp_ctreat(flag, ap);
	if (flag.conv == 'f')
	{
		if (flag._L)
			out.doub = va_arg(ap, long double);
		else
			out.doub = va_arg(ap, double);
		nb_char += wp_ftreat(flag, out.doub);
	}
	if (flag.conv == 'x' || flag.conv == 'X' || flag.conv == 'o' || flag.conv == 'p')
		nb_char = choose_xo(flag, ap, nb_char, out);
    va_end(ap);
    return (nb_char);
}
