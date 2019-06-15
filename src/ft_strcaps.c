/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcaps.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 22:46:47 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/15 16:36:04 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

char		*ft_strcaps(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		while (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
			i++;
		}
		i++;
	}
	return (str);
}
