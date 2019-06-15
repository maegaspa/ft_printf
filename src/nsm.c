/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   nsm.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/13 16:07:29 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/14 18:03:28 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

int			parse(char *str, va_list ap)
{
	t_flag		flags;
	t_compt		compt;
	int			nb_char;

	nb_char = 0;
	compt.i = -1;
	while (str[++compt.i])
	{
		if (str[compt.i] != '%')
		{
			ft_putchar(str[compt.i]);
			nb_char++;
		}
		compt.m = 0;
		if (str[compt.i] == '%' && str[compt.i + 1] == '%')
		{
			while (str[compt.i] == '%')
			{
				compt.i++;
				compt.m++;
			}
			ft_putncaract('%', (compt.m  / 2));
			nb_char += compt.m  / 2;
			compt.i--;
		}
		if (str[compt.i] == '%' && (str[compt.i + 1] != '%' && str[compt.i + 1] != '\0'))
		{
			compt.j = compt.i + 1;
			compt.k = 0;
			flags = flag_init(flags);
			compt.num2 = ft_strnew(0);
			while (!(is_conv(str[compt.j]))) // Remplissage STRUCT FLAG
			{
				if (str[compt.j] == '#' && flags.hashtag < 1)
					flags.hashtag++;
				if (str[compt.j] == '+' && flags.plus < 1)
					flags.plus++;
				if (str[compt.j] == '-' && flags.minus < 1) //&& !is_conv(str[compt.j + 1]) && !ft_isdigit(str[compt.j - 1]))
					flags.minus++;
				if (str[compt.j] == '0' && flags.zero < 1 && !is_conv(str[compt.j + 1]) && !ft_isdigit(str[compt.j - 1]))
					flags.zero++;
				if (str[compt.j] == '.' && ((ft_isdigit(str[compt.j - 1]) || ft_isdigit(str[compt.j + 1])) || str[compt.j - 1] == ' ' || str[compt.j - 1] == '#' || str[compt.j - 1] == '+' || (str[compt.j - 1] == '%' && (is_conv(str[compt.j + 1]))))) //RAJOUT
				{
					flags.point++;
					compt.k = compt.j;
				}
				if (str[compt.j] == ' ' && flags.space < 1)
					flags.space++;
				if (str[compt.j] == 'l' && flags._l < 2)
					flags._l++;
				if (str[compt.j] == 'h' && flags._h < 2)
					flags._h++;
				if (str[compt.j] == 'L' && flags._L < 1)
					flags._L++;
				//printf("\n%c\n", str[compt.j]);
				compt.j++;
			}
			flags.conv = str[compt.j];
			if (!(compt.num = ft_strsub(str, compt.i, (compt.j - compt.i + 1))))
				return (0);
			if (flags.point)
				if (!(compt.num2 = ft_strsub(str, compt.k + 1, (compt.j - compt.k))))
					return (0);
			flags.precision = ft_atoi_2(compt.num2); // Ajout PRECISION
			flags.width = ft_atoi_2(compt.num); // Ajout LARGEUR
			compt.i = compt.j;
			//print_help(flags, compt.i);
			nb_char = resolve_option(str, ap, flags, nb_char);
		}
		//printf("{%d}\n", nb);
	}
	va_end(ap);
	return (nb_char);
}
/*
void		ft_setflag2(char *str, t_flag *flags, t_compt *compt)
{
	if (str[compt->j] == '#' && flags->hashtag < 1)
		flags->hashtag++;
	if (str[compt->j] == '+' && flags->plus < 1)
		flags->plus++;
	if (str[compt->j] == '-' && flags->minus < 1)
		flags->minus++;
	if (str[compt->j] == '0' && flags->zero < 1 && !is_conv(str[compt->j + 1]) && !ft_isdigit(str[compt->j - 1]))
		flags->zero++;
	if (str[compt->j] == '.' && ((ft_isdigit(str[compt->j - 1]) || ft_isdigit(str[compt->j + 1])) ||
		str[compt->j - 1] == ' ' || str[compt->j - 1] == '#' || str[compt->j - 1] == '+' ||
		(str[compt->j - 1] == '%' && is_conv(str[compt->j + 1]))))
	{
		flags->point++;
		compt->k = compt->j;
	}
	if (str[compt->j] == ' ' && flags->space < 1)
		flags->space++;
	if (str[compt->j] == 'l' && flags->_l < 2)
		flags->_l++;
	if (str[compt->j] == 'h' && flags->_h < 2)
		flags->_h++;
	if (str[compt->j] == 'L' && flags->_L < 1)
		flags->_L++;
}

int			ft_setflag(char *str, t_flag *flags, t_compt *compt)
{
	compt->j = compt->i;
	compt->k = 0;
	compt->num2 = ft_strnew(0);
	while (!(is_conv(str[compt->j++]))) // Remplissage STRUCT FLAG
		ft_setflag2(str, &flags, &compt);
	flags->conv = str[compt->j - 1];
	if (!(compt->num = ft_strsub(str, compt->i, (compt->j - compt->i))))
		return (0);
	if (flags->point)
		if (!(compt->num2 = ft_strsub(str, compt->k + 1, (compt->j - compt->k - 1))))
			return (0);
	flags->precision = ft_atoi_2(compt->num2); // Ajout PRECISION
	flags->width = ft_atoi_2(compt->num); // Ajout LARGEUR
	compt->i = compt->j - 1;
	return (1);
}

int			ft_normaltext(char *str, t_compt *compt)
{
	int		nb_char;

	nb_char = 0;
	if (str[compt->i] != '%')
		nb_char += ft_putchar_add(str[compt->i]);
	compt->m = 0;
	if (str[compt->i] == '%' && str[compt->i + 1] == '%')
	{
		while (str[compt->i] == '%')
		{
			compt->i++;
			compt->m++;
		}
		ft_putncaract('%', (compt->m  / 2));
		nb_char += compt->m  / 2;
		compt->i--;
	}
	return (nb_char);
}

int			parse(char *str, va_list ap)
{
	t_flag		flags;
	t_compt		compt;
	int			nb_char;

	nb_char = 0;
	compt.i = -1;
	while (str[++compt.i])
	{
		nb_char += ft_normaltext(str, &compt);
		if (str[compt.i] == '%' && (str[compt.i + 1] != '%' && str[compt.i + 1] != '\0'))
		{
			flags = flag_init(flags);
			if (!(ft_setflag(str, &flags, &compt)))
				return (0);
			nb_char = resolve_option(str, ap, flags, nb_char);
		}
	}
	va_end(ap);
	return (nb_char);
}*/

