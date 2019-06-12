/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wp_oxtreat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/12 14:13:59 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 16:08:42 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

int			wp_oxtreat(t_flag flag, long long dig)
{
    int     putspace;
    int     i;
	int		nb_char;
    char    *nbr;

    putspace = 0;
    nb_char = 0;
    i = -1;
    nbr = dectohexa(dig, flag, 0);
    nb_char = ox_treat_1(flag, dig, nbr, nb_char);
    nb_char = ox_treat_2(flag, dig, nbr, nb_char);
    nb_char = ox_treat_3(flag, dig, nbr, nb_char);
    nb_char = ox_treat_4(flag, dig, nbr, nb_char);
    nb_char = ox_treat_5(flag, dig, nbr, nb_char);
    nb_char = ox_treat_6(flag, dig, nbr, nb_char);
    nb_char = ox_treat_7(flag, dig, nbr, nb_char);
    nb_char = ox_treat_8(flag, dig, nbr, nb_char);
   /* putspace = flag.width - ft_strlen(nbr);
    if (dig == 0 && !flag.width && !flag.precision && !flag.point)
        ft_putstr(nbr);
    if (flag.hashtag > 0 && (!(dig == 0)) && (flag.precision > flag.width || 
    (flag.zero > 0 && !flag.precision && !flag.point) || (flag.width == flag.precision && flag.width != 0) ||
    (flag.zero && !flag.plus) || (flag.width > flag.precision && !flag.zero)))
    {
        if (flag.conv == 'x')
        {
            ft_putstr("0x");
            nb_char += 2;
        }
        if (flag.conv == 'X')
        {
            ft_putstr("0X");
            nb_char += 2;
        }
    }*/
    /*if (flag.minus > 0 && flag.precision < 1 && (!(dig == 0)))
        ft_putstr(nbr);
    if (dig == 0 && flag.width & flag.point)
    {
        if ((size_t)flag.width > 0)
        {
            while (++i < (size_t)flag.width)
            {
                ft_putchar(' ');
                nb_char++;
            }
        }
    }*/
    /*if (flag.width > 0 && !flag.point)
    {
        if (flag.hashtag > 0)
            putspace -= 2;
        if ((size_t)flag.width > ft_strlen(nbr) && flag.minus)
        {
            while (++i < putspace)
            {
                ft_putchar(' ');
                nb_char++;
            }
        }
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
        }
    }*/
    /*if (flag.width > 0 && flag.point > 0 && !flag.precision)
    {
        if (flag.hashtag > 0)
            putspace -= 2;
        if (dig == 0)
            putspace = flag.width;
        if ((size_t)flag.width > ft_strlen(nbr) && !flag.minus)
        {
            while (++i < putspace)
            {
                ft_putchar(' ');
                nb_char++;
            }        
        }
        if ((size_t)flag.width > ft_strlen(nbr) && flag.minus > 0)
        {
            while (++i < putspace)
            {
                ft_putchar(' ');
                nb_char++;
            }        
        }
    }*/
    /*if (!flag.width && flag.minus > 0 && flag.point > 0 && flag.precision > 0)
    {
        putspace = flag.precision - ft_strlen(nbr) - 1;
        if (flag.hashtag > 0)
            putspace -= 2;
        if ((size_t)flag.precision > ft_strlen(nbr))
        {
            while (++i < putspace)
            {
                ft_putchar('0');
                nb_char++;
            }
        }
    }
	if (flag.width >= 0 && flag.point && flag.precision)
	{
		putspace = flag.width - flag.precision - ft_strlen(nbr) + 1;
        if (flag.zero && flag.width > flag.precision)
            putspace = flag.width - ft_strlen(nbr);
        if (flag.hashtag > 0)
            putspace -= 2;
		if ((size_t)flag.width > ft_strlen(nbr)) // pitetre
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
    /*if (flag.hashtag > 0 && (!(dig == 0)) && ((flag.zero && flag.width && flag.plus && flag.point) ||
    (flag.width && !flag.point && !flag.precision && !flag.zero) || (!flag.zero && !flag.precision)))
    {
        if (flag.conv == 'x')
        {
            ft_putstr("0x");
            nb_char += 2;
        }
        if (flag.conv == 'X')
        {
            ft_putstr("0X");
            nb_char += 2;
        }
    }*/
    /*if (flag.space > 0)
    {
        ft_putchar(' ');
        nb_char++;
    }*/
    /*if (flag.width > 0 && !flag.point && !flag.precision && flag.minus > 0 && flag.zero > 0)
    {
        putspace = flag.width - ft_strlen(nbr);
        if (flag.hashtag > 0)
            putspace -= 2;
        if ((size_t)flag.width > ft_strlen(nbr))
        {
            while (++i < putspace)
            {
                ft_putchar(' ');
				nb_char++;
            }        
        }
    }*/
	/*if (flag.minus > 0 && flag.precision < 1 && (!(dig == 0)))
        return (ft_strlen(nbr) + nb_char);
    else if (dig == 0 && !flag.precision && !flag.point)
        return (ft_strlen(nbr) + nb_char);
	else if (dig == 0 && !flag.width && !flag.precision && flag.point)
 		return (0);
    else if (dig == 0 && flag.width && flag.point)
        return (nb_char);
    else
        ft_putstr(nbr);*/
    /*if (flag.width > 0 && flag.point > 0 && !flag.precision && flag.minus > 0)
    {
        putspace = flag.width - ft_strlen(nbr);
        if ((size_t)flag.width > ft_strlen(nbr))
        {
            while (++i < putspace)
            {
                ft_putchar(' ');
				nb_char++;
            }        
        }
    }
    if (flag.width > 0 && !flag.point && !flag.precision && flag.minus > 0)
    {
        putspace = flag.width - ft_strlen(nbr);
        if ((size_t)flag.width > ft_strlen(nbr))
        {
            while (++i < putspace)
            {
                ft_putchar(' ');
				nb_char++;
            }        
        }
    }*/
    return(ft_strlen(nbr) + nb_char);
}

