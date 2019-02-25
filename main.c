/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 13:36:54 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/25 12:52:49 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/printf.h"
#include <stdio.h>

int     main()
{
    int c;
    char *str;

    c = 420;
    str = "je suis str";
    printf("printf : %s %d\n", str, c);
    ft_printf("ft_printf : coucou les amis lol caba et jj %d \n", c);
    return (0);
}