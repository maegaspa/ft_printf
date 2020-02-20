/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wp_btreat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/18 16:47:43 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/07/22 16:00:41 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

static char		*dectobin(unsigned long long n, t_flag flags, int i)
{
	char				*seg;
	int					j;
	int					tmp;

	if (n <= 4294967295)
		n = (unsigned int)n;
	if (n == 0)
		return (octa_zero(seg));
	j = ret_int(n, 2);
	if (!(seg = malloc(sizeof(char) * (j + 1))))
		return (NULL);
	seg[j] = '\0';
	while (n != 0)
	{
		tmp = n % 2;
		seg[i] = tmp + 48;
		i++;
		n = n / 2;
	}
	seg = cut_str_long(seg, flags);
	return (ft_strrev(seg));
}

static int		ft_print(t_flag flag, char *nbr, int putspace,
				unsigned long long dig)
{
	int		nb_char;

	nb_char = 0;
	while (!flag.minus && putspace--)
		nb_char += ft_putchar_add(' ');
	if (flag.conv == 'b')
		nb_char = multichar_treat("0b", nb_char);
	else if (flag.conv == 'B')
		nb_char = multichar_treat("0B", nb_char);
	if (flag.precision > ft_strlen(nbr))
	{
		ft_putncaract('0', flag.precision - ft_strlen(nbr));
		nb_char += flag.precision - ft_strlen(nbr);
	}
	else if (!flag.point && !flag.minus && flag.zero &&
			flag.width > ft_strlen(nbr) + 2)
	{
		ft_putncaract('0', flag.width - ft_strlen(nbr) - 2);
		nb_char += flag.width - ft_strlen(nbr) - 2;
	}
	if (!(!dig && flag.point && !flag.precision))
		nb_char += ft_putstr_add(nbr);
	return (nb_char);
}

int				wp_btreat(t_flag flag, unsigned long long dig)
{
	char	*nbr;
	int		nb_char;
	int		putspace;

	nb_char = 0;
	if (!(nbr = dectobin(dig, flag, 0)))
		return (0);
	putspace = (flag.width > ft_strlen(nbr) + 2) ? flag.width -
				ft_strlen(nbr) - 2 : 0;
	putspace = (flag.point && flag.precision > ft_strlen(nbr)) ? flag.width -
				flag.precision - 2 : putspace;
	if (dig == 0 && flag.width > 2 && flag.point && !flag.precision)
		putspace = flag.width - 2;
	if (!flag.point && !flag.minus && flag.zero && flag.width >
		ft_strlen(nbr) + 2)
		putspace = 0;
	if (putspace < 0)
		putspace = 0;
	nb_char += ft_print(flag, nbr, putspace, dig);
	free(nbr);
	while (flag.minus && putspace--)
		nb_char += ft_putchar_add(' ');
	return (nb_char);
}