int        ox_treat_1(t_flag flag, long long dig, char *nbr, int nb_char)
{
    int putspace;
    int i;

    i = -1;
    putspace = flag.width - ft_strlen(nbr);
    if (dig == 0 && !flag.width && !flag.precision && !flag.point)
        ft_putstr(nbr);
    if (flag.hashtag > 0 && (!(dig == 0)) && (flag.precision > flag.width || 
    (flag.zero > 0 && !flag.precision && !flag.point) || (flag.width == flag.precision && flag.width != 0) ||
    (flag.zero && !flag.plus && !flag.width) || (flag.width > flag.precision && !flag.zero)))
    {
        if (flag.conv == 'x')
            nb_char = multichar_treat("0x", nb_char);
        if (flag.conv == 'X')
            nb_char = multichar_treat("0X", nb_char);
    }
    if (flag.minus > 0 && flag.precision < 1 && (!(dig == 0)))
        ft_putstr(nbr);
    if (dig == 0 && flag.width & flag.point)
    {
        if ((size_t)flag.width > 0)
            while (++i < (size_t)flag.width)
                nb_char = char_treat(' ', nb_char);
    }
	return (nb_char);
}

int        ox_treat_2(t_flag flag, long long dig, char *nbr, int nb_char)
{
    int putspace;
    int i;

    putspace = flag.width - ft_strlen(nbr);
    i = -1;
    if (flag.width > 0 && !flag.point)
    {
        if (flag.hashtag > 0)
            putspace -= 2;
        if ((size_t)flag.width > ft_strlen(nbr) && flag.minus)
            while (++i < putspace)
                nb_char = char_treat(' ', nb_char);
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
    }
	return (nb_char);
}

int        ox_treat_3(t_flag flag, long long dig, char *nbr, int nb_char)
{
    int putspace;
    int i;

    i = -1;
    putspace = flag.width - ft_strlen(nbr);
    if (flag.width > 0 && flag.point > 0 && !flag.precision)
    {
        if (flag.hashtag > 0)
            putspace -= 2;
        if (dig == 0)
            putspace = flag.width;
        if ((size_t)flag.width > ft_strlen(nbr) && !flag.minus)
            while (++i < putspace)
                nb_char = char_treat(' ', nb_char);
        if ((size_t)flag.width > ft_strlen(nbr) && flag.minus > 0)
            while (++i < putspace)
                nb_char = char_treat(' ', nb_char);
    }
    return (nb_char);
}

