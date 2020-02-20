/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wp_ftreat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/20 19:35:54 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/28 15:48:38 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

static int		ft_rounded1(double flo, t_flag flag, t_float *sfloat)
{
	if ((long)flo > 5 || ((long)flo == 5 && (flo - (long)flo) > 0.0))
	{
		while (ft_strlen(sfloat->digit) >= sfloat->i)
		{
			if (ft_strlen(sfloat->digit) == sfloat->i &&
				sfloat->digit[ft_strlen(sfloat->digit) - sfloat->i] == '9')
				sfloat->enti += 1;
			if (sfloat->digit[ft_strlen(sfloat->digit) - sfloat->i] != '9')
			{
				sfloat->digit[ft_strlen(sfloat->digit) - sfloat->i] += 1;
				break ;
			}
			else if (sfloat->digit[ft_strlen(sfloat->digit) - sfloat->i] == '9')
				sfloat->digit[ft_strlen(sfloat->digit) - sfloat->i] = '0';
			sfloat->i++;
		}
		if (ft_strlen(sfloat->digit) == 0)
			sfloat->enti += sfloat->enti / ABS(sfloat->enti);
	}
	else if ((long)flo == 5 && (flag.precision == 1 || (flag.precision == 0 &&
		flag.point == 1)) && (sfloat->enti % 2 == 1))
		sfloat->enti += 1;
	if (!(sfloat->temp = ft_itoa_base(sfloat->enti, 10)))
		return (0);
	return (1);
}

static int		ft_rounded2(double flo, t_flag flag, t_float *sfloat)
{
	if (!(sfloat->itoa = ft_itoa_base(ABS((long)flo), 10)))
		return (0);
	if (!(sfloat->temp = ft_strjoin(sfloat->digit,
		sfloat->itoa)))
		return (0);
	free(sfloat->itoa);
	free(sfloat->digit);
	if (!(sfloat->digit = ft_strdup(sfloat->temp)))
		return (0);
	free(sfloat->temp);
	return (1);
}

static char		*ft_rounded(double flo, t_flag flag, int option)
{
	t_float		sfloat;

	if (!(ft_sfloatinit(flo, flag, &sfloat)))
		return (NULL);
	flo = flo - (double)sfloat.enti;
	while (sfloat.preci--)
	{
		flo = flo * 10;
		if (!(ft_rounded2(flo, flag, &sfloat)))
			return (NULL);
		flo = flo - (long)flo;
	}
	if (!(ft_rounded1(ft_pow10(ABS(flo), 1), flag, &sfloat)))
	{
		free(sfloat.digit);
		free(sfloat.temp);
		return (NULL);
	}
	if (option)
	{
		free(sfloat.digit);
		return (sfloat.temp);
	}
	free(sfloat.temp);
	return (sfloat.digit);
}

static char		*ft_ftoa(double f, t_flag flag)
{
	char		*nb;
	char		*temp;
	int			zero;
	char		*caleak;

	if (!(nb = ft_rounded(f, flag, 1)))
		return (NULL);
	if (flag.point && flag.precision == 0)
		return (nb);
	if (!(temp = ft_strjoin(nb, ".")))
		return (NULL);
	free(nb);
	nb = ft_rounded(f, flag, 0);
	zero = flag.precision - ft_strlen(nb);
	free(nb);
	if (!(caleak = ft_rounded(f, flag, 0)))
		return (NULL);
	if (!(nb = ft_strjoin(temp, caleak)))
		return (NULL);
	free(caleak);
	if (!(ft_putzero(zero, &temp, &nb)))
		return (NULL);
	free(temp);
	return (nb);
}

int				wp_ftreat(t_flag flag, double nb)
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
	nb_char += ft_print_before(flag, putspace, str, nb);
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
