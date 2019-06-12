/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wp_streat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 17:20:00 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 20:13:42 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/printf.h"

static int	ft_printnull(t_flag flag, char *string)
{
	if (string)// || !flag.point || !flag.precision)
		return (0);
	//write(1, "(null)", flag.precision): affiche un cara imaginaire lors du depassement
	if (!flag.precision)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putchar('(');
	if (flag.precision >= 2)
		ft_putchar('n');
	if (flag.precision >= 3)
		ft_putchar('u');
	if (flag.precision >= 4)
		ft_putchar('l');
	if (flag.precision >= 5)
		ft_putchar('l');
	if (flag.precision >= 6)
		ft_putchar(')');
	return ((flag.precision <= 6) ? flag.precision : 6);
}

int			wp_streat(t_flag flag, va_list ap) //traiter une option s
{
    int		putspace;
    size_t	i;
    int		nb_char;
	char	*string;

	string = va_arg(ap, char*);
    nb_char = 0;
    i = 0;
	putspace = (string) ? flag.width - ft_strlen(string) : flag.width;
    putspace = (string && flag.point && flag.precision < ft_strlen(string)) ? flag.width - flag.precision : putspace;
	putspace = (!string && !flag.point && flag.width) ? flag.width - 6 : putspace;
	putspace = (!string && flag.precision && flag.width) ? flag.width - flag.precision : putspace;
	if (!flag.point && flag.width <= ft_strlen(string))
		putspace = 0;
	// GERER AJOUT DEVANT STRING
	if (flag.point && !flag.precision && flag.width > 0 && !flag.minus)
	{
		while (i < flag.width)
		{
			if (flag.zero)
			{
				ft_putchar('0');
				nb_char++;
	        }
			else
            {
                ft_putchar(' ');
                nb_char++;
            }
			i++;
        }
    }
    if (flag.width && !flag.minus)
    {
        if (!string || (putspace > 0))
        {
            while (i < putspace)
            {
                if (flag.zero > 0)
                {
                    ft_putchar('0');
                    nb_char++;
                }
                else
                {
                    ft_putchar(' ');
                    nb_char++;
                }
				i++;
            }
        }
    }
	// IMPRIME LA STRING
	if (flag.point && flag.precision > 0)
	{
		i = 0;
		while (string && i < ft_strlen(string) && i < flag.precision)
			ft_putchar(string[i++]);
		nb_char += i;
	}
	if ((flag.point && flag.precision > 0) || (!flag.point && !flag.precision))
		nb_char += ft_printnull(flag, string);
	if (!flag.point)
	{	
		ft_putstr(string);
		nb_char += ft_strlen(string);
	}
	// GERE LE MOINS
	if (flag.width > 0 && flag.minus)
    {
		i = 0;
        if (!string || (!flag.precision && (size_t)flag.width > ft_strlen(string)))
        {
            while (i < putspace)
			{
                nb_char += ft_putchar_add(' ');
				i++;
            }
        }
		if (string && flag.point)
		{
			while (nb_char < flag.width)
			{
				ft_putchar(' ');
                nb_char++;
			}
		}
    }
    return (nb_char);
}