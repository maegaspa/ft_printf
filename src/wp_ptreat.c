/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wp_ptreat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/11 17:32:14 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 23:09:49 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

char			*dectohexa_p(unsigned long long n, t_flag flags, int i)
{
	char				*seg;
	int					j;
	int					tmp;

	if (n <= 4294967295)
		n = (unsigned int)n;
	if (n == 0)
		return (octa_zero(seg));
	j = ret_int(n, 16);
	if (!(seg = malloc(sizeof(char) * (j + 1))))
		return (NULL);
	seg[j] = '\0';
	while (n != 0)
	{
		tmp = n % 16;
		if (tmp < 10)
			seg[i] = tmp + 48;
		else if (flags.conv == 'p')
			seg[i] = tmp + 87;
		i++;
		n = n / 16;
	}
	seg = cut_str_long(seg, flags);
	return (ft_strrev(seg));
}
// gcc -g -fsanitize=address libft/libft.a src/ft_atoi_2.c src/ft_strcaps.c src/nsm.c src/util.c src/wp_ctreat.c src/wp_dtreat.c src/wp_otreat.c src/wp_oxtreat.c src/wp_streat.c src/wp_utreat.c src/wp_ptreat.c  main.c
int             wp_ptreat(t_flag flag, unsigned long long dig)
{
	char 	*nbr;
	int		nb_char;
	int		putspace;

	nb_char = 0;
	//BEFORE
    if (!(nbr = dectohexa_p(dig, flag, 0)))
		return (0);
	putspace = (flag.width > ft_strlen(nbr) + 2) ? flag.width - ft_strlen(nbr) - 2 : 0;
	putspace = (!dig && flag.width > ft_strlen(nbr) + 1) ? flag.width - ft_strlen(nbr) -  1 : 0;
	putspace = (flag.point && flag.precision > ft_strlen(nbr)) ? flag.width - flag.precision - 2 : putspace;
	//putspace = () // PB AVEC FLAG '0'
	//putspace = (dig == 0) ? flag.precision : putspace;
	if (putspace < 0)
		putspace = 0;
	while (!flag.minus && putspace--)
		nb_char += ft_putchar_add(' ');
	//PRINT
	nb_char = multichar_treat("0x", nb_char);
	if (flag.precision > ft_strlen(nbr))
	{	if (!dig)
			nb_char += ft_putchar_add('0');
		ft_putncaract('0', flag.precision - ft_strlen(nbr));
		nb_char += flag.precision - ft_strlen(nbr);
	}
	if (dig != 0)
		nb_char += ft_putstr_add(nbr);
	free(nbr);
	//AFTER
	while (flag.minus && putspace--)
		nb_char += ft_putchar_add(' ');
	return (nb_char);
}