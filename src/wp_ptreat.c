/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wp_ptreat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/11 17:32:14 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/11 17:35:30 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

int             wp_ptreat(void *p, t_flag flag)
{
    flag.hashtag = 1;
    flag._l = 1;
    return (wp_oxtreat(flag, (long long)p));
}