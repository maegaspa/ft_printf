/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   nsm.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/13 16:07:29 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/17 18:42:23 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flag			flag_init(t_flag flag)
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

int				parse_2(t_compt *compt, t_flag flags, int nb_char, char *str)
{
	if (str[compt->i] != '%')
	{
		ft_putchar(str[compt->i]);
		nb_char++;
	}
	compt->m = 0;
	if (str[compt->i] == '%' && str[compt->i + 1] == '%')
	{
		while (str[compt->i] == '%')
		{
			compt->i++;
			compt->m++;
		}
		ft_putncaract('%', (compt->m / 2));
		nb_char += compt->m / 2;
		compt->i--;
	}
	return (nb_char);
}

void			parse_3(t_compt *compt, t_flag *flags, char *str)
{
	if (str[compt->j] == '#' && flags->hashtag < 1)
		flags->hashtag++;
	if (str[compt->j] == '+' && flags->plus < 1)
		flags->plus++;
	if (str[compt->j] == '-' && flags->minus < 1)
		flags->minus++;
	if (str[compt->j] == '0' && flags->zero < 1 &&
		!is_conv(str[compt->j + 1]) && !ft_isdigit(str[compt->j - 1]))
		flags->zero++;
	if (str[compt->j] == '.' && ((ft_isdigit(str[compt->j - 1])
		|| ft_isdigit(str[compt->j + 1])) || str[compt->j - 1] == ' '
		|| str[compt->j - 1] == '#' || str[compt->j - 1] == '+'
		|| (str[compt->j - 1] == '%' && (is_conv(str[compt->j + 1])))))
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

int				parse_4(t_compt *compt, t_flag *flags, char *str)
{
	flags->conv = str[compt->j];
	if (!(compt->num = ft_strsub(str, compt->i, (compt->j - compt->i + 1))))
		return (0);
	if (flags->point)
		if (!(compt->num2 = ft_strsub(str, compt->k + 1,
			(compt->j - compt->k))))
			return (0);
	flags->precision = ft_atoi_2(compt->num2);
	flags->width = ft_atoi_2(compt->num);
	compt->i = compt->j;
	return (1);
}

int				parse(char *str, va_list ap)
{
	t_flag		flags;
	t_compt		compt;
	int			nb_char;

	nb_char = 0;
	compt.i = -1;
	while (str[++compt.i])
	{
		nb_char = parse_2(&compt, flags, nb_char, str);
		if (str[compt.i] == '%' && (str[compt.i + 1]
			!= '%' && str[compt.i + 1] != '\0'))
		{
			compt.j = compt.i;
			compt.k = 0;
			flags = flag_init(flags);
			compt.num2 = ft_strnew(0);
			while (!(is_conv(str[++compt.j])))
				parse_3(&compt, &flags, str);
			parse_4(&compt, &flags, str);
			nb_char = resolve_option(str, ap, flags, nb_char);
			free_compt(&compt);
		}
	}
	va_end(ap);
	return (nb_char);
}

void			free_compt(t_compt *compt)
{
	free(compt->num);
	free(compt->num2);
}

int				ft_printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	return (parse((char *)format, ap));
}

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
	/* if (flag.conv == 'f')
	{
		if (flag._L)
			out.doub = va_arg(ap, long double);
		else
			out.doub = va_arg(ap, double);
		nb_char += wp_ftreat(flag, out.doub);
	}*/
	if (flag.conv == 'x' || flag.conv == 'X'
		|| flag.conv == 'o' || flag.conv == 'p')
		nb_char = choose_xo(flag, ap, nb_char, out);
	va_end(ap);
	return (nb_char);
}
