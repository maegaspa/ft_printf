/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wp_otreat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/13 16:32:33 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/01 14:39:54 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

int			wp_otreat(t_flag flag, long long dig)
{
    int     putspace;
    int     i;
	int		nb_char;
    char    *nbr;

    putspace = 0;
    nb_char = 0;
    i = -1;
    nbr = dectoocta(dig, flag);
    nb_char = o_treat_1(flag, dig, nbr, nb_char);
    nb_char = o_treat_2(flag, dig, nbr, nb_char);
    nb_char = o_treat_3(flag, dig, nbr, nb_char);
    /*if (flag.hashtag > 0 && ((flag.zero > 0 && !flag.precision && !flag.point) || (flag.minus && !flag.precision) || (flag.point && flag.precision && !flag.width && !flag.zero)))
    {
        ft_putchar('0');
        nb_char++;
    }
    if (flag.minus > 0 && flag.precision <= 1 && (!(dig == 0)))
        ft_putstr(nbr);
    if (flag.width > 0 && dig == 0 && flag.point && !flag.precision)
    {
        putspace = flag.width;
        if (flag.hashtag > 0)
            putspace -= 1;        
        while (++i < putspace)
        {    
            ft_putchar(' ');
            nb_char++;
        }
    }*/
    /*if (flag.precision > 0 && flag.point && flag.zero)
    {
        putspace = flag.precision - ft_strlen(nbr);
        if (dig == 0)
            putspace = flag.precision;
        i = -1;
        if ((size_t)flag.precision > ft_strlen(nbr))
        {
            while (++i < putspace)
            {
                ft_putchar('0');
                nb_char++;
            }
        }
    }*/
    /*if (!flag.width && flag.point && flag.precision && !flag.minus && !flag.zero && (!(dig == 0)))
    {
        putspace = flag.precision - ft_strlen(nbr);
        while (++i < putspace)
        {
            ft_putchar('0');
            nb_char++;
        }
    }*/
    /*if (flag.precision > 0 && dig == 0 && flag.point && !flag.width && !flag.zero)
    {
        putspace = flag.precision;
        if (flag.hashtag > 0)
            putspace -= 1;
        i = -1;
        while (++i < putspace)
        {    
            ft_putchar('0');
            nb_char++;
        }
    }*/
    if (flag.width > 0 && !flag.point)
    {
        nb_char = o_treat_4(flag, dig, nbr, nb_char);
        nb_char = o_treat_5(flag, dig, nbr, nb_char);
        /*putspace = flag.width - ft_strlen(nbr);
        if (dig == 0)
            putspace = flag.width;
        if (flag.hashtag > 0)
            putspace -= 1;
        if ((size_t)flag.width > ft_strlen(nbr) && flag.minus)
        {
            while (++i < putspace)
            {
                ft_putchar(' ');
                nb_char++;
            }
        }
        putspace = flag.width - ft_strlen(nbr);
        if (dig == 0)
            putspace = flag.width;
        if (flag.hashtag > 0)
            putspace -= 1;
        if ((size_t)flag.width > ft_strlen(nbr) && !flag.minus)
        {
            while (++i < putspace)
            {
                if (flag.point > 0 || flag.zero > 0)
                {
                    ft_putchar('0');
                    nb_char++;
                }
                else
                {
                    ft_putchar(' ');
                    nb_char++;
                }
            }        
        }*/
    }
    /*if (flag.width > 0 && flag.point > 0 && !flag.precision && (!(dig == 0)))
    {
        if (flag.hashtag > 0)
            putspace -= 1;        
        if ((size_t)flag.width > ft_strlen(nbr) && !flag.minus)
        {
            while (++i < putspace)
            {
                ft_putchar(' ');
                nb_char++;
            }        
        }
    }
    if (!flag.width && flag.minus > 0 && flag.point > 0 && flag.precision > 0)
    {
        putspace = flag.precision - ft_strlen(nbr);
        if (flag.hashtag > 0)
            putspace -= 1;        
        if ((size_t)flag.precision > ft_strlen(nbr))
        {
            while (++i < putspace)
            {
                ft_putchar('0');
                nb_char++;
            }
        }
    }*/
	/*if (flag.width && flag.point && flag.precision)
	{
		putspace = flag.width - flag.precision;
		if ((size_t)flag.width > ft_strlen(nbr))
		{
			while (++i < putspace)
			{
				ft_putchar(' ');
				nb_char++;
			}
		}
		putspace = flag.precision - ft_strlen(nbr);
		i = -1;
		if ((size_t)flag.precision > ft_strlen(nbr))
        {
            while (++i < putspace)
            {
				ft_putchar('0');
                nb_char++;
            }
		}
	}*/
    /*if (flag.hashtag > 0 && !flag.minus && ((flag.zero && flag.width && flag.plus && flag.point) ||
    (flag.width && !flag.point && !flag.precision && !flag.zero) || (!flag.zero && !flag.precision) ||
    (flag.width > 0 && flag.point > 0 && !flag.precision)))
    {
        ft_putchar('0');
        nb_char++;
    }
    if (flag.width > 0 && flag.point > 0 && !flag.precision && flag.minus > 0)
    {
        putspace = flag.width - ft_strlen(nbr);
        if (flag.hashtag > 0)
            putspace -= 1;
        if ((size_t)flag.width > ft_strlen(nbr))
        {
            while (++i < putspace)
            {
                ft_putchar(' ');
				nb_char++;
            }        
        }
    }*/
    nb_char = o_treat_6(flag, dig, nbr, nb_char);
    nb_char = o_treat_7(flag, dig, nbr, nb_char);
    nb_char = o_treat_8(flag, dig, nbr, nb_char);
    /*if (flag.width > 0 && dig == 0 && flag.point && !flag.precision)
        return(ft_strlen(nbr) + nb_char);
    else if (flag.precision > 0 && dig == 0 && flag.point && !flag.width)
        return(ft_strlen(nbr) + nb_char);
    else if (dig == 0 && flag.point && !flag.precision && !flag.width)
        return (0);
    else if (dig == 0 && !flag.precision && !flag.point)
        return (ft_strlen(nbr) + nb_char);
    else if (flag.minus > 0 && flag.precision <= 1 && (!(dig == 0)))
        return (ft_strlen(nbr) + nb_char);
    else
        ft_putstr(nbr);*/
    nb_char = o_treat_9(flag, dig, nbr, nb_char);
    /*if (flag.width > 0 && flag.point > 0 && !flag.precision && flag.minus > 0)
    {
        putspace = flag.width - ft_strlen(nbr);
        if (flag.hashtag > 0)
            putspace -= 1;
        if ((size_t)flag.width > ft_strlen(nbr))
        {
            while (++i < putspace)
            {
                ft_putchar(' ');
				nb_char++;
            }        
        }
    }*/
    nb_char = o_treat_10(flag, dig ,nbr, nb_char);
    return (ft_strlen(nbr) + nb_char);
}

