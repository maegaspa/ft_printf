/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   nsm.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/13 16:07:29 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/22 17:41:14 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

void		init(t_flag *flags)
{
	flags->hashtag = 0;
	flags->plus = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->point = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->space = 0;
	flags->l = 0;
	flags->h = 0;
	flags->ll = 0;
}

t_flag		compt_flags(t_flag flags, t_compt cpt, char *str)
{
	if (str[cpt.j - 1] == '#' && flags.hashtag < 1)
		flags.hashtag++;
	if (str[cpt.j - 1] == '+' && flags.plus < 1)
		flags.plus++;
	if (str[cpt.j - 1] == '-' && flags.minus < 1)
		flags.minus++;
	if (str[cpt.j - 1] == '0' && flags.zero < 1 &&
			!is_conv(str[cpt.j]) && !ft_isdigit(str[cpt.j - 2]))
		flags.zero++;
	if (if_is_true(str, flags, cpt))
	{
		flags.point++;
		flags.tmp = cpt.j - 1;
	}
	if (str[cpt.j - 1] == ' ' && flags.space < 1)
		flags.space++;
	if (str[cpt.j - 1] == 'l' && flags.l < 2)
		flags.l++;
	if (str[cpt.j - 1] == 'h' && flags.h < 2)
		flags.h++;
	if (str[cpt.j - 1] == 'L' && flags.ll < 1)
		flags.ll++;
	return (flags);
}

int			give_info(t_compt *compt, t_flag flags, va_list va, char *str)
{
	compt->j = compt->i + 1;
	flags.tmp = 0;
	init(&flags);
	while (!(is_conv(str[compt->j++])))
		if ((is_no_flag(compt, &flags, str) == 1))
			return (1);
	flags.conv = str[compt->j - 1];
	if (!(compt->num = ft_strsub(str, compt->i, (compt->j - compt->i))))
		return (0);
	compt->num2 = NULL;
	if (flags.point)
		if (!(compt->num2 = ft_strsub(str, flags.tmp + 1,
						(compt->j - flags.tmp - 1))))
			return (0);
	if (compt->num2 == NULL)
		flags.precision = 0;
	else
		flags.precision = ft_atoi_2(compt->num2);
	flags.width = ft_atoi_2(compt->num);
	compt->i = compt->j - 1;
	compt->nb = resolve_option(str, va, flags, compt->nb);
	ft_strdel(&compt->num);
	ft_strdel(&compt->num2);
	return (1);
}

int			if_is_true(char *str, t_flag flags, t_compt cpt)
{
	if (str[cpt.j - 1] == '.' && ((ft_isdigit(str[cpt.j - 2]) ||
		ft_isdigit(str[cpt.j])) || str[cpt.j - 2] == ' '
		|| str[cpt.j - 2] == '+' || str[cpt.j - 2] == '#'
		|| (str[cpt.j - 2] == '%'
		&& is_conv(str[cpt.j]))))
		return (1);
	else
		return (0);
}

int			parse(char *str, va_list va)
{
	t_flag		flags;
	t_compt		compt;

	compt.nb = 0;
	compt.i = -1;
	while (str[++compt.i])
	{
		if (str[compt.i] != '%')
		{
			ft_putchar(str[compt.i]);
			compt.nb++;
		}
		if (str[compt.i] == '%' && str[compt.i + 1] != '\0')
			if (!(give_info(&compt, flags, va, str)))
				return (0);
	}
	va_end(va);
	return (compt.nb);
}
