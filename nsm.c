/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   nsm.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/13 16:07:29 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/25 12:53:08 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/printf.h"

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
    t_flag flag;

    i = 0;
    nb_char = 0;
    k = -1;
    flag = flag_init(flag);
    wichf = ft_strnew(0);
    while (str[i])
    {
        if (str[i] != '%' && str[i - 1] != '%') // || str[i] == '%' && str[i + 1] != '%' && str[i + 2] == ' ')
        {
            ft_putchar(str[i]);
            nb_char++;
        }
        if (str[i] == '%' && (str[i + 1] != '%' && str[i + 1] != '\0' && str[i - 1] != '%'))
        {
            j = i;
            //if (str[j + 1] == '%')
            //    flag.pc_flag++;
            if (str[j + 1] == '#')
            { 
                flag.hash_flag++;
                wichf[k + 1] = str[j + 2];
                k++;
            }
            if (str[j + 1] == '0')
                flag.zero_flag++;
            if (str[j + 1] == '+')
                flag.plus_flag++;
            if (str[j + 1] == '-')
                flag.minus_flag++;
            if (str[j + 1] == '.')
                flag.point_flag++;
            if (str[j + 1] == ' ')
                flag.space_flag++;
            if (ft_isdigit(str[j + 1]))
                flag.width_flag++;
            if (str[j + 1] == 'l' && str[j + 2] == 'l')
                flag.elle_flag++;
            if (str[j + 2] == 'h' && str[j + 2] == 'h')
                flag.hihi_flag++;
        }
       if (is_option(str[i]) && str[i - 1] == '%')
        {
            wichf[k + 1] = str[i];
            k++;
        }
     //   if (is_option(str[i]) && (str[i - 1] == '%' || is_flag(flag))) //|| flag.hash_flag > 0 || flag.minus_flag > 0 ||
       //     flag.pc_flag > 0 || flag.plus_flag > 0 || flag.point_flag > 0 || flag.space_flag > 0 ||
         //   flag.width_flag > 0 || flag.zero_flag > 0))
           // wichf[k++] = str[i];
        i++;
    }
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
    resolve_option(str, ap, wichf);
    return (nb_char);
}

int         ft_printf(const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    return (parsing((char *)format, ap));
}

/*int         is_base(int nb, int base)
{

}*/

int         resolve_option(char *str, va_list ap, char *wichf)
{
    int         i;
    int         j;
    int         integer;
    const char  *acter;
    char        al;
    
    i = -1;
    j = -1;
    while (str[++i])
    {
        if (is_option(str[i]))
        {
            while (wichf[++j])
            {
                if (wichf[j] == 'd' || wichf[j] == 'i')
                {
                    integer = va_arg(ap, int);
                    printf("integer = %d\n", integer);
                    printf("Dans D\n");
                }
                if (wichf[j] == 's')
                {
                    acter = va_arg(ap, const char *);
                    printf("%s\n", acter);
                    printf("Dans S\n");
                }
                if (wichf[j] == 'c')
                {
                    al = (char) va_arg(ap, int);
                    printf("c = %c\n", al);
                    printf("Dans C\n");
                }
                if (wichf[j++] == 'x')
                    va_arg(ap, unsigned int);
                if (wichf[j++] == 'X')
                    va_arg(ap, unsigned int);
                if (wichf[j++] == 'l')
                    va_arg(ap, long int);
                if (wichf[j++] == 'L')
                    va_arg(ap, long double);
              //  if (wichf[j++] == 'h')
               //     va_arg(ap, short int);
                if (wichf[j++] == 'o')
                    va_arg(ap, unsigned int);
                if (wichf[j++] == 'u')
                    va_arg(ap, unsigned int);
                if (wichf[j++] == 'p')
                    va_arg(ap, void *);
                if (wichf[j++] == 'f')
                    va_arg(ap, double);
            }
        }
    }
    va_end(ap);
    return (0);
}