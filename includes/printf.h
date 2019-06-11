/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 13:23:57 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/03 16:09:54 by maegaspa    ###    #+. /#+    ###.fr     */
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

typedef	struct				s_float
{
	char					*digit;
	char					*temp;
	int						preci;
	int						i;
	long					enti;
}							t_float;

typedef struct              s_flag
{
    unsigned int            hashtag;
    unsigned int            zero;
    unsigned int            plus;
    unsigned int            minus;
    unsigned int            point;
    unsigned int            space;
    unsigned int            width;
    unsigned int            _l;
    unsigned int            _h;
    unsigned int            _L;
	unsigned int			precision;
	char					conv;
}                           t_flag;

typedef struct              s_out
{
    int                     integ;
    unsigned long long      yessai;
    char                    *string;
    unsigned char           uns_char;
    unsigned int            uns_integ;
    long                    lo;
    long double             lo_double;
    unsigned short          sh_int;
    int                   *void_pointer;
    double                  doub;
    int                     precis;
    long long               ld;
    unsigned long           o;
}                           t_out;

typedef struct				s_compt
{
	int		i;
	int		j;
	int		k;
	int		m;
	char	*num;
	char	*num2;
}							t_compt;

typedef struct              s_count
{
    int                     i;
    int                     j;
}                           t_count;

int							parse(char *str, va_list ap);
int                         ft_printf(const char *format, ...);
//int                       parsing(char *str, va_list ap);
int                         resolve_option(char *str, va_list ap, t_flag flag, int nb_char);
unsigned int                x_treat(unsigned int out, t_flag flag, char *str);
char                        s_treat(const char *out, t_flag flag, char *str);
char                        *flag_boi(t_flag flag, char *str);
int                         wp_streat(t_flag flag, va_list string);
int                         wp_dtreat(t_flag flag, long long dig);
void						print_help(t_flag flag, int nb_char);
char                        *ft_itoa_base(int value, int base);
int		                    ft_atoibis(char *s);
char                        *ft_strcaps(char *str);
int                         wp_ctreat(t_flag flag, va_list ap);
int                         wp_oxtreat(t_flag flag, long long dig);
//char                        *ft_wichf(char wichf, char *str, int i, t_flag flag);
void	                    ft_putncaract(char c, int size);
int		                    ft_atoi_2(char const *str);
void	                    ft_putnstr(char const *s, int size);
int			                wp_otreat(t_flag flag, long long dig);
int                         wp_utreat(t_flag flag, long long dig);
int                         choose_dig(t_flag flag, int nb_char, va_list ap, t_out out);
int		                    choose_xo(t_flag flag, va_list ap, int nb_char, t_out out);
char	                    *nbr_dig(long long dig, t_flag flag, char *str);
char                        *nbr_digox(long long dig, t_flag flag, char *str);
char                        *ft_uhhtoa_base(unsigned short value, int base);
char                        *ft_ulltoa_base(unsigned long long value, int base);
char                        *ft_utoa_base(unsigned int value, int base);
char	                    *dectohexa(unsigned long long n, t_flag flags, int i);
char	                    *octa_zero(char *seg);
int		                    ret_int(unsigned long long n, int base);
char	                    *cut_str_long(char *seg, t_flag flags);
char	                    *dectoocta(unsigned long n, t_flag flags);
int                         char_treat(char c, int nb_char);
int				            ft_putchar_add(char c);
int                         multichar_treat(char *c, int nb_char);
int							wp_ftreat(t_flag flag, double nb);
double long					ft_pow10(double long f, int exp);
int							d_treat_1(t_flag flag, long long dig, char *len, int nb_char);
int							d_treat_2(t_flag flag, long long dig, char *len, int nb_char);
int							d_treat_3(t_flag flag, long long dig, char *len, int nb_char);
int							d_treat_4(t_flag flag, long long dig, char *len, int nb_char);
int							d_treat_5(t_flag flag, long long dig, char *len, int nb_char);
int							d_treat_6(t_flag flag, long long dig, char *len, int nb_char);
int							d_treat_7(t_flag flag, long long dig, char *len, int nb_char);
int                       	o_treat_1(t_flag flag, long long dig, char *nbr, int nb_char);
int                       	o_treat_2(t_flag flag, long long dig, char *nbr, int nb_char);
int                       	o_treat_3(t_flag flag, long long dig, char *nbr, int nb_char);
int                       	o_treat_4(t_flag flag, long long dig, char *nbr, int nb_char);
int                       	o_treat_5(t_flag flag, long long dig, char *nbr, int nb_char);
int                       	o_treat_6(t_flag flag, long long dig, char *nbr, int nb_char);
int                      	o_treat_7(t_flag flag, long long dig, char *nbr, int nb_char);
int                       	o_treat_8(t_flag flag, long long dig, char *nbr, int nb_char);
int                         o_treat_9(t_flag flag, long long dig, char *nbr, int nb_char);
int                       	o_treat_10(t_flag flag, long long dig, char *nbr, int nb_char);
int                       	ox_treat_1(t_flag flag, long long dig, char *nbr, int nb_char);
int                       	ox_treat_2(t_flag flag, long long dig, char *nbr, int nb_char);
int                       	ox_treat_3(t_flag flag, long long dig, char *nbr, int nb_char);
int                       	ox_treat_4(t_flag flag, long long dig, char *nbr, int nb_char);
int                       	ox_treat_5(t_flag flag, long long dig, char *nbr, int nb_char);
int                       	ox_treat_6(t_flag flag, long long dig, char *nbr, int nb_char);
int                         ox_treat_7(t_flag flag, long long dig, char *nbr, int nb_char);
int                       	ox_treat_8(t_flag flag, long long dig, char *nbr, int nb_char);
int                       	u_treat_1(t_flag flag, long long dig, char *nbr, int nb_char);
int                       	u_treat_2(t_flag flag, long long dig, char *nbr, int nb_char);
int                       	u_treat_3(t_flag flag, long long dig, char *nbr, int nb_char);
int                       	u_treat_4(t_flag flag, long long dig, char *nbr, int nb_char);
int                       	u_treat_5(t_flag flag, long long dig, char *nbr, int nb_char);
int                         u_treat_6(t_flag flag, long long dig, char *nbr, int nb_char);
int                       	u_treat_7(t_flag flag, long long dig, char *nbr, int nb_char);
//int			                wp_ddtreat(t_flag flag, t_out out);
//int                         ft_printf(const char *format,
//        ...) __attribute__((format(printf,1,2)));
#endif