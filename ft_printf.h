#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# define X_MAJ_BASE "0123456789ABCDEF"
# define X_MIN_BASE "0123456789abcdef"
# define BASE_TEN "0123456789"

typedef struct	s_fl
{
	char	*str;
	char	cv;
	int		p;
	int		fw;
	int		zeros;
}				t_fl;

int				ft_printf(const char *s, ...);
int				ft_format(const char *s, va_list *ap, t_fl *fl);
int				ft_process(va_list *ap, char *s, t_fl *fl);
int				ft_write(va_list *ap, t_fl *fl);
void			ft_start_fl(t_fl *);
int				ft_flag_inf(char *s, t_fl *fl);
int				ft_fw_inf(va_list *ap, char *s, t_fl *fl);
int				ft_precision_inf(va_list *ap, char *s, t_fl *fl);
void			ft_conversion(va_list *ap, char c, t_fl *fl);
void			ft_flag_applier(t_fl *fl);
void			ft_special_cases(t_fl *fl);
void			ft_point_flag_str(t_fl *fl);
void			ft_point_flag_nbr(t_fl *fl);
void			ft_space_flags(t_fl *fl);
int				ft_isin(int n, char *s);
int				ft_isaconversion(int n);
int				ft_isflag(int n);

#endif
