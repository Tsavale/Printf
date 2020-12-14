
#include "ft_printf.h"

void	conv_type_n(t_info *info, va_list va)
{
	int *p;

	p = va_arg(va, int*);
	*p = info->ret;
}
