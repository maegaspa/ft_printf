/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   nsm.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/13 16:07:29 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 17:05:51 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/printf.h"
#include <stdlib.h>

void         print_help(t_flag flag, int nb_char)
{
    printf("hash : %d\n", flag.hash_flag);
    printf("pc   : %d\n", flag.pc_flag);
    printf("zero : %d\n", flag.zero_flag);
    printf("minus: %d\n", flag.minus_flag);
    printf("plus : %d\n", flag.plus_flag);
    printf("point: %d\n", flag.point_flag);
    printf("space: %d\n", flag.space_flag);
    printf("width: %d\n", flag.width_flag);
    printf("elle : %d\n", flag.elle_flag);
    printf("hihi : %d\n", flag.hihi_flag);
    printf("nb_char: %d\n", nb_char);
}

int         is_option(char p)
{
    if (p == 's' || p == 'd' || p == 'i' || p == 'o' || p == 'u' || p == 'x' || p == 'X'
        || p == 'c' || p == 'p' || p == 'l' || p == 'L' || p == 'f' || p == 'h')
        return (1);
    return (0);
}

t_flag      flag_init(t_flag flag)
{
    flag.pc_flag = 0;
    flag.hash_flag = 0;
    flag.zero_flag = 0;
    flag.plus_flag = 0;
    flag.minus_flag = 0;
    flag.point_flag = 0;
    flag.space_flag = 0;
    flag.width_flag = 0;
    flag.elle_flag = 0;
    flag.hihi_flag = 0;
    return (flag);
}

t_out       out_init(t_out out)
{
    out.acter = 0;
    out.aif = 0;
    out.elle = 0;
    out.elled = 0;
    out.hihi = 0;
    out.integ = 0;
    out.ix = 0;
    out.pai = 0;
    return (out);
}

int         is_flag(t_flag flag)
{
     if (flag.hash_flag > 0 || flag.minus_flag > 0 || flag.pc_flag > 0
        || flag.zero_flag > 0 || flag.point_flag > 0 || flag.space_flag > 0
        || flag.width_flag > 0 || flag.plus_flag > 0)
        return (1);
    return (0);
}

int         parsing(char *str, va_list ap)
{
    int     i;
    int     j;
    int     k;
    int     nb_char;
    char    *wichf;
    t_flag  flag;
    int    *audd;

    i = -1;
    k = -1;
    nb_char = 0;
    //j = 0;
    flag = flag_init(flag);
    if (!(wichf = ft_strnew(0)))
        return (0);
    while (str[++i])
    {
		k = 0;
        if (str[i] != '%' && str[i - 1] != '%')
        {
                ft_putchar(str[i]);
                nb_char++;
        }
		if (str[i] == '%' && str[i + 1] == '%')
		{
			while (str[i] == '%')
			{
				i++;
				k++;
			}
			ft_putncaract('%', (k  / 2));
			nb_char += k / 2;
			i--;
        }
        if (str[i] == '%' && (str[i + 1] != '%' && str[i + 1] != '\0' && str[i - 1] != '%'))
        {
            j = i;
            while (!(is_option(str[j++])))
            { 
                if (str[j] == '#')
                { 
                    flag.hash_flag++;
                    wichf[k + 1] = str[j + 2];
                    k++;
                }
                if ((str[j - 1] == '%' || str[j - 1] == '#' ) && str[j] == '0')
                    flag.zero_flag++;
                if (str[j] == '+')
                    flag.plus_flag++;
                if (str[j] == '-')
                    flag.minus_flag++;
                if (str[j] == '.')
                    flag.point_flag++;
                if (str[j] == ' ')
                    flag.space_flag++;
                if ((str[j - 1] == '%' || str[j - 1] == '#') && ft_isdigit(str[j]))         /////PARSING A REVOIR POUR flag.width = atoi du bail; +++ZERO
                    flag.width_flag++;
                if (str[j + 1] == 'l' && str[j + 2] == 'l')
                    flag.elle_flag++;
                if (str[j + 2] == 'h' && str[j + 2] == 'h')
                    flag.hihi_flag++;
            }
        }
       // num = ft_strsub(str, i, (j - i))	
		//if (flags.point_flag)
		//	num2 = ft_strsub(str, k + 1, (j - k - 1))
        //printf("wichf = %s\n", wichf);
        wichf = ft_wichf(wichf, str, i, flag);
        //printf("wichf = %s\n", wichf);
        //segfault quand resolve est ici
        //printf("str = %c\n", str[i]);
        nb_char += resolve_option(str, ap, wichf, flag, nb_char); //POSITION DE CETTE FONCTION A REVOIR, GERER PLSRS OPTIONS EM MM TPS
    }
    print_help(flag, nb_char);
    return (nb_char);
}

