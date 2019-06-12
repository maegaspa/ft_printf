/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/30 15:47:32 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 19:14:38 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

int         char_treat(char c, int nb_char)
{
    ft_putchar(c);
    nb_char++;
    return(nb_char);
}

int         multichar_treat(char *c, int nb_char)
{
    ft_putstr(c);
    nb_char += ft_strlen(c);
    return(nb_char);
}

int             ft_pow(int nb, int pow)
{
    if (pow == 0)
        return (1);
    else
        return (nb * ft_pow(nb, pow - 1));
}

int				ft_putchar_add(char c)
{
	write(1, &c, 1);
	return (1);
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

double long		ft_pow10(double long f, int exp)
{
	while (exp)
	{
		f = f * 10;
		exp--;
	}
	return (f);
}
