#include "ft_printf.h"

void	special_case_with_zero(t_info *info, unsigned long long value)
{
	if (!value && (info->flags & FLAGS_PRECISION) && !info->precision)
	{
		if (info->lenght && !info->width)
		{
			info->buf[--info->lenght] = '\0';
		}
		else if (info->lenght && info->width)
		{
			info->buf[info->lenght - 1] = ' ';
		}
	}
}