int         ft_printf(const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    return (parsing((char *)format, ap));
}

void	    ft_putncaract(char c, int size)
{
	int		i;

	i = -1;
	while (++i != size)
		ft_putchar(c);
}


char        *ft_wichf(char *wichf, char *str, int i, t_flag flag)
{
    int     k;
    //char    *audd;

    //audd = flag_boi(flag, str);
   
    k = 0;
    //if (is_option(str[i]) && (str[i + 1] == audd))
    //if (is_option(str[i]) && (str[i - 1] == '%' || (ft_isdigit(str[i - 1] || str []))
    /*if (is_option(str[i]) && (str[i - 1] == '%' || ft_isdigit(str[i - 1])||
        str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == ' ')) // RAJOUTER OPTIONS, VRAIMENT
    
    {
        wichf[k + 1] = str[i];
        k++;
    }*/
    while(str[++i])
    {
        if (str[i] == '%')
            k = i;
        if (is_option(str[i]))
        {
            while (k < i)
            {
                if (ft_isdigit(str[k]))
                    wichf[k] = str[i];
                k++;
            }
        }
    }
    wichf[k + 1] = '\0';
    //printf("wichf = %s\n", wichf);
    return (wichf);
}

int         resolve_option(char *str, va_list ap, char *wichf, t_flag flag, int nb_char)
{
    int         i;
    int         j;
    char        *nbr;
    t_out       out;
    
    i = -1;
    j = -1;
    out = out_init(out);
    out.precis = ft_atoi(flag_boi(flag, str));
    //printf("precis = %d\n", out.precis);
    //flag.width_flag = out.precis;
    //printf("atoi = %d\n", out.precis);
    //  printf("wichf = %s\n", wichf);
    //str = ft_strnew(0);
    while (str[++i])
    {
        //printf("str[i] = %c\n", str[i]);
        if (is_option(str[i]))
        {
            while (wichf[++j])
            {
                //printf("wichf[j] = %c\n", wichf[j]);
                if (wichf[j] == 'd' || wichf[j] == 'i')
                {
                    out.integ = va_arg(ap, int);
                    nb_char += wp_dtreat(flag, out.precis, str, out.integ);
                }
                if (wichf[j] == 's')
                {
                    out.acter = va_arg(ap, char *);
                    nb_char += wp_streat(flag, out.precis, out.acter);
                }
                if (wichf[j] == 'c')
                {
                    out.al = va_arg(ap, int);
                    nb_char += wp_ctreat(flag, out.precis, out.al);
                }
                if (wichf[j] == 'x')
                {
                    out.ix = va_arg(ap, unsigned int);
                    nbr = ft_itoa_base(out.ix, 16);
                    nb_char += wp_oxtreat(flag, out.precis, nbr, wichf);
                }
                if (wichf[j] == 'X')
                {
                    out.ix = va_arg(ap, unsigned int);
                    nbr = ft_itoa_base(out.ix, 16);
                    nbr = ft_strcaps(nbr);
                    ft_putstr(nbr);
                }
                if (wichf[j] == 'l')
                    va_arg(ap, long int);
                if (wichf[j] == 'L')
                    va_arg(ap, long double);
              //  if (wichf[j] == 'h')
               //     va_arg(ap, short int);
                if (wichf[j] == 'o')
                {
                    out.ix = va_arg(ap, unsigned int);
                    nbr = ft_itoa_base(out.ix, 8);
                    nb_char += wp_oxtreat(flag, out.precis, nbr, wichf);
                }
                if (wichf[j] == 'p')
                    va_arg(ap, void *);

                if (wichf[j] == 'f')
                    va_arg(ap, double);
            }
        }
    }
    va_end(ap);
    return (nb_char);
}