int        ox_treat_4(t_flag flag, long long dig, char *nbr, int nb_char)
{
    int putspace;
    int i;

    putspace = 0;
    i = -1;
    if (flag.hashtag > 0 && flag.width > 0 && flag.point > 0 && !flag.precision)
    {
        if (flag.conv == 'x')
            nb_char = multichar_treat("0x", nb_char);
        if (flag.conv == 'X')
            nb_char = multichar_treat("0X", nb_char);
    }
    if (!flag.width && flag.minus > 0 && flag.point > 0 && flag.precision > 0)
    {
        putspace = flag.precision - ft_strlen(nbr) - 1;
        if (flag.hashtag > 0)
            putspace -= 2;
        if ((size_t)flag.precision > ft_strlen(nbr))
            while (++i < putspace)
                nb_char = char_treat('0', nb_char);
    }
	return (nb_char);
}

int        ox_treat_5(t_flag flag, long long dig, char *nbr, int nb_char)
{
    int putspace;
    int i;

    putspace = 0;
    i = - 1;
    if (flag.point && flag.precision)
	{
		putspace = flag.width - flag.precision - ft_strlen(nbr) + 1;
        if (flag.zero && flag.width > flag.precision)
            putspace = flag.width - ft_strlen(nbr);
        if (flag.hashtag > 0)
            putspace -= 2;
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

int            ox_treat_6(t_flag flag, long long dig, char *nbr, int nb_char)
{
    int putspace;
    int i;

    putspace = 0;
    i = -1;
    if (flag.hashtag > 0 && (!(dig == 0)) && ((flag.zero && flag.width && flag.plus && flag.point) ||
    (flag.width && !flag.point && !flag.precision && !flag.zero) || (!flag.zero && !flag.precision)))
    {
        if (flag.conv == 'x')
            nb_char = multichar_treat("0x", nb_char);
        if (flag.conv == 'X')
            nb_char = multichar_treat("0X", nb_char);
    }
    if (flag.width > 0 && !flag.point && !flag.precision && flag.minus > 0 && flag.zero > 0)
    {
        putspace = flag.width - ft_strlen(nbr);
        if (flag.hashtag > 0)
            putspace -= 2;
        if ((size_t)flag.width > ft_strlen(nbr))
            while (++i < putspace)
                nb_char = char_treat('0', nb_char);
    }
	return (nb_char);
}

int         ox_treat_7(t_flag flag, long long dig, char *nbr, int nb_char)
{
    if (dig == 0 && flag.hashtag && !flag.precision && !flag.zero)
        nbr[0] = '\0';
    if (flag.minus > 0 && flag.precision < 1 && (!(dig == 0)))
        return (nb_char);
    else if (dig == 0 && !flag.precision && !flag.point)
        return (nb_char);
	else if (dig == 0 && !flag.width && !flag.precision && flag.point)
 		return (nb_char);
    else if (dig == 0 && flag.width && flag.point)
        return (nb_char);
    else
        ft_putstr(nbr);
	return (nb_char);
}

int        ox_treat_8(t_flag flag, long long dig, char *nbr, int nb_char)
{
    int putspace;
    int i;

    i = -1;
    putspace = 0;
    if (flag.width > 0 && flag.point > 0 && !flag.precision && flag.minus > 0)
    {
        putspace = flag.width - ft_strlen(nbr);
        if ((size_t)flag.width > ft_strlen(nbr))
            while (++i < putspace)
                nb_char = char_treat(' ', nb_char);
    }
   /* if (flag.width > 0 && !flag.point && !flag.precision && flag.minus > 0)
    {
        putspace = flag.width - ft_strlen(nbr);
        if ((size_t)flag.width > ft_strlen(nbr))
            while (++i < putspace)
                nb_char = char_treat(' ', nb_char);      
    }*/
	return (nb_char);
}