int			ft_printf(const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    return (parse((char *)format, ap));
}

void		ft_putncaract(char c, int size)
{
	int		i;

	i = -1;
	while (++i != size)
		ft_putchar(c);
}

void		ft_putnstr(char const *s, int size)
{
	if (s != 0)
		write(1, s, size);
}

int         resolve_option(char *str, va_list ap, t_flag flag, int nb_char)
{
    int         i;
    char        *nbr;
    t_out       out;

    i = -1;
    out = out_init(); //INUTIL POUR LE MOMENT
    if (flag.conv == 'd' || flag.conv == 'i' || flag.conv == 'u')
        nb_char = choose_dig(flag, nb_char, ap, out);
    if (flag.conv == 's')
		nb_char += wp_streat(flag, ap);
	if (flag.conv == 'c' || flag.conv == '%')
        nb_char += wp_ctreat(flag, ap);
	/*if (flag.conv == 'f')
	{
		if (flag._L)
			out.doub = va_arg(ap, long double);
		else
			out.doub = va_arg(ap, double);
		nb_char += wp_ftreat(flag, out.doub);
	}*/
	if (flag.conv == 'x' || flag.conv == 'X' || flag.conv == 'o' || flag.conv == 'p')
		nb_char = choose_xo(flag, ap, nb_char, out);
    va_end(ap);
    return (nb_char);
}

