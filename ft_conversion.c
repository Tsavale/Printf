#include "ft_printf.h"

void		ft_conversion(va_list *ap, char c, t_fl *fl)
{
	fl->cv = c;
	if (c == 'c')
		return ;
	else if (c == 's')
		fl->str = ft_strdup(va_arg(*ap, char*));
	else if (c == 'd' || c == 'i')
		fl->str = ft_itoa(va_arg(*ap, int));
	else if (c == 'u')
		fl->str = ft_utoa_base(va_arg(*ap, unsigned int), BASE_TEN);
	else if (c == 'x')
		fl->str = ft_utoa_base(va_arg(*ap, unsigned int), X_MIN_BASE);
	else if (c == 'X')
		fl->str = ft_utoa_base(va_arg(*ap, unsigned int), X_MAJ_BASE);
	else if (c == '%')
		fl->str = ft_strdup("%");
	else if (c == 'p')
		fl->str = ft_utoa_base(va_arg(*ap, unsigned long), X_MIN_BASE);
	ft_flag_applier(fl);
}
