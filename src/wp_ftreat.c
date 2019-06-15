/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wp_ftreat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/20 19:35:54 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/15 15:32:06 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

static char	*ft_rounded1(double flo, t_flag flag, int option, t_float sfloat)
{
	if ((long)flo > 5 || ((long)flo == 5 && (flo - (long)flo) > 0.0))
	{
		sfloat.i = 1;
		while (ft_strlen(sfloat.digit) >= sfloat.i)
		{
			if (ft_strlen(sfloat.digit) == sfloat.i &&
				sfloat.digit[ft_strlen(sfloat.digit) - sfloat.i] == '9')
				sfloat.enti += 1;
			if (sfloat.digit[ft_strlen(sfloat.digit) - sfloat.i] != '9')
			{
				sfloat.digit[ft_strlen(sfloat.digit) - sfloat.i] += 1;
				break ;
			}
			else if (sfloat.digit[ft_strlen(sfloat.digit) - sfloat.i] == '9')
				sfloat.digit[ft_strlen(sfloat.digit) - sfloat.i] = '0';
			sfloat.i++;
		}
		if (ft_strlen(sfloat.digit) == 0)
			sfloat.enti += 1;
	}
	sfloat.temp = ft_itoa_base(sfloat.enti, 10);
	if (!option)
		return (sfloat.digit);
	return (sfloat.temp);
}

static char	*ft_rounded(double flo, t_flag flag, int option)
{
	t_float		sfloat;

	sfloat.preci = flag.precision;
	sfloat.enti = (long)flo;
	flo = flo - (double)sfloat.enti;
	if (!(sfloat.digit = ft_strnew(0)))
		return (NULL);
	while (sfloat.preci--)
	{
		flo = flo * 10;
		sfloat.itoa = ft_itoa_base((long)flo, 10);
		if (!(sfloat.temp = ft_strjoin(sfloat.digit,
			sfloat.itoa)))
			return (NULL);
		flo = flo - (long)flo;
		free(sfloat.digit);
		sfloat.digit = ft_strdup(sfloat.temp);
		free(sfloat.temp);
	}
	flo = ft_pow10(flo, 1);
	if ((long)flo == 5 && (flag.precision == 1 || (flag.precision == 0 &&
		flag.point == 1)) && (sfloat.enti % 2 == 1))
		sfloat.enti += 1;
	return (ft_rounded1(flo, flag, option, sfloat));
}

static char	*ft_ftoa(double f, t_flag flag)
{
	char		*nb;
	char		*temp;
	int			zero;

	if (!(nb = ft_rounded(f, flag, 1)))
		return (NULL);
	if (flag.point && flag.precision == 0)
		return (nb);
	if (!(temp = ft_strjoin(nb, ".")))
		return (NULL);
	free(nb);
	zero = flag.precision - ft_strlen(ft_rounded(f, flag, 0));
	if (!(nb = ft_strjoin(temp, ft_rounded(f, flag, 0))))
		return (NULL);
	while (zero-- != 0)
	{
		free(temp);
		temp = ft_strdup(nb);
		free(nb);
		if (!(nb = ft_strjoin(temp, "0")))
			return (NULL);
	}
	return (nb);
}

static	int	ft_print_before(t_flag flag, int putspace, int nb_char, double nb)
{
	if (flag.space)
		nb_char += ft_putchar_add(' ');
	if (putspace > 0 && !flag.minus)
	{
		while (putspace--)
		{
			if (flag.zero)
				nb_char += ft_putchar_add('0');
			else
				nb_char += ft_putchar_add(' ');
		}
	}
	if (flag.plus)
	{
		if (nb >= 0)
			nb_char += ft_putchar_add('+');
		if (nb < 0)
			nb_char += ft_putchar_add('-');
	}
	return (nb_char);
}

int			wp_ftreat(t_flag flag, double nb)
{
	int		nb_char;
	char	*str;
	int		putspace;

	if (!flag.point)
		flag.precision = 6;
	str = ft_ftoa(nb, flag);
	nb_char = 0;
	putspace = (str) ? flag.width - ft_strlen(str) - flag.plus :
										flag.width - flag.plus;
	if ((flag.hashtag && flag.point && !flag.precision) || flag.space)
		putspace -= 1;
	nb_char = ft_print_before(flag, putspace, nb_char, nb);
	if (str)
		nb_char += ft_strlen(str);
	ft_putstr(str);
	if (flag.hashtag && flag.point && !flag.precision)
		nb_char += ft_putchar_add('.');
	if (putspace > 0 && flag.minus)
		while (putspace--)
			nb_char += ft_putchar_add(' ');
	free(str);
	return (nb_char);
}