int        o_treat_1(t_flag flag, long long dig, char *nbr, int nb_char)
{
    int putspace;
    int i;

    i = -1;
    putspace = flag.width - ft_strlen(nbr);
    if (flag.hashtag > 0 && ((flag.zero > 0 && !flag.precision && !flag.point) || (flag.minus && !flag.precision)
    || (flag.point && flag.precision && !flag.width && !flag.zero)))
        nb_char = char_treat('0', nb_char);
    if (flag.minus > 0 && flag.precision <= 1 && (!(dig == 0)))
        ft_putstr(nbr);
    if (flag.width > 0 && dig == 0 && flag.point && !flag.precision)
    {
        putspace = flag.width;
        if (flag.hashtag > 0)
            putspace -= 1;        
        while (++i < putspace)
            nb_char = char_treat(' ', nb_char);
    }
	return (nb_char);
}

int        o_treat_2(t_flag flag, long long dig, char *nbr, int nb_char)
{
    int putspace;
    int i;

    i = -1;
    putspace = 0;
    if (flag.precision > 0 && flag.point && flag.zero)
    {
        putspace = flag.precision - ft_strlen(nbr);
        if (dig == 0)
            putspace = flag.precision;
        i = -1;
        if ((size_t)flag.precision > ft_strlen(nbr))
		    while (++i < putspace)
				nb_char = char_treat('0', nb_char);	
    }
    if (!flag.width && flag.point && flag.precision && !flag.minus && !flag.zero && (!(dig == 0)))
    {
        putspace = flag.precision - ft_strlen(nbr);
        while (++i < putspace)
            nb_char = char_treat('0', nb_char);
    }
	return (nb_char);
}

int        o_treat_3(t_flag flag, long long dig, char *nbr, int nb_char)
{
    int putspace;
    int i;

    putspace = 0;
    i = -1;
    if (flag.precision > 0 && dig == 0 && flag.point && !flag.width && !flag.zero)
    {
        putspace = flag.precision;
        if (flag.hashtag > 0)
            putspace -= 1;
        i = -1;
        while (++i < putspace)
            nb_char = char_treat('0', nb_char);
    }
	return (nb_char);
}

