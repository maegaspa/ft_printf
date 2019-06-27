/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wp_streat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 17:20:00 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 15:34:37 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

static int	ft_printnull(t_flag flag, char *string)
{
	if (string)
		return (0);
	if (!flag.precision)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putchar('(');
	if (flag.precision >= 2)
		ft_putchar('n');
	if (flag.precision >= 3)
		ft_putchar('u');
	if (flag.precision >= 4)
		ft_putchar('l');
	if (flag.precision >= 5)
		ft_putchar('l');
	if (flag.precision >= 6)
		ft_putchar(')');
	return ((flag.precision <= 6) ? flag.precision : 6);
}

int			wp_streat(t_flag flag, va_list ap)
{
	char	*string;
	int		putspace;
	int		nb_char;

	nb_char = 0;
	string = va_arg(ap, char*);
	putspace = (string) ? flag.width - ft_strlen(string) : flag.width;
	putspace = (string && flag.point && flag.precision < ft_strlen(string))
		? flag.width - flag.precision : putspace;
	putspace = (!string && !flag.point && flag.width)
		? flag.width - 6 : putspace;
	if (!flag.point && flag.width <= ft_strlen(string))
		putspace = 0;
	nb_char = s_treat_1(flag, string, nb_char, putspace);
	nb_char = s_treat_2(flag, string, nb_char, putspace);
	nb_char = s_treat_3(flag, string, nb_char, putspace);
	return (nb_char);
}

int			s_treat_1(t_flag flag, char *string, int nb_char, int putspace)
{
	int		i;

	i = -1;
	if (flag.point && !flag.precision && flag.width > 0 && !flag.minus)
	{
		while (++i < flag.width)
		{
			if (flag.zero)
				nb_char = char_treat('0', nb_char);
			else
				nb_char = char_treat(' ', nb_char);
		}
	}
	return (nb_char);
}

int			s_treat_2(t_flag flag, char *string, int nb_char, int putspace)
{
	int		i;

	i = -1;
	if ((flag.width && !flag.minus && flag.precision) ||
		(flag.width && !flag.minus && !flag.point))
	{
		if (!string || (putspace > 0))
		{
			while (++i < putspace)
				if (flag.zero > 0)
					nb_char = char_treat('0', nb_char);
				else
					nb_char = char_treat(' ', nb_char);
		}
	}
	if (flag.point && flag.precision > 0)
	{
		i = 0;
		while (string && i < ft_strlen(string) && i < flag.precision)
			ft_putchar(string[i++]);
		nb_char += i;
	}
	return (nb_char);
}

int			s_treat_3(t_flag flag, char *string, int nb_char, int putspace)
{
	int		i;

	i = -1;
	if ((flag.point && flag.precision > 0) || (!flag.point && !flag.precision))
		nb_char += ft_printnull(flag, string);
	if (!flag.point)
	{
		ft_putstr(string);
		nb_char += ft_strlen(string);
	}
	if (flag.width > 0 && flag.minus)
	{
		if (!string ||
			(!flag.precision && (size_t)flag.width > ft_strlen(string)))
			while (++i < putspace)
				nb_char = char_treat(' ', nb_char);
		if (string && flag.point)
			while (nb_char < flag.width)
				nb_char = char_treat(' ', nb_char);
	}
	return (nb_char);
}
