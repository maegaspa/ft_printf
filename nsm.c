/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   nsm.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/13 16:07:29 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 20:00:47 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/printf.h"

int    parsing(char *str)
{
    int i;
    int type;

    i = 0;
    while (str[i])
    {
      //  if (str[0] != 34)
        //     return (0);
        while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\f' || str[i] == '\r' || str[i] == '\v' || str[i] == ',')
            i++;
        if (str[i] == '%' && str[i + 1] == 'd')
            type = 2;
        if (str[i] == '%' && str[i + 1] == 'd')
            type = 3;
        if (str[i] == '%' && str[i + 1] == '%')
        {
            ft_putstr('%');
        }
        i++;
    }
    return (0);
}

int     ft_printf(const char *format, ...)
{
    int is_valid;
    va_list ap;
    int boom;

    is_valid = parsing((char*)format);
    va_start(ap, format);
    while (*format)
    {
        boom = (vartype)va_arg(ap, vartype);
        output_type()
    }
    va_end(ap);
    return (0);
}

int type_go(char *str)
{
    void *vartype;

    if (is_valid == 2)
        vartype = (int)vartype;
    if (is_valid == 3)
        vartype = (char)vartype;
    if (is_valid == 4)
        vartype = (unsigned char)vartype;
    return (vartype);
}