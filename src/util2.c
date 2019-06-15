/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util2.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/14 17:55:34 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/15 14:56:28 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

int			is_option(char p)
{
    if (p == 's' || p == 'd' || p == 'i' || p == 'o' || p == 'u' || p == 'x' || p == 'X'
        || p == 'c' || p == 'p' || p == 'l' || p == 'L' || p == 'f' || p == 'h')
        return (1);
    return (0);
}
/* 
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
*/
int			is_conv(char c)
{
    if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o'
		|| c == 'u' || c == 'x' || c == 'X' || c == 'f' || c == '\0' || c == '%')
        return (1);
    return (0);
}

int				ft_putstr_add(char const *str)
{
	if (str != NULL)
		write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

char            *ft_itoa_base(int value, int base)
{
    int         i;
    char        *nbr;
    int         neg;

    i = 1;
    neg = 0;
    if (value < 0)
    {
        if (base == 10)
            neg = 1;
        value *= -1;
    }
    while (ft_pow(base, i) - 1 < value)
        i++;
    if (!(nbr = (char *)malloc(sizeof(nbr) * i)))
        return (NULL);
    nbr[i + neg] = '\0';
    while (i-- > 0)
    {
        nbr[i + neg] = (value % base) + (value % base > 9 ? 'a' - 10 : '0');
        value = value / base;
    }
    if (neg)
        nbr[0] = '-';
    return (nbr);
}
