/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoibis.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 22:11:01 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/14 23:33:42 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/printf.h"

int		ft_atoi(char *s)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\v'
			|| s[i] == '\f' || s[i] == '\r' || ft_isalpha(s[i])
			|| s[i] == '%' || s[i] == '0' || s[i] == '+' || s[i] == '-'
			|| s[i] == '#' || s[i] == 'l' || s[i] == 'h' || s[i] == 'L')
		i++;
	if (s[i] == '+')
		i++;
	while (s[i] >= 48 && s[i] <= 57)
	{
		num = (num * 10) + s[i] - 48;
		i++;
	}
	return (num);
}