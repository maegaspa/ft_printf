/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 13:23:57 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/29 16:59:04 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct              s_flag
{
    unsigned int            pc_flag;
    unsigned int            hash_flag;
    unsigned int            zero_flag;
    unsigned int            plus_flag;
    unsigned int            minus_flag;
    unsigned int            point_flag;
    unsigned int            space_flag;
    unsigned int            width_flag;
    unsigned int            elle_flag;
    unsigned int            hihi_flag;
    unsigned int            precision;
}                           t_flag;
typedef struct              s_out
{
    int                     integ;
    char                    *acter;
    unsigned char           al;
    unsigned int            ix;
    long                    elle;
    long double             elled;
    short int               hihi;
    void                    *pai;
    double                  aif;
    int                     precis;
}                           t_out;
typedef struct              s_count
{
    int                     i;
    int                     j;
}                           t_count;
int                         ft_printf(const char *format, ...);
int                         parsing(char *str, va_list ap);
int                         resolve_option(char *str, va_list ap, char wichf, t_flag flag, int nb_char);
unsigned int                x_treat(unsigned int out, t_flag flag, char *str);
char                        s_treat(const char *out, t_flag flag, char *str);
char                        *flag_boi(t_flag flag, char *str);
int                         wp_streat(t_flag flag, int size, char *pute);
int                         wp_dtreat(t_flag flag, char *str, t_out out);
void                        print_help(t_flag flag, int nb_char);
char                        *ft_itoa_base(int value, int base);
int		                    ft_atoibis(char *s);
char                        *ft_strcaps(char *str);
int                         wp_ctreat(t_flag flag, int size, int c);
int                         wp_oxtreat(t_flag flag, int size, char *str, char wichf);
//char                        *ft_wichf(char wichf, char *str, int i, t_flag flag);
void	                    ft_putncaract(char c, int size);
int		                    ft_atoi_2(char const *str);
void	                    ft_putnstr(char const *s, int size);
//int                         ft_printf(const char *format,
//        ...) __attribute__((format(printf,1,2)));
#endif