int    o_treat_4(t_flag flag, long long dig, char *nbr, int nb_char)
{
    int putspace;
    int i;

    putspace = flag.width - ft_strlen(nbr);
    if (dig == 0)
        putspace = flag.width;
    if (flag.hashtag > 0)
        putspace -= 1;
    if ((size_t)flag.width > ft_strlen(nbr) && flag.minus)
        while (++i < putspace)
            nb_char = char_treat(' ', nb_char);
    putspace = flag.width - ft_strlen(nbr);
    if (dig == 0)
        putspace = flag.width;
    if (flag.hashtag > 0)
        putspace -= 1;
	return (nb_char);
}

int        o_treat_5(t_flag flag, long long dig, char *nbr, int nb_char)
{
    int putspace;
    int i;

    putspace = 0;
    i = -1;
    if ((size_t)flag.width > ft_strlen(nbr) && !flag.minus)
    {
        while (++i < putspace)
        {
            if (flag.point > 0 || flag.zero > 0)
                nb_char = char_treat('0', nb_char);
            else
                nb_char = char_treat(' ', nb_char);
        }        
    }
	return (nb_char);
}

int        o_treat_6(t_flag flag, long long dig, char *nbr, int nb_char)
{
    int putspace;
    int i;

    i = -1;
    putspace = 0;
    if (flag.width > 0 && flag.point > 0 && !flag.precision && (!(dig == 0)))
    {
        if (flag.hashtag > 0)
            putspace -= 1;        
        if ((size_t)flag.width > ft_strlen(nbr) && !flag.minus)
            while (++i < putspace)
                nb_char = char_treat(' ', nb_char);
    }
    if (!flag.width && flag.minus > 0 && flag.point > 0 && flag.precision > 0)
    {
        putspace = flag.precision - ft_strlen(nbr);
        if (flag.hashtag > 0)
            putspace -= 1;        
        if ((size_t)flag.precision > ft_strlen(nbr))
            while (++i < putspace)
                nb_char = char_treat('0', nb_char);
    }
	return (nb_char);
}

int        o_treat_7(t_flag flag, long long dig, char *nbr, int nb_char)
{
    int putspace;
    int i;

    putspace = 0;
    i = -1;
    if (flag.width && flag.point && flag.precision)
	{
		putspace = flag.width - flag.precision;
		if ((size_t)flag.width > ft_strlen(nbr))
			while (++i < putspace)
				nb_char = char_treat(' ', nb_char);
		putspace = flag.precision - ft_strlen(nbr);
		i = -1;
		if ((size_t)flag.precision > ft_strlen(nbr))
            while (++i < putspace)
				nb_char = char_treat('0', nb_char);
	}
	return (nb_char);
}

int        o_treat_8(t_flag flag, long long dig, char *nbr, int nb_char)
{
    int putspace;
    int i;

    putspace = 0;
    i = -1;
    if (flag.hashtag > 0 && !flag.minus && ((flag.zero && flag.width && flag.plus && flag.point) ||
    (flag.width && !flag.point && !flag.precision && !flag.zero) || (!flag.zero && !flag.precision) ||
    (flag.width > 0 && flag.point > 0 && !flag.precision)))
        nb_char = char_treat('0', nb_char);
    if (flag.width > 0 && flag.point > 0 && !flag.precision && flag.minus > 0)
    {
        putspace = flag.width - ft_strlen(nbr);
        if (flag.hashtag > 0)
            putspace -= 1;
        if ((size_t)flag.width > ft_strlen(nbr))
            while (++i < putspace)
                nb_char = char_treat(' ', nb_char);
    }
	return (nb_char);
}

int         o_treat_9(t_flag flag, long long dig, char *nbr, int nb_char)
{
    if (flag.width > 0 && dig == 0 && flag.point && !flag.precision)
        return(ft_strlen(nbr) + nb_char);
    else if (flag.precision > 0 && dig == 0 && flag.point && !flag.width)
        return(ft_strlen(nbr) + nb_char);
    else if (dig == 0 && flag.point && !flag.precision && !flag.width)
        return (0);
    else if (dig == 0 && !flag.precision && !flag.point)
        return (ft_strlen(nbr) + nb_char);
    else if (flag.minus > 0 && flag.precision <= 1 && (!(dig == 0)))
        return (ft_strlen(nbr) + nb_char);
    else
		ft_putstr(nbr);
	return (nb_char);
}

int        o_treat_10(t_flag flag, long long dig, char *nbr, int nb_char)
{
    int putspace;
    int i;

    putspace = 0;
    i = -1;
    if (flag.width > 0 && flag.point > 0 && !flag.precision && flag.minus > 0)
    {
        putspace = flag.width - ft_strlen(nbr);
        if (flag.hashtag > 0)
            putspace -= 1;
        if ((size_t)flag.width > ft_strlen(nbr))
            while (++i < putspace)
                nb_char = char_treat(' ', nb_char);
    }
	return (nb_char);
}