int        choose_dig(t_flag flag, int nb_char, va_list ap, t_out out)
{
    if (flag._l && flag.conv == 'u')
	{
		out.yessai = va_arg(ap, unsigned long long);
		nb_char += wp_utreat(flag, out.yessai);
	}
	else if (flag.conv == 'u' && !flag._h && flag._l)
	{
		out.uns_integ = va_arg(ap, unsigned int);
		nb_char += wp_utreat(flag, out.uns_integ);
	}
    else if (flag.conv == 'u' && flag._h)
    {
        out.sh_int = va_arg(ap, unsigned short);
        nb_char += wp_utreat(flag, out.sh_int);
    }
	else if (flag._l && (flag.conv == 'd' || flag.conv == 'i'))
	{
		out.ld = va_arg(ap, long long);
		nb_char += wp_dtreat(flag, out.ld);
	}
	else if (flag.conv == 'u' && !flag._h && !flag._l)
	{
		out.uns_integ = va_arg(ap, unsigned int);
		nb_char += wp_utreat(flag, out.uns_integ);
	}
	else
	{
		out.integ = va_arg(ap, int);
		nb_char += wp_dtreat(flag, out.integ);
	}
	return (nb_char);
}

int		choose_xo(t_flag flag, va_list ap, int nb_char, t_out out)
{
    char    *nbr;

	if (flag.conv == 'x' || flag.conv == 'X')
	{
		out.yessai = va_arg(ap, unsigned long long);
		nb_char += wp_oxtreat(flag, out.yessai);
	}
	if (flag.conv == 'p')
	{
		out.void_pointer = va_arg(ap, void*);
		nb_char += wp_oxtreat(flag, (unsigned long long)out.void_pointer);
	}
	if (flag.conv == 'o')
	{
		out.o = va_arg(ap, unsigned long);
		nb_char += wp_otreat(flag, out.o);
	}
	return (nb_char);
}

char	*nbr_dig(long long dig, t_flag flag, char *str)
{
	if (flag.conv == 'u')
	{
		if (flag._l)
			str = ft_ulltoa(dig);
		else if (flag._h == 1)
			str = ft_uhtoa(dig);
		else if (flag._h == 2)
			str = ft_hhtoa(dig);
		else
			str = ft_utoa(dig);
	}
	if (flag.conv == 'i' || flag.conv == 'd')
	{
		if (flag._l)
			str = ft_lltoa(dig);
		else if (flag._h == 1)
			str = ft_htoa(dig);
		else if (flag._h == 2)
			str = ft_hhtoa(dig);
		else
			str = ft_itoa(dig);
	}
	return (str);
}

char	                *dectohexa(unsigned long long n, t_flag flags, int i)
{
	char				*seg;
	int					j;
	int					tmp;

	if (n >= 429496729 && n <= 4563402751 && !flags._l)
		n = n - 4294967296;
	if (n == 0)
		return (octa_zero(seg));
	j = ret_int(n, 16);
	if (!(seg = malloc(sizeof(char) * j + 1)))
		return (NULL);
	seg[j] = '\0';
	while (n != 0)
	{
		tmp = n % 16;
		if (tmp < 10)
			seg[i] = tmp + 48;
		else if (flags.conv == 'x' || flags.conv == 'p')
			seg[i] = tmp + 87;
		else if (flags.conv == 'X')
			seg[i] = tmp + 55;
		i++;
		n = n / 16;
	}
	seg = cut_str_long(seg, flags);
	return (ft_strrev(seg));
}

char	                *dectoocta(unsigned long n, t_flag flags)
{
	char			    *seg;
	int				    i;
	int				    j;
	unsigned long	    tmp;

	if (flags._h)
		n = (unsigned short)n;
    if (flags._h == 2)
        n = (unsigned char)n;
	i = 0;
	if (n == 0)
		return (octa_zero(seg));
	j = ret_int(n, 8);
	if (!(seg = malloc(sizeof(char) * j + 1)))
		return (NULL);
	seg[j + 1] = '\0';
	while (n != 0)
	{
		seg[i] = 48 + (n % 8);
		n = n / 8;
		i++;
	}
	return (ft_strrev(seg));
}