char                    *flag_boi(t_flag flag, const char *str)
{
    int     i;
    int     j;
    int     k;
    char    *tmp;

    i = -1;
    j = 0;
    //k = 0;
    if (!(tmp = ft_strnew(0)))
        return (NULL);
    if (flag.point_flag > 0 || flag.width_flag > 0)
    {
        while(str[++i])
        {
            if (str[i] == '%')
                k = i + 1;
            if (is_option(str[i]))
            {
                while (k < i)
                {
                    tmp[j] = str[k];
                    k++;
                    j++;
                }
            }
        }
        /*while (str[++i])
        {
            if (ft_isdigit(str[i]) && (str[i - 1] == '%' || str[i - 2] == '%'))       // SI PLUSIEURS DIGITS DANS le printf trouver une condition
            {
               tmp[j] = str[i];
               j++;
            }
        }*/
    }
    tmp[j] = '\0';
    return (tmp);
}

int                    wp_ctreat(t_flag flag, int size, int c)
{
    int putspace;
    int i;

    i = 0;
    putspace = size - 1;
   if (flag.width_flag > 0 && flag.point_flag == 0)
    {
        if (size > 1)
        {
            while (++i < putspace)
            {
                if (flag.zero_flag > 0)
                    ft_putchar('0');
                else
                    ft_putchar(' ');
            }
        }
    }
    ft_putchar(c);
    return (0); // return nb_char
}

int                    wp_streat(t_flag flag, int size, char *pute)
{
    int     putspace;
    int     i;
    int     nb_char;

    putspace = 0;
    nb_char = 0;
    i = -1;
    if (size < 0)
        size = 0;
    putspace = size - ft_strlen(pute);
    if (flag.point_flag > 0)
    {
        if (flag.zero_flag > 0)
        {
            while (++i < size)
            {
                ft_putchar('0');
                nb_char++;
            } 
        }
        if (size < ft_strlen(pute))
        {
            while (++i < size)
                ft_putchar(pute[i]);
            pute[i] = '\0';
        }
    }
    if (flag.width_flag > 0 && flag.point_flag == 0)
    {
        if (size > ft_strlen(pute))
        {
            while (++i < putspace)
            {
                if (flag.zero_flag > 0)
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
    }
    ft_putstr(pute);
    nb_char = ft_strlen(pute);
    return (nb_char);
}

int                    wp_dtreat(t_flag flag, int size, const char *str, int nb)
{
    int     putspace;
    int     i;
    int     j;
    char    *len;

    putspace = 0;
    i = -1;
    j = 0;
    len = ft_itoa(nb);
    if (size < 0)
        size = 0;
    putspace = size - ft_strlen(len);
    if (flag.width_flag > 0)
    {
        if (size > ft_strlen(len))
        {
            while (++i < putspace)
            {
                if (flag.zero_flag > 0)
                    ft_putchar('0');
                else
                    ft_putchar(' ');
            }
        }
    }
    if (flag.point_flag > 0)
    {
        if (size > ft_strlen(len))
        {
            while (++i < putspace)
                ft_putchar('0');
        }
    }
    if (flag.plus_flag > 0)
        ft_putchar('+');
    if (flag.space_flag > 0)
        ft_putchar(' ');
    ft_putnbr(nb);
    return(ft_strlen(len));
}

int         wp_oxtreat(t_flag flag, int size, char const *str, char *wichf)
{
    int     putspace;
    int     i;
    int     j;

    putspace = 0;
    i = -1;
    j = 0;
    if (size < 0)
        size = 0;
    putspace = size - ft_strlen(str);
    if (flag.hash_flag > 0 && flag.zero_flag > 0)
    {
        if (wichf[j++] == 'o')
            ft_putchar('0');
        if (wichf[j++] == 'x')
            ft_putstr("0x");
        if (wichf[j++] == 'X')
            ft_putstr("0X");
    }
    if (flag.width_flag > 0)
    {
        if (size > ft_strlen(str))
        {
            while (++i < putspace)
            {
                if (flag.point_flag > 0 || flag.zero_flag > 0)
                    ft_putchar('0');
                else
                    ft_putchar(' ');
            }        
        }
    }
    if (flag.hash_flag > 0)
    {
        if (wichf[j++] == 'o')
            ft_putchar('0');
        if (wichf[j++] == 'x')
            ft_putstr("0x");
        if (wichf[j++] == 'X')
            ft_putstr("0X");
    }
    ft_putstr(str);
    return(ft_strlen(